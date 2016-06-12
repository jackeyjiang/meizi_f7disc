/**
  ******************************************************************************
  * 文件: filelist.h
  * 作者: LeiTek (leitek.taobao.com)
  * 版本: V1.0.0
  * 描述: SPI flash 中间件头文件
  ******************************************************************************
  *
  *                  版权所有 (C), LeiTek (leitek.taobao.com)
  *                                www.leitek.com
  *
  ******************************************************************************
  */
  
/* 防止递归包含该头文件 ------------------------------------------------------*/
#ifndef __FILELIST_H
#define __FILELIST_H

#ifdef __cplusplus
 extern "C" {
#endif 

#include "stdint.h"
     
#define _MAX_PATH_LENGTH  256
#define _MAX_NAME_LENGTH  64
#define _MAX_FILE_CNT	  64
#define _MAX_FILE_ATTR    8
#define _MAX_FILE_EXT     8
     
typedef struct{
    char  fileName[_MAX_NAME_LENGTH];
    uint64_t fileSize;
    char  fileAttribe[_MAX_FILE_ATTR];
    char  fileExt[_MAX_FILE_EXT];
    char  flag;
}FILE_INFO_STRUCT;
     
typedef struct{
    char currentFloderPath[_MAX_PATH_LENGTH];
    char topFloderPath[_MAX_PATH_LENGTH]; //有其他办法处理，可以不用这个
    FILE_INFO_STRUCT fileInfo[_MAX_FILE_CNT]; 
	int fileCnt;
}FILE_LIST_STRUCT;
     
     
#ifdef __cplusplus
}
#endif

#endif /* __LTK_SPI_FLASH_H */

/****************************** leitek.taobao.com *****************************/
