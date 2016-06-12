/**
  ******************************************************************************
  * 文件: file_list.c
  * 作者: LeiTek (leitek.taobao.com)
  * 版本: V1.0.0
  * 描述: SPI flash 模块中间件层，实现 SPI flash 初始化，读写等功能
  ******************************************************************************
  *
  *                  版权所有 (C), LeiTek (leitek.taobao.com)
  *                                www.leitek.com
  *
  ******************************************************************************
  */
  
/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx.h"
#include "stdio.h"
#include "string.h"
#include "rl_fs.h" 
#include "filelist.h"
#include "Terminal.h"

/*
********************************************************************
*
*       Static data
*
**********************************************************************
*/
static struct {
  uint32_t Mask;
  char c;
} _aAttrib[] = {
{FS_FAT_ATTR_READ_ONLY,   'R'},
{FS_FAT_ATTR_HIDDEN,	  'H'},
{FS_FAT_ATTR_SYSTEM,	  'S'},
{FS_FAT_ATTR_VOLUME_ID,	  'V'},
{FS_FAT_ATTR_DIRECTORY,	  'D'},
{FS_FAT_ATTR_ARCHIVE,	  'A'}
};


static char *get_entry (char *cp, char **pNext);
static void dot_format (uint64_t val, char *sp);
static void _GetExt(char * pFile, char * pExt);

FILE_LIST_STRUCT fileList;
void fill_filelist(char *par)
{
  int64_t fsize;
  uint32_t files,dirs,i;
  char temp[32],*mask,*next,ch;
  fsFileInfo info;
  uint8_t file_cnt=0;
  char                c;
  char         acExt   [256] = {0};
  char         acAttrib[20]  = { 0 };
  int          fileNameLen = 0;
  
  fileNameLen = strlen(par);
  mask = par;//get_entry (par, &next);
  if( fileNameLen==0 ) {
	mask = "M0:\\*.*";
  } else if (mask[2] == ':') {
    mask[fileNameLen+0] = '*'; 
    mask[fileNameLen+1] = '.'; 
    mask[fileNameLen+2] = '*'; 
    mask[fileNameLen+3] = 0; 
  }

  printf ("\nFile System Directory...");
  files = 0;
  dirs  = 0;
  fsize = 0;
  info.fileID  = 0;
  file_cnt = 0;
  /* 获取当前的路径 */
  memcpy(fileList.currentFloderPath,mask,strlen(mask));
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
	  if(strstr(&info.name[i],".")) continue;   //remove .. and .
	  if(strstr(&info.name[i],"..")) continue;
      memcpy(fileList.fileInfo[file_cnt].fileName,&info.name[i],strlen(&info.name[i]));
      fileList.fileInfo[file_cnt].flag = 1;
      for (i = 0; i < 6; i++) {
        if (info.attrib & _aAttrib[i].Mask) {
            c = _aAttrib[i].c;
        }else{
            c = '-';
        }
        fileList.fileInfo[file_cnt].fileAttribe[i] = c;
      }
      memcpy(fileList.fileInfo[file_cnt].fileExt,"Dir",strlen("Dir"));
	  file_cnt++;
	  fileList.fileCnt = file_cnt;
    }else{
      dot_format (info.size, &temp[0]);
      i = 0;
      while (strlen((const char *)info.name+i) > 41) {
        ch = info.name[i+41];
        info.name[i+41] = 0;
        printf ("\n%-41s", &info.name[i]);
        info.name[i+41] = ch;
        i += 41;
      }
      memcpy(fileList.fileInfo[file_cnt].fileName,&info.name[i],strlen(&info.name[i]));
      fileList.fileInfo[file_cnt].flag = 0; 
      for (i = 0; i < 6; i++) {
        if (info.attrib & _aAttrib[i].Mask) {
            c = _aAttrib[i].c;
        }else{
            c = '-';
        }
        fileList.fileInfo[file_cnt].fileAttribe[i] = c;
      }
      _GetExt(&fileList.fileInfo[file_cnt].fileName[0], acExt);
      memcpy(fileList.fileInfo[file_cnt].fileExt,acExt,strlen(acExt));
	  file_cnt++; 
	  fileList.fileCnt = file_cnt;
    }
  }
}

/*-----------------------------------------------------------------------------
 *        Process input string for long or short name entry
 *----------------------------------------------------------------------------*/
static char *get_entry (char *cp, char **pNext) {
  char *sp, lfn = 0, sep_ch = ' ';

  if (cp == NULL) {                           /* skip NULL pointers           */
    *pNext = cp;
    return (cp);
  }
  
  if(strlen(cp)==0){			/* skip string NULL */
	  *pNext = NULL;
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
static void dot_format (uint64_t val, char *sp) {

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
  
  if(k == 0){
	  return;
  }
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