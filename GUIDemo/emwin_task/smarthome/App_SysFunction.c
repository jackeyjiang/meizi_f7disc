/*
*********************************************************************************************************
*	                                  
*	ģ������ : GUI�����ϵͳ����
*	�ļ����� : App_SysFunction.c
*	��    �� : V1.1
*	˵    �� : ͼƬ��ʾ�ͱ����API
*	�޸ļ�¼ :
*		�汾��    ����          ����         ˵��
*		V1.0    2013-03-26    Eric2013       �׷�
*       V1.1    2014-05-23    Eric2013       ɾ�����ļ��ж���ĺ�����ֻ������ͼ
*
*********************************************************************************************************
*/
//#include "includes.h"
#include "stdint.h"
#include "MainTask.h"
#if 0
/*
*********************************************************************************************************
*	                                         ����SD��
*********************************************************************************************************
*/
FRESULT result;
FIL file;
FIL FileSave;   //ר������ͼƬ�ı���
FILINFO finfo;
DIR DirInf;
UINT bw;
FATFS fs;
FATFS fs_nand;
FATFS fs_usb;


/*
*********************************************************************************************************
*	�� �� ��: _WriteByte2File()
*	����˵��: д�ļ���SD�����������洢����
*	��    �Σ�Data Ҫд�����ݣ� p ָ��FIL���ͱ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void _WriteByte2File(U8 Data, void * p) 
{
	result = f_write (p, &Data, 1, &bw);
}
#endif
/***************************** ���������� www.armfly.com (END OF FILE) *********************************/