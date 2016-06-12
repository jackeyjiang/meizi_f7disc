/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2012  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.12 - Graphical user interface for embedded applications **
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with a license and should not be re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : DIALOG_FS_ChooseFile.c
Purpose     : Shows how to make use of the CHOOSEFILE dialog.
							It shows the dialog with and without skinning.
							The button bar is shown at the bottom and at the top
							of the window.
Requirements: WindowManager - (x)
							MemoryDevices - (x)
							AntiAliasing  - ( )
							VNC-Server    - ( )
							PNG-Library   - ( )
							TrueTypeFonts - ( )

							Requires eithar a MS Windows environment or emFile!
----------------------------------------------------------------------
*/

#include "DIALOG.h"
#include "MESSAGEBOX.h"

#ifdef WIN32
	#include <windows.h>
#else
	#include "RTE_Components.h"
	#include "string.h"
	#include "stdio.h"
	#include <stdio.h>                      /* Standard I/O .h-file               */
	#include <ctype.h>                      /* Character functions                */
	#include <string.h>                     /* String and memory functions        */

	#include "cmsis_os.h"                   /* CMSIS RTOS definitions             */
	#include "./Terminal.h"
	#include "stm32f7xx_hal.h"
	#include "rl_fs.h"
#endif

#define _MAX_PATH   260 /* max. length of full pathname */
#define _MAX_DRIVE  3   /* max. length of drive component */
#define _MAX_DIR    256 /* max. length of path component */
#define _MAX_FNAME  256 /* max. length of file name component */
#define _MAX_EXT    256 /* max. length of extension component */

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
static struct {
	U32 Mask;
	char c;
} _aAttrib[] = {
{FS_FAT_ATTR_READ_ONLY, 'R'},
{FS_FAT_ATTR_HIDDEN,    'H'},
{FS_FAT_ATTR_SYSTEM,    'S'},
{FS_FAT_ATTR_VOLUME_ID, 'V'},
{FS_FAT_ATTR_DIRECTORY, 'D'},
{FS_FAT_ATTR_ARCHIVE,   'A'}
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
static int _GetData(CHOOSEFILE_INFO * pInfo);
static void dot_format (uint64_t val, char *sp);

/*********************************************************************
*
*       _GetExt
*/
static void _GetExt(char * pFile, char * pExt) {
	int Len;
	int i;
	int j;
	int k = 0;

	//
	// Search beginning of extension
	//
	Len = strlen(pFile);
	for (i = Len; i > 0; i--) {
		if (*(pFile + i) == '.') {
			*(pFile + i) = '\0';     // Cut extension from filename
			k = 1;
			break;
		}
	}
	if(k==0) return;
	//
	// Copy extension
	//
	j = 0;
	while (*(pFile + ++i) != '\0') {
		*(pExt + j) = *(pFile + i);
		j++;
	}
	*(pExt + j) = '\0';          // Set end of string
}

/*********************************************************************
*
*       _GetData
*/
static int _GetData(CHOOSEFILE_INFO * pInfo) 
{
	static int NewDir;   //是否为新打开的路径
	fsStatus fs_status;   //rl-fs API 返回值
	static char acAttrib[10]         = { 0 };  //文件属性
	
	static char acDrive [_MAX_DRIVE];
	static char acDir   [_MAX_DIR];
	static char acName  [_MAX_FNAME];
	static char acExt   [_MAX_EXT];
	static char acMask  [_MAX_PATH];
	static char acPath  [_MAX_PATH];
	
	char  c;  //用于存储文件属性的值
	char ch; //用于长文件名
	int i;    //循环用
	int r;   //读取文件的返回值
	char *fn;  //文件名指针
	char temp[32];
	
	uint64_t fsize;
	uint32_t files,dirs;
	
	static fsFileInfo ffinfo;  //打开的文件信息
	
	files = 0;
	dirs  = 0;
	fsize = 0;
	ffinfo.fileID  = 0;
	
	switch (pInfo->Cmd) 
	{
		case CHOOSEFILE_FINDFIRST:
		NewDir = 1;
		//
		// Do not 'break' here...
		//
		case CHOOSEFILE_FINDNEXT:
		if (NewDir) //NewDir = 1
		{  
			memset(acPath,0,sizeof(acPath));
			strcat(acPath,pInfo->pRoot);
			strcat(acPath,pInfo->pMask);
			printf("acPath:%s\n",acPath);
			if((fs_status = ffind (acPath,&ffinfo)) == fsOK)
			{
				printf(" fs_status  %d\n",fs_status);
				if (ffinfo.attrib & FS_FAT_ATTR_DIRECTORY)
				{
					
					i = 0;
					while (strlen((const char *)ffinfo.name+i) > 41) 
					{
						ch = ffinfo.name[i+41];
						ffinfo.name[i+41] = 0;
						printf ("\n%-41s", &ffinfo.name[i]);
						ffinfo.name[i+41] = ch;
						i += 41;
					}
					printf ("\n%-41s    <DIR>       ", &ffinfo.name[i]);
					printf ("  %02d.%02d.%04d  %02d:%02d",
									 ffinfo.time.day, ffinfo.time.mon, ffinfo.time.year,
									 ffinfo.time.hr, ffinfo.time.min);
					
					fn = ffinfo.name;
					pInfo->Flags = (ffinfo.attrib & _aAttrib[4].Mask) ? CHOOSEFILE_FLAG_DIRECTORY : 0;
					for (i = 0; i < GUI_COUNTOF(_aAttrib); i++) {
					  if (ffinfo.attrib & _aAttrib[i].Mask) {
						c = _aAttrib[i].c;
					  } else {
						c = '-';
					  }
					  acAttrib[i] = c;
					}
					r = 0;
				}
				else 
				{
					dot_format (ffinfo.size, &temp[0]);
					i = 0;
					while (strlen((const char *)ffinfo.name+i) > 41)
					{
						ch = ffinfo.name[i+41];
						ffinfo.name[i+41] = 0;
						printf ("\n%-41s", &ffinfo.name[i]);
						ffinfo.name[i+41] = ch;
						i += 41;
					}
					printf ("\n%-41s %14s ", &ffinfo.name[i], temp);
					printf ("  %02d.%02d.%04d  %02d:%02d",
									 ffinfo.time.day, ffinfo.time.mon, ffinfo.time.year,
									 ffinfo.time.hr, ffinfo.time.min);
					fsize += ffinfo.size;
					files++;
					fn = ffinfo.name;
					pInfo->Flags = (ffinfo.attrib & _aAttrib[4].Mask) ? CHOOSEFILE_FLAG_DIRECTORY : 0;
					for (i = 0; i < GUI_COUNTOF(_aAttrib); i++) {
					  if (ffinfo.attrib & _aAttrib[i].Mask) {
						c = _aAttrib[i].c;
					  } else {
						c = '-';
					  }
					  acAttrib[i] = c;
					}
					r = 0;
					r = 0;
				}
			}
			else
			{
				r = 1;
			}
			if (ffinfo.fileID == 0)
			{
				printf ("\nNo files...");
			}
			else 
			{
				dot_format (fsize, &temp[0]);
				printf ("\n              %9d File(s)    %21s bytes", files, temp);
			}
			//dot_format (ffree(acPath), &temp[0]);
			if (dirs)
			{
				printf ("\n              %9d Dir(s)     %21s bytes free.\n", dirs, temp);
			}
			else 
			{
				printf ("\n%56s bytes free.\n",temp);
			}
			NewDir = 0;
		}
		else  // NewDir = 0 
		{
			//strcat(acPath,pInfo->pRoot);
			//strcat(acPath,pInfo->pMask);
			printf("acPath:%s\n",acPath);
			if((fs_status = ffind (acPath,&ffinfo)) == fsOK)
			{
				printf(" fs_status  %d\n",fs_status);
				if (ffinfo.attrib & FS_FAT_ATTR_DIRECTORY)
				{
					i = 0;
					while (strlen((const char *)ffinfo.name+i) > 41) 
					{
						ch = ffinfo.name[i+41];
						ffinfo.name[i+41] = 0;
						printf ("\n%-41s", &ffinfo.name[i]);
						ffinfo.name[i+41] = ch;
						i += 41;
					}
					printf ("\n%-41s    <DIR>       ", &ffinfo.name[i]);
					printf ("  %02d.%02d.%04d  %02d:%02d",
									 ffinfo.time.day, ffinfo.time.mon, ffinfo.time.year,
									 ffinfo.time.hr, ffinfo.time.min);
					fn = ffinfo.name;
					for (i = 0; i < GUI_COUNTOF(_aAttrib); i++) {
					  if (ffinfo.attrib & _aAttrib[i].Mask) {
						c = _aAttrib[i].c;
					  } else {
						c = '-';
					  }
					  acAttrib[i] = c;
					}
					r = 0;
					
					r = 0;
				}
				else 
				{
					dot_format (ffinfo.size, &temp[0]);
					i = 0;
					while (strlen((const char *)ffinfo.name+i) > 41)
					{
						ch = ffinfo.name[i+41];
						ffinfo.name[i+41] = 0;
						printf ("\n%-41s", &ffinfo.name[i]);
						ffinfo.name[i+41] = ch;
						i += 41;
					}
					printf ("\n%-41s %14s ", &ffinfo.name[i], temp);
					printf ("  %02d.%02d.%04d  %02d:%02d",
									 ffinfo.time.day, ffinfo.time.mon, ffinfo.time.year,
									 ffinfo.time.hr, ffinfo.time.min);
					fsize += ffinfo.size;
					files++;
					fn = ffinfo.name;
					for (i = 0; i < GUI_COUNTOF(_aAttrib); i++) {
					  if (ffinfo.attrib & _aAttrib[i].Mask) {
						c = _aAttrib[i].c;
					  } else {
						c = '-';
					  }
					  acAttrib[i] = c;
					}
					r = 0;
					r= 0 ;
				}
			}
			else
			{
				printf("find file erro\n");
				r = 1;
			}       
		}
	
		if(r == 0)
		{
		
			//
			// Generate attribute string (pInfo->pAttrib)
			//
			for (i = 0; i < GUI_COUNTOF(_aAttrib); i++) {
				c = (ffinfo.attrib & _aAttrib[i].Mask) ? _aAttrib[i].c : '-';
				acAttrib[i] = c;
			}
			//
			// Make name and extension (pInfo->pName, pInfo->pExt)
			//
			if(ffinfo.attrib & _aAttrib[4].Mask)
			{
				pInfo->pExt    = "Directory";
			}
			else
			{
				_GetExt(fn, acExt);
				pInfo->pExt    = acExt; 
			}
			//
			// Pass data to dialog
			//
			pInfo->pAttrib = acAttrib;
			pInfo->pName   = fn;//acName;
			pInfo->pExt    = acExt;
			pInfo->SizeL   = ffinfo.size << 10;
			pInfo->SizeH   = ffinfo.size >> 22;
			pInfo->Flags   = (ffinfo.attrib & FS_FAT_ATTR_DIRECTORY) 
											 ? CHOOSEFILE_FLAG_DIRECTORY : 0;
			printf("pInfo->pName:%s\n",pInfo->pName);
		}
	}
	return r;
}



/*********************************************************************
*
*       _EnableSkinning
*/
static void _EnableSkinning(int OnOff) {
	if (OnOff) {
		FRAMEWIN_SetDefaultSkin(FRAMEWIN_SKIN_FLEX);
		BUTTON_SetDefaultSkin  (BUTTON_SKIN_FLEX);
		DROPDOWN_SetDefaultSkin(DROPDOWN_SKIN_FLEX);
		HEADER_SetDefaultSkin(HEADER_SKIN_FLEX);
		SCROLLBAR_SetDefaultSkin(SCROLLBAR_SKIN_FLEX);
	} else {
		FRAMEWIN_SetDefaultSkinClassic();
		BUTTON_SetDefaultSkinClassic();
		DROPDOWN_SetDefaultSkinClassic();
		HEADER_SetDefaultSkinClassic();
		SCROLLBAR_SetDefaultSkinClassic();
	}
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       OnICON00Clicked
*/
void OnICON00Clicked(void)
{
	const char        acMask[]            = "*.*";
	CHOOSEFILE_INFO   Info                = { 0 };
	WM_HWIN           hWin;
	int               r;
	char              acDirLocal[_MAX_PATH]= "M0:\\";
	char const      * apDrives[1]         = {acDirLocal};

	FRAMEWIN_SetDefaultFont(GUI_FONT_20_ASCII);
	FRAMEWIN_SetDefaultTextAlign(GUI_TA_HCENTER);
	LISTVIEW_SetDefaultFont(GUI_FONT_16_ASCII);
	HEADER_SetDefaultFont(GUI_FONT_16_ASCII);
	BUTTON_SetDefaultFont(GUI_FONT_16_ASCII);

	Info.pfGetData = _GetData;
	Info.pMask     = acMask;

	while (1) 
	{
		CHOOSEFILE_SetTopMode(1);
		hWin = CHOOSEFILE_Create(0,          //Handle of parent window.
								 0,              //X position in pixels of the  dialog in clie nt coordinates.
								 0,              //Y position in pixels of the  dialog in client coordinates.
								 LCD_GetXSize(),     //X-size of the dialog in pixels.
								 LCD_GetYSize(),       //Y-size of the dialog in pixels
								 apDrives,           //Pointer to an array of strings containing the root directories to be used.
								 GUI_COUNTOF(apDrives),//Number of root directories. 
								 0,            //Initial index of the root directory to be used.
								 "File Dialog",      //Title to be shown in the title bar.
								 0,            //Additional flags for the FRAMEWIN widget.
								 &Info);         //Pointer to a CHOOSEFILE_INFO structure.
		
		CHOOSEFILE_SetButtonText(hWin, CHOOSEFILE_BI_CANCEL, "Close");

		r = GUI_ExecCreatedDialog(hWin);
		
		// 由 case GUI_ID_OK: GUI_EndDialog(hWin, 0);
		if (r == 0) 
		{
			//点击了Archive属性的文件 会进入到这里，也就是说，可以
			//在这里进入图片显示，MP3播放等功能。
			hWin = MESSAGEBOX_Create(Info.pRoot, "File:", 0);
			GUI_Delay(2000);
			WM_DeleteWindow(hWin);
		}
		// 由case GUI_ID_CANCEL: GUI_EndDialog(hWin, 1);  
		else 
		{
			WM_DeleteWindow(hWin);
		}
	}
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