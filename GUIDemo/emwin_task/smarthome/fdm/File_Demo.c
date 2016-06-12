/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::File System
 * Copyright (c) 2004-2015 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    File_Demo.c
 * Purpose: File manipulation example program
 *----------------------------------------------------------------------------*/

#include <stdio.h>                      /* Standard I/O .h-file               */
#include <ctype.h>                      /* Character functions                */
#include <string.h>                     /* String and memory functions        */

#include "cmsis_os.h"                   /* CMSIS RTOS definitions             */
#include "rl_fs.h"                      /* FileSystem definitions             */

#include "./Terminal.h"

#include "stm32f7xx_hal.h"

//extern GLCD_FONT GLCD_Font_6x8;
//extern GLCD_FONT GLCD_Font_16x24;

/* Command definitions structure. */
typedef struct scmd {
	char val[8];
	void (*func)(char *par);
} SCMD;

/* Command function prototypes */
void cmd_capture (char *par);
void cmd_type    (char *par);
void cmd_rename  (char *par);
void cmd_copy    (char *par);
void cmd_delete  (char *par);
void cmd_dir     (char *par);
void cmd_format  (char *par);
void cmd_help    (char *par);
void cmd_fill    (char *par);
void cmd_attrib  (char *par);
void cmd_cid     (char *par);

/* Local constants */
const char intro[] =
	"\n\n\n\n\n\n\n\n"
	"+-----------------------------------------------------------------------+\n"
	"|                 FileSystem File Manipulation example                  |\n";
const char help[] = 
	"+ command ------------------+ function ---------------------------------+\n"
	"| CAP \"fname\" [/A]          | captures serial data to a file            |\n"
	"|                           |  [/A option appends data to a file]       |\n"
	"| FILL \"fname\" [nnnn]       | create a file filled with text            |\n"
	"|                           |  [nnnn - number of lines, default=1000]   |\n"
	"| TYPE \"fname\"              | displays the content of a text file       |\n"
	"| REN \"fname1\" \"fname2\"     | renames a file 'fname1' to 'fname2'       |\n"
	"| COPY \"fin\" [\"fin2\"] \"fout\"| copies a file 'fin' to 'fout' file        |\n"
	"|                           |  ['fin2' option merges 'fin' and 'fin2']  |\n"
	"| DEL \"fname\"               | deletes a file                            |\n"
	"| DIR [\"mask\"]              | displays a list of files in the directory |\n"
	"| FORMAT [label [/FAT32]]   | formats the device                        |\n"
	"|                           | [/FAT32 option selects FAT32 file system] |\n"
	"| ATTRIB \"fname\" [arg]      | change file attributes                    |\n"
	"| CID                       | read CID register from the memory card    |\n"
	"| HELP  or  ?               | displays this help                        |\n"
	"+---------------------------+-------------------------------------------+\n";

const SCMD cmd[] = {
	"CAP",    cmd_capture,
	"TYPE",   cmd_type,
	"REN",    cmd_rename,
	"COPY",   cmd_copy,
	"DEL",    cmd_delete,
	"DIR",    cmd_dir,
	"FORMAT", cmd_format,
	"HELP",   cmd_help,
	"FILL",   cmd_fill,
	"ATTRIB", cmd_attrib,
	"CID",    cmd_cid,
	"?",      cmd_help };

#define CMD_COUNT   (sizeof (cmd) / sizeof (cmd[0]))

/* Local variables */
char in_line[160];

/* Local Function Prototypes */
void dot_format (uint64_t val, char *sp);
char *get_entry (char *cp, char **pNext);

#ifdef __RTX
extern uint32_t os_time;
#if 0
uint32_t HAL_GetTick(void) { 
	return os_time; 
}
#endif
#endif

/**
	* System Clock Configuration
	*   System Clock source            = PLL (HSE)
	*   SYSCLK(Hz)                     = 216000000
	*   HCLK(Hz)                       = 216000000
	*   AHB Prescaler                  = 1
	*   APB1 Prescaler                 = 4
	*   APB2 Prescaler                 = 2
	*   HSE Frequency(Hz)              = 25000000
	*   PLL_M                          = 25
	*   PLL_N                          = 432
	*   PLL_P                          = 2
	*   PLL_Q                          = 9
	*   VDD(V)                         = 3.3
	*   Main regulator output voltage  = Scale1 mode
	*   Flash Latency(WS)              = 7
	*/
void SystemClock_Config (void) {
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;
	RCC_PeriphCLKInitTypeDef RCC_PeriphClkInitStruct;

	/* Enable HSE Oscillator and activate PLL with HSE as source */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 25;
	RCC_OscInitStruct.PLL.PLLN = 400;  
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 9;
	HAL_RCC_OscConfig(&RCC_OscInitStruct);

	/* Activate the OverDrive to reach the 216 MHz Frequency */
	HAL_PWREx_EnableOverDrive();
	
	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;  
	HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7);

	/* Select 48MHz clock source as SDMMC1 clock */
	RCC_PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SDMMC1;
	RCC_PeriphClkInitStruct.Sdmmc1ClockSelection = RCC_SDMMC1CLKSOURCE_CLK48;
	HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInitStruct); 
}

/**
	* Configure the MPU attributes as Write Through for SRAM1/2
	*   The Base Address is 0x20010000 since this memory interface is the AXI.
	*   The Region Size is 256KB, it is related to SRAM1 and SRAM2 memory size.
	*/
void MPU_Config (void) {
	MPU_Region_InitTypeDef MPU_InitStruct;
	
	/* Disable the MPU */
	HAL_MPU_Disable();

	/* Configure the MPU attributes as WT for SRAM */
	MPU_InitStruct.Enable = MPU_REGION_ENABLE;
	MPU_InitStruct.BaseAddress = 0x20010000;
	MPU_InitStruct.Size = MPU_REGION_SIZE_256KB;
	MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
	MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
	MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
	MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
	MPU_InitStruct.Number = MPU_REGION_NUMBER0;
	MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
	MPU_InitStruct.SubRegionDisable = 0x00;
	MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

	HAL_MPU_ConfigRegion(&MPU_InitStruct);

	/* Enable the MPU */
	HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

/**
	* CPU L1-Cache enable
	*/
void CPU_CACHE_Enable (void) {

	/* Enable I-Cache */
	SCB_EnableICache();

	/* Enable D-Cache */
	SCB_EnableDCache();
}

/*-----------------------------------------------------------------------------
 *        Initialize On Board LCD Module
 *----------------------------------------------------------------------------*/
void init_display () {
//  GLCD_Initialize         ();
//  GLCD_SetBackgroundColor (GLCD_COLOR_BLUE);
//  GLCD_SetForegroundColor (GLCD_COLOR_WHITE);
//  GLCD_ClearScreen        ();
//  GLCD_SetFont            (&GLCD_Font_16x24);
//  GLCD_DrawString         (5*16, 0*24, "  STM32F746G-DISCO  ");
//  GLCD_DrawString         (5*16, 1*24, "  Evaluation Board  ");
//  GLCD_DrawString         (5*16, 3*24, "      MDK-ARM       ");
//  GLCD_DrawString         (5*16, 4*24, " File_Demo example  ");
}

/*-----------------------------------------------------------------------------
 *        Extract drive specification from the input string
 *----------------------------------------------------------------------------*/
char *get_drive (char *src, char *dst, uint32_t dst_sz) {
	uint32_t i, n;

	i = 0;
	n = 0;
	while (!n && src && src[i] && (i < dst_sz)) {
		dst[i] = src[i];

		if (dst[i] == ':') {
			n = i + 1;
		}
		i++;
	}
	if (n == dst_sz) {
		n = 0;
	}
	dst[n] = '\0';

	return (src + n);
}

/*-----------------------------------------------------------------------------
 *        Process input string for long or short name entry
 *----------------------------------------------------------------------------*/
char *get_entry (char *cp, char **pNext) {
	char *sp, lfn = 0, sep_ch = ' ';

	if (cp == NULL) {                           /* skip NULL pointers           */
		*pNext = cp;
		return (cp);
	}

	for ( ; *cp == ' ' || *cp == '\"'; cp++) {  /* skip blanks and starting  "  */
		if (*cp == '\"') { sep_ch = '\"'; lfn = 1; }
		*cp = 0;
	}
 
	for (sp = cp; *sp != CR && *sp != LF && *sp != 0; sp++) {
		if ( lfn && *sp == '\"') break;
		if (!lfn && *sp == ' ' ) break;
	}

	for ( ; *sp == sep_ch || *sp == CR || *sp == LF; sp++) {
		*sp = 0;
		if ( lfn && *sp == sep_ch) { sp ++; break; }
	}

	*pNext = (*sp) ? sp : NULL;                 /* next entry                   */
	return (cp);
}

/*-----------------------------------------------------------------------------
 *        Print size in dotted fomat
 *----------------------------------------------------------------------------*/
void dot_format (uint64_t val, char *sp) {

	if (val >= (uint64_t)1e12) {
		sp += sprintf (sp,"%d.",(uint32_t)(val/(uint64_t)1e12));
		val %= (uint64_t)1e12;
		sp += sprintf (sp,"%03d.",(uint32_t)(val/(uint64_t)1e9));
		val %= (uint64_t)1e9;
		sp += sprintf (sp,"%03d.",(uint32_t)(val/(uint64_t)1e6));
		val %= (uint64_t)1e6;
		sprintf (sp,"%03d.%03d",(uint32_t)(val/1000),(uint32_t)(val%1000));
		return;
	}
	if (val >= (uint64_t)1e9) {
		sp += sprintf (sp,"%d.",(uint32_t)(val/(uint64_t)1e9));
		val %= (uint64_t)1e9;
		sp += sprintf (sp,"%03d.",(uint32_t)(val/(uint64_t)1e6));
		val %= (uint64_t)1e6;
		sprintf (sp,"%03d.%03d",(uint32_t)(val/1000),(uint32_t)(val%1000));
		return;
	}
	if (val >= (uint64_t)1e6) {
		sp += sprintf (sp,"%d.",(uint32_t)(val/(uint64_t)1e6));
		val %= (uint64_t)1e6;
		sprintf (sp,"%03d.%03d",(uint32_t)(val/1000),(uint32_t)(val%1000));
		return;
	}
	if (val >= 1000) {
		sprintf (sp,"%d.%03d",(uint32_t)(val/1000),(uint32_t)(val%1000));
		return;
	}
	sprintf (sp,"%d",(uint32_t)(val));
}

/*-----------------------------------------------------------------------------
 *        Capture serial data to file
 *----------------------------------------------------------------------------*/
void cmd_capture (char *par) {
	char *fname, *next;
	bool  append, retv;
	FILE *f;

	fname = get_entry (par, &next);
	if (fname == NULL) {
		printf ("\nFilename missing.\n");
		return;
	}
	append = false;
	if (next) {
		par = get_entry (next, &next);
		if ((strcmp (par, "/A") == 0) ||(strcmp (par, "/a") == 0)) {
			append = true;
		}
		else {
			printf ("\nCommand error.\n");
			return;
		}
	}
	printf ((append) ? "\nAppend data to file %s" :
										 "\nCapture data to file %s", fname);
	printf("\nPress ESC to stop.\n");
	f = fopen (fname,append ? "a" : "w"); /* open a file for writing            */
	if (f == NULL) {
		printf ("\nCan not open file!\n");  /* error when trying to open file     */
		return;
	}
	do {
		retv = getline (in_line, sizeof (in_line));
		fputs (in_line, f);
	} while (retv == true);
	fclose (f);                         /* close the output file                */
	printf ("\nFile closed.\n");
}

/*-----------------------------------------------------------------------------
 *        Create a file and fill it with some text
 *----------------------------------------------------------------------------*/
void cmd_fill (char *par) {
	char *fname, *next;
	FILE *f;
	int i,cnt = 1000;

	fname = get_entry (par, &next);
	if (fname == NULL) {
		printf ("\nFilename missing.\n");
		return;
	}
	if (next) {
		par = get_entry (next, &next);
		if (sscanf (par,"%d", &cnt) == 0) {
			printf ("\nCommand error.\n");
			return;
		}
	}

	f = fopen (fname, "w");               /* open a file for writing            */
	if (f == NULL) {
		printf ("\nCan not open file!\n");  /* error when trying to open file     */
		return;
	} 
	for (i = 0; i < cnt; i++)  {
		fprintf (f, "This is line # %d in file %s\n", i, fname);
		if (!(i & 0x3FF)) printf("."); fflush (stdout);
	}
	fclose (f);                           /* close the output file              */
	printf ("\nFile closed.\n");
}

/*-----------------------------------------------------------------------------
 *        Read file and dump it to serial window
 *----------------------------------------------------------------------------*/
void cmd_type (char *par) {
	char *fname,*next;
	FILE *f;
	int ch;

	fname = get_entry (par, &next);
	if (fname == NULL) {
		printf ("\nFilename missing.\n");
		return;
	}
	printf("\nRead data from file %s\n",fname);
	f = fopen (fname,"r");                /* open the file for reading          */
	if (f == NULL) {
		printf ("\nFile not found!\n");
		return;
	}
 
	while ((ch = fgetc (f)) != EOF) {     /* read the characters from the file  */
		putchar (ch);                       /* and write them on the screen       */
	}
	fclose (f);                           /* close the input file when done     */
	printf ("\nFile closed.\n");
}

/*-----------------------------------------------------------------------------
 *        Rename a File
 *----------------------------------------------------------------------------*/
void cmd_rename (char *par) {
	char *fname,*fnew,*next,dir;

	fname = get_entry (par, &next);
	if (fname == NULL) {
		printf ("\nFilename missing.\n");
		return;
	}
	fnew = get_entry (next, &next);
	if (fnew == NULL) {
		printf ("\nNew Filename missing.\n");
		return;
	}
	if (strcmp (fname,fnew) == 0) {
		printf ("\nNew name is the same.\n");
		return;
	}

	dir = 0;
	if (*(fname + strlen(fname) - 1) == '\\') {
		dir = 1;
	}

	if (frename (fname, fnew) == fsOK) {
		if (dir) {
			printf ("\nDirectory %s renamed to %s\n",fname,fnew);
		}
		else {
			printf ("\nFile %s renamed to %s\n",fname,fnew);
		}
	}
	else {
		if (dir) {
			printf ("\nDirectory rename error.\n");
		}
		else {
			printf ("\nFile rename error.\n");
		}
	}
}

/*-----------------------------------------------------------------------------
 *        Copy a File
 *----------------------------------------------------------------------------*/
void cmd_copy (char *par) {
	char *fname,*fnew,*fmer,*next;
	FILE *fin,*fout;
	uint32_t cnt,total;
	char buf[512];
	bool merge;

	fname = get_entry (par, &next);
	if (fname == NULL) {
		printf ("\nFilename missing.\n");
		return;
	}
	fmer = get_entry (next, &next);
	if (fmer == NULL) {
		printf ("\nNew Filename missing.\n");
		return;
	}
	fnew = get_entry (next, &next);
	if (fnew != NULL) {
		merge = true;
	}
	else {
		merge = false;
		fnew = fmer;
	}
	if ((strcmp (fname,fnew) == 0) || (merge && strcmp (fmer,fnew) == 0)) {
		printf ("\nNew name is the same.\n");
		return;
	}

	fin = fopen (fname,"r");              /* open the file for reading          */
	if (fin == NULL) {
		printf ("\nFile %s not found!\n",fname);
		return;
	}

	if (merge == false) {
		printf ("\nCopy file %s to %s\n",fname,fnew);
	}
	else {
		printf ("\nCopy file %s, %s to %s\n",fname,fmer,fnew);
	}
	fout = fopen (fnew,"w");              /* open the file for writing          */
	if (fout == NULL) {
		printf ("\nFailed to open %s for writing!\n",fnew);
		fclose (fin);
		return;
	}

	total = 0;
	while ((cnt = fread (&buf, 1, 512, fin)) != 0) {
		fwrite (&buf, 1, cnt, fout);
		total += cnt;
	}
	fclose (fin);                         /* close input file when done         */

	if (merge == true) {
		fin = fopen (fmer,"r");             /* open the file for reading          */
		if (fin == NULL) {
			printf ("\nFile %s not found!\n",fmer);
		}
		else {
			while ((cnt = fread (&buf, 1, 512, fin)) != 0) {
				fwrite (&buf, 1, cnt, fout);
				total += cnt;
			}
			fclose (fin);
		}
	}
	fclose (fout);
	dot_format (total, &buf[0]);
	printf ("\n%s bytes copied.\n", &buf[0]);
}

/*-----------------------------------------------------------------------------
 *        Delete a File
 *----------------------------------------------------------------------------*/
void cmd_delete (char *par) {
	char *fname, *next;
	fsStatus status;

	fname = get_entry (par, &next);
	if (fname == NULL) {
		printf ("\nFilename missing.\n");
		return;
	}
	status = fdelete (fname, next);

	if (status == fsOK) {
		printf ("\nDelete successful.\n");
	}
	else if (status == fsFileNotFound) {
		printf ("\nFile %s not found.\n",fname);
	}
	else {
		printf ("\nDelete failed.\n");
	}
}

/*-----------------------------------------------------------------------------
 *        Print a Directory
 *----------------------------------------------------------------------------*/
void cmd_dir (char *par) {
	uint64_t fsize;
	uint32_t files,dirs,i;
	char temp[32],*mask,*next,ch;
	fsFileInfo info;

	mask = get_entry (par, &next);
	if (mask == NULL) {
		mask = "*.*";
	} else if ((mask[1] == ':') && (mask[2] == 0)) {
		mask[2] = '*'; 
		mask[3] = '.'; 
		mask[4] = '*'; 
		mask[5] = 0; 
	} else if ((mask[2] == ':') && (mask[3] == 0)) {
		mask[3] = '*'; 
		mask[4] = '.'; 
		mask[5] = '*'; 
		mask[6] = 0; 
	}

	printf ("\nFile System Directory...");
	files = 0;
	dirs  = 0;
	fsize = 0;
	info.fileID  = 0;
	while (ffind (mask,&info) == fsOK) {
		if (info.attrib & FS_FAT_ATTR_DIRECTORY) {
			i = 0;
			while (strlen((const char *)info.name+i) > 41) {
				ch = info.name[i+41];
				info.name[i+41] = 0;
				printf ("\n%-41s", &info.name[i]);
				info.name[i+41] = ch;
				i += 41;
			}
			printf ("\n%-41s    <DIR>       ", &info.name[i]);
			printf ("  %02d.%02d.%04d  %02d:%02d",
							 info.time.day, info.time.mon, info.time.year,
							 info.time.hr, info.time.min);
			dirs++;
		}
		else {
			dot_format (info.size, &temp[0]);
			i = 0;
			while (strlen((const char *)info.name+i) > 41) {
				ch = info.name[i+41];
				info.name[i+41] = 0;
				printf ("\n%-41s", &info.name[i]);
				info.name[i+41] = ch;
				i += 41;
			}
			printf ("\n%-41s %14s ", &info.name[i], temp);
			printf ("  %02d.%02d.%04d  %02d:%02d",
							 info.time.day, info.time.mon, info.time.year,
							 info.time.hr, info.time.min);
			fsize += info.size;
			files++;
		}
	}
	if (info.fileID == 0) {
		printf ("\nNo files...");
	}
	else {
		dot_format (fsize, &temp[0]);
		printf ("\n              %9d File(s)    %21s bytes", files, temp);
	}
	dot_format (ffree(mask), &temp[0]);
	if (dirs) {
		printf ("\n              %9d Dir(s)     %21s bytes free.\n", dirs, temp);
	}
	else {
		printf ("\n%56s bytes free.\n",temp);
	}
}

/*-----------------------------------------------------------------------------
 *        Format Device
 *----------------------------------------------------------------------------*/
void cmd_format (char *par) {
	char  label[12];
	char  drive[4];
	int   retv;

	par = get_drive (par, drive, 4);

	printf ("\nProceed with Format [Y/N]\n");
	retv = getchar();
	if (retv == 'y' || retv == 'Y') {
		/* Format the drive */
		if (fformat (drive, par) == fsOK) {
			printf ("Format completed.\n");
			if (fvol (drive, label, NULL) == 0) {
				if (label[0] != '\0') {
					printf ("Volume label is \"%s\"\n", label);
				}
			}
		}
		else {
			printf ("Formatting failed.\n");
		}
	}
	else {
		printf ("Formatting canceled.\n");
	}
}

/*-----------------------------------------------------------------------------
 *        Change file attributes
 *----------------------------------------------------------------------------*/
void cmd_attrib (char *par) {
	char *arg, *path, *next, *sp;

	path = par;
	next = par;
	arg  = par;

	/* Parse input string for parameters */
	do {
		sp = get_entry (next, &next);

		if (sp == 0 && next == 0) {
			printf ("\nCommand error.\n");
			return;
		}

		if (next) {
			if (*next == '+' || *next == '-') {
				*(next - 1) = ' ';
			}
			else {
				path = next;
			}
		}
	}
	while (sp && next);

	if (fattrib (path, arg) != fsOK) {
		printf ("Failed to change file attributes.\n");
	}
	else {
		printf ("File attributes changed.\n");
	}
}

/*-----------------------------------------------------------------------------
 *        Read and output SD card CID register
 *----------------------------------------------------------------------------*/
void cmd_cid (char *par) {
	char drive[4];
	int32_t id;
	fsCID_Register cid;

	par = get_drive (par, drive, 4);
	id    = fs_ioc_get_id (drive);
	if (id >= 0 && (fs_ioc_lock (id) == fsOK)) {
		if (fs_ioc_device_ctrl (id, fsDevCtrlCodeGetCID, &cid) == fsOK) {
			printf ("Manufacturer ID: %d (0x%.2X)\n",  cid.MID, cid.MID);
			printf ("OEM/Application ID: %c%c\n",    cid.OID >> 8, cid.OID & 0xFF);
			printf ("Product name: %c%c%c%c%c\n", cid.PNM[0], cid.PNM[1], cid.PNM[2],
																						cid.PNM[3], cid.PNM[4]);
			printf ("Product revision: %d.%d\n",     cid.PRV >> 4, cid.PRV & 0x0F);
			printf ("Product serial number: 0x%X\n", cid.PSN);
			printf ("Manufacturing date: %d/%.2d\n", cid.MDT & 0x0F, cid.MDT >> 4);
		}
		else printf ("CID register read failed.\n");

		fs_ioc_unlock (id);
	}
	else printf ("Specified drive doesn't exists!");
}

/*-----------------------------------------------------------------------------
 *        Display Command Syntax help
 *----------------------------------------------------------------------------*/
void cmd_help (char *par) {
	printf (help);
}

/*-----------------------------------------------------------------------------
 *        Initialize a Flash Memory Card
 *----------------------------------------------------------------------------*/
void init_filesystem (void) {
	fsStatus stat;

	printf ("Initializing and mounting enabled drives...\n\n");

	/* Initialize and mount drive "M0" */
	stat = finit ("M0:");
	if (stat == fsOK) {
		stat = fmount ("M0:");
		if (stat == fsOK) {
			printf ("Drive M0 ready!\n");
		}
		else if (stat == fsNoFileSystem) {
			/* Format the drive */
			printf ("Drive M0 not formatted!\n");
			cmd_format ("M0:");
		}
		else {
			printf ("Drive M0 mount failed with error code %d\n", stat);
		}
	}
	else {
		printf ("Drive M0 initialization failed!\n");
	}

	printf ("\nDone!\n");
}
#if 0
/*-----------------------------------------------------------------------------
 *        Main: 
 *----------------------------------------------------------------------------*/
int main (void) {
	char *sp,*cp,*next;
	uint32_t i;
	FILE  			  *fin;
	char 			   count[20];
	MPU_Config();                             /* Configure the MPU              */
	CPU_CACHE_Enable();                       /* Enable the CPU Cache           */

	HAL_Init();                               /* Initialize the HAL Library     */
	SystemClock_Config();                     /* Configure the System Clock     */

	init_display ();
	printf (intro);                               /* display example info       */
	printf (help);

	init_filesystem ();

#if 0
	while (1) {
		printf ("\nCmd> ");                         /* display prompt             */
		fflush (stdout);
																								/* get command line input     */
		if (getline (in_line, sizeof (in_line)) == false) {
			continue;
		}

		sp = get_entry (&in_line[0], &next);
		if (*sp == 0) {
			continue;
		}
		for (cp = sp; *cp && *cp != ' '; cp++) {
			*cp = toupper (*cp);                    /* command to upper-case      */
		}
		for (i = 0; i < CMD_COUNT; i++) {
			if (strcmp (sp, (const char *)&cmd[i].val)) {
				continue;
			}
			cmd[i].func (next);                     /* execute command function   */
			break;
		}
		if (i == CMD_COUNT) {
			printf ("\nCommand error\n");
		}
	}
#else
	
	printf ("file demo!!!!\n");
	fin = fopen("M0:","r");
	while (fin != NULL)  {
		fread (&count[0], sizeof (int), 10, fin);
		printf("count is %s\n",count);
		
	}
	fclose (fin);
	while(1);
	
#endif
}
#endif
