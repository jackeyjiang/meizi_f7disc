/**
  ******************************************************************************
  * �ļ�: print_choose.c
  * ����: Jack
  * �汾: V1.0.0
  * ����: ѡ���ļ���ӡ
  ******************************************************************************
  *
  *                  ��Ȩ���� (C): LeiTek (leitek.taobao.com)
  *                                www.leitek.com
  *
  ******************************************************************************
  */
  
/* Includes ------------------------------------------------------------------*/
#include "stdbool.h"
#include "stm32f10x.h"
#include "jack_emwin.h"
#include "jack_button_value.h"
#include "ltk_debug.h"
#include "user_sd.h"
#include "GUI.h"

/** �ⲿ����ͼƬ�ļ�  **/
//extern GUI_CONST_STORAGE GUI_BITMAP bmbutton_pressed;
extern GUI_CONST_STORAGE GUI_BITMAP bmflolder_name;
extern GUI_CONST_STORAGE GUI_BITMAP bmfile_name;
extern GUI_CONST_STORAGE GUI_BITMAP bmfile_up_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmfile_up;
extern GUI_CONST_STORAGE GUI_BITMAP bmfile_down_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmfile_down;
extern GUI_CONST_STORAGE GUI_BITMAP bmfile_ture_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmfile_ture;
extern GUI_CONST_STORAGE GUI_BITMAP bmfile_return_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmfile_return;

extern GUI_CONST_STORAGE GUI_BITMAP bmPrint_image;
extern GUI_CONST_STORAGE GUI_BITMAP bmPrint_pause_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmPrint_pause;
extern GUI_CONST_STORAGE GUI_BITMAP bmPrint_set_dec_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmPrint_set_dec;
extern GUI_CONST_STORAGE GUI_BITMAP bmPrint_set_inc_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmPrint_set_inc;
extern GUI_CONST_STORAGE GUI_BITMAP bmPrint_setup_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmPrint_setup;
extern GUI_CONST_STORAGE GUI_BITMAP bmPrint_start_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmPrint_start;
extern GUI_CONST_STORAGE GUI_BITMAP bmPrint_stop_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmPrint_stop;

/** �ⲿ���ú��� **/
extern void _ShowBMPEx(const char * sFilename);
extern void CreateFileBrower(void);
extern void	setTargetHotendIncDec( int16_t celsius, uint8_t extruder);
extern void	setTargetBedIncDec(int16_t celsius);
extern WM_HWIN CreateStopWarning(void);

/** �ڲ����� **/
static void _cbPrintSetup(WM_MESSAGE* pMsg);

/**
  * �� �� ��: _cbFileScan(WM_MESSAGE* pMsg) 
  * ��    ��: ��ӡ�ļ�ѡ�����
  * ��    ��: pMsg
  * �� �� ֵ: ��
  */
  
void _cbFileScan(WM_MESSAGE* pMsg) 
{
	BUTTON_Handle UpButton,DownButton,ChooseButton,ReturnButton;
	WM_HWIN hWin = pMsg->hWin;
	switch (pMsg->MsgId) 
	{
		case WM_CREATE:
			/* ���þ۽�*/
			WM_SetFocus(hWin);
			/* �����ĸ�ͼƬ��ť */
			UpButton = BUTTON_CreateEx(235,12,74,52,  hWin, WM_CF_SHOW, 0, FILE_BUTTON_UP);
			BUTTON_SetBitmapEx(UpButton,BUTTON_BI_UNPRESSED, &bmfile_up_xg, 0 ,0);

			DownButton = BUTTON_CreateEx(235,67,74,52,  hWin, WM_CF_SHOW, 0, FILE_BUTTON_DOWN);
			BUTTON_SetBitmapEx(DownButton,BUTTON_BI_UNPRESSED, &bmfile_down_xg, 0 ,0);

			ChooseButton = BUTTON_CreateEx(235,122,74,52,  hWin, WM_CF_SHOW, 0, FILE_BUTTON_CHOOSE);
			BUTTON_SetBitmapEx(ChooseButton,BUTTON_BI_UNPRESSED, &bmfile_ture_xg, 0 ,0);

			ReturnButton = BUTTON_CreateEx(235,177,74,52,  hWin, WM_CF_SHOW, 0, FILE_BUTTON_RETURN);
			BUTTON_SetBitmapEx(ReturnButton,BUTTON_BI_UNPRESSED, &bmfile_return_xg, 0 ,0);
        
            /* �ļ����� */
        
            /* ��ʾ�ļ���/�ļ��� ͼ�������� */
            
			break;
		case WM_KEY:
			/* ����ĳ�������͵���ǰ��������Ĵ���*/
            switch (((WM_KEY_INFO*)(pMsg->Data.p))->Key) 
            { 
				case GUI_KEY_ESCAPE:
                    GUI_EndDialog(hWin, 1);
                    break;
				case GUI_KEY_TAB:
					WM_SetFocusOnNextChild(hWin);
					break;
            }
            break;
		case WM_PAINT:
			GUI_SetBkColor(BK_COLOR_2);
            GUI_SetColor(GUI_TRANSPARENT);
			GUI_Clear();
			break;
		case WM_NOTIFY_PARENT:
			if (pMsg->Data.v == WM_NOTIFICATION_RELEASED) 
			{
				int Id = WM_GetId(pMsg->hWinSrc);
				switch (Id) 
				{
					case FILE_BUTTON_UP: //�Ϸ�һҳ
						
						break;
					case FILE_BUTTON_DOWN: //�·�һҳ
					
						break;
					case FILE_BUTTON_CHOOSE:
						_DeleteFrame();
						_CreateFrame(&_cbPrinting);						
						break;
					case FILE_BUTTON_RETREAT:
					
						break;
					case FILE_BUTTON_RETURN:
						_DeleteFrame();
						_CreateFrame(&_cbIndex);						
						break;
				}
			}
			break;
		default:
		WM_DefaultProc(pMsg);
	}
}

/**
  * �� �� ��: _cbPrinting(WM_MESSAGE* pMsg) 
  * ��    ��: �ļ���ӡ����
  * ��    ��: pMsg
  * �� �� ֵ: ��
  */
bool print_status = false; //true:��ͣ false:����
__IO uint64_t print_start_time = 0;    //��ӡ��ʼʱ�� (ms)
__IO uint64_t print_current_time = 0;  //��ǰʱ�� (ms)
__IO uint64_t print_used_time = 0;     //��ʱ�೤ʱ�� (s)
extern GUI_FONT XBF_Font;
void _cbPrinting(WM_MESSAGE* pMsg)
{
	BUTTON_Handle StopButton,StartButton,PauseButton,SetupButton;
    PROGBAR_Handle PrintFileSchedule;
    TEXT_Handle BedTemperatrue,ExtruderTemperatrue,PrintSpeed,UsedTime,RemainTime,FileName;
	WM_HWIN hWin = pMsg->hWin;
    WM_HWIN _DialgWin;
    char text_buffer[20]={0};
    int16_t temp = 0,temp1 = 0;
    uint8_t hours_used,minute_used,second_used = 0;
	switch (pMsg->MsgId) 
	{
		case WM_CREATE:
			/* ���þ۽�*/
			WM_SetFocus(hWin);
			/* ��������ͼƬ��ť �����ƴ�ӡ״̬*/
            StartButton = BUTTON_CreateEx(23,145,94,94,   hWin, WM_CF_SHOW, 0, PRINT_BUTTON_START);
            if(print_status == true){  
                BUTTON_SetBitmapEx(StartButton,BUTTON_BI_UNPRESSED, &bmPrint_start_xg, 0 ,0);
                BUTTON_SetBitmapEx(StartButton,BUTTON_BI_PRESSED, &bmPrint_start, 0 ,0);
            }else{
                BUTTON_SetBitmapEx(StartButton,BUTTON_BI_UNPRESSED, &bmPrint_pause_xg, 0 ,0);
                BUTTON_SetBitmapEx(StartButton,BUTTON_BI_PRESSED, &bmPrint_pause, 0 ,0);
            }
            
			StopButton = BUTTON_CreateEx(116,145,94,94,  hWin, WM_CF_SHOW, 0, PRINT_BUTTON_STOP);
			BUTTON_SetBitmapEx(StopButton,BUTTON_BI_UNPRESSED, &bmPrint_stop_xg, 0 ,0);
            BUTTON_SetBitmapEx(StopButton,BUTTON_BI_PRESSED, &bmPrint_stop, 0 ,0);

			SetupButton = BUTTON_CreateEx(209,145,94,94,   hWin, WM_CF_SHOW, 0, PRINT_BUTTON_SETUP);
			BUTTON_SetBitmapEx(SetupButton,BUTTON_BI_UNPRESSED, &bmPrint_setup_xg, 0 ,0);
            BUTTON_SetBitmapEx(SetupButton,BUTTON_BI_PRESSED, &bmPrint_setup, 0 ,0);
            
            /* ��������ʾ */
            PrintFileSchedule = PROGBAR_CreateEx(23,97,274,32, hWin, WM_CF_SHOW,PROGBAR_CF_HORIZONTAL ,PRINT_SCHEDULE);
            PROGBAR_SetFont(PrintFileSchedule,GUI_FONT_16B_ASCII);
            
            /* �ȴ��¶���ʾ */
            BedTemperatrue = TEXT_CreateEx(68,16,40,20, hWin, WM_CF_SHOW, TEXT_CF_LEFT,BED_CURRENT_TEMPERATURE_TXET,"--/--");
            TEXT_SetFont(BedTemperatrue,GUI_FONT_16B_ASCII);            
            
            /* �������¶���ʾ */
            ExtruderTemperatrue = TEXT_CreateEx(165,16,50,20, hWin, WM_CF_SHOW, TEXT_CF_LEFT,EXTRUDER_CURRENT_TEMPERATURE_TXET,"--/--");
            TEXT_SetFont(ExtruderTemperatrue,GUI_FONT_16B_ASCII);
          
            /* �ٶ���ʾ */
            PrintSpeed = TEXT_CreateEx(280,16,50,20, hWin, WM_CF_SHOW, TEXT_CF_LEFT,PRINT_SPPED_TXET,"100");
            TEXT_SetFont(PrintSpeed,GUI_FONT_16B_ASCII);
  
            /* ��ʱ��ʾ */
            UsedTime = TEXT_CreateEx(80,50,100,20, hWin, WM_CF_SHOW, TEXT_CF_LEFT,USED_TIME_TXET,"--:--:--");
            TEXT_SetFont(UsedTime,GUI_FONT_16B_ASCII);
            
            /* ʣ��ʱ����ʾ */
            RemainTime = TEXT_CreateEx(255,50,100,20, hWin, WM_CF_SHOW, TEXT_CF_LEFT,REMAIN_TIME_TXET,"--:--:--");
            TEXT_SetFont(RemainTime,GUI_FONT_16B_ASCII);
            
			break;
		case WM_KEY:	
			/* ����ĳ�������͵���ǰ��������Ĵ���*/
            switch (((WM_KEY_INFO*)(pMsg->Data.p))->Key) 
            { 
				case GUI_KEY_ESCAPE:
                    GUI_EndDialog(hWin, 1);
                    break;
				case GUI_KEY_TAB:
					WM_SetFocusOnNextChild(hWin);
					break;
            }
		case WM_PAINT:
			GUI_SetBkColor(BK_COLOR_2);
            GUI_SetColor(GUI_TRANSPARENT);
            GUI_Clear();
			GUI_DrawBitmap(&bmPrint_image, 0 , 0);
        
            //�ļ�����ʾ
            GUI_UC_SetEncodeNone();
		    GUI_SetFont(&GUI_FontHZ16);
			GUI_SetBkColor(BK_COLOR_2);
			GUI_SetColor(GUI_BLACK);  
            #if _USE_LFN
            GUI_DispStringHCenterAt(Fs_LongFileName,160,75); 
            #else
            GUI_DispStringHCenterAt(Fs_FileName,160,75); 
            #endif   
            GUI_UC_SetEncodeUTF8();
			break;
		case WM_NOTIFY_PARENT:
			if (pMsg->Data.v == WM_NOTIFICATION_RELEASED) 
			{
				int Id = WM_GetId(pMsg->hWinSrc);
				switch (Id) 
				{
					case PRINT_BUTTON_STOP:
                        _DialgWin = CreateStopWarning();
                        WM_MakeModal(_DialgWin);
						break;
					case PRINT_BUTTON_START:
                        if(print_status == true){
                            /* ��ȡ PRINT_BUTTON_START ��� */
                            StartButton = WM_GetDialogItem(pMsg->hWin, PRINT_BUTTON_START);
                            /* ��ʾ�µİ�ťͼƬ */
                            BUTTON_SetBitmapEx(StartButton,BUTTON_BI_UNPRESSED, &bmPrint_pause_xg, 0 ,0);
                            BUTTON_SetBitmapEx(StartButton,BUTTON_BI_PRESSED, &bmPrint_pause, 0 ,0);
                            /* ���Ĵ�ӡ��ʾ״̬ */
                            print_status = false;
							/* ��������˶� */ 
							printPlay();
                            /* ������ȡSD������ */
                            //sd_print_start();
                            
                        }else{
                            StartButton = WM_GetDialogItem(pMsg->hWin, PRINT_BUTTON_START);                             
                            BUTTON_SetBitmapEx(StartButton,BUTTON_BI_UNPRESSED, &bmPrint_start_xg, 0 ,0);
                            BUTTON_SetBitmapEx(StartButton,BUTTON_BI_PRESSED, &bmPrint_start, 0 ,0);
                            /* ���Ĵ�ӡ��ʾ״̬ */
                            print_status = true;
                            /* ��ͣ��ȡSD������ */
                            sd_print_suspend();
							/* ��ͣ����˶� */ 
							printPause();
                        }
						break;
					case PRINT_BUTTON_SETUP:
						_DeleteFrame();
						_CreateFrame(&_cbPrintSetup);							
						break;

				}
			}
			break;
        case TEMPERATRUE_REPORT:  //�����¶���ʾ��Ϣ��ÿ���޸�һ��
        
            /* ��ȡ BED_CURRENT_TEMPERATURE_TXET ��� */
            BedTemperatrue = WM_GetDialogItem(pMsg->hWin, BED_CURRENT_TEMPERATURE_TXET);
            /* ��ȡ�¶����� */
            temp  = getTemperature(1); 
            temp1 = getTargetTemperature(1); 
            /* ת��Ϊ�ַ��� */
            sprintf(text_buffer,"%02d/%02d",temp,temp1);     
            /* ������������¶���ʾ */
            TEXT_SetText(BedTemperatrue,text_buffer);   
        
            /* ��ȡEXTRUDER_CURRENT_TEMPERATURE_TXET ��� */
            ExtruderTemperatrue = WM_GetDialogItem(pMsg->hWin, EXTRUDER_CURRENT_TEMPERATURE_TXET);
            /* ��ȡ�¶����� */
            temp = getTemperature(0); 
            temp1 = getTargetTemperature(0);
            /* ת��Ϊ�ַ��� */
            sprintf(text_buffer,"%02d/%02d",temp,temp1);  
            /* ������������¶���ʾ */
            TEXT_SetText(ExtruderTemperatrue,text_buffer);
        
            /* ��ȡ PRINT_SCHEDULE ��� */
            PrintFileSchedule = WM_GetDialogItem(pMsg->hWin, PRINT_SCHEDULE); 
            /* ��ȡ ����ֵ  */
            temp = c_sdReader_getPercentDone();
            /* ������������ٷֱ���ʾ */
            PROGBAR_SetValue(PrintFileSchedule,temp);

            /* �Ѿ���ʱ��ʾ ��ʣ��ʱ����ʾ */
            UsedTime  = WM_GetDialogItem(pMsg->hWin, USED_TIME_TXET); 
            print_current_time = GUI_GetTime();
            print_used_time = (print_current_time - print_start_time)/1000;
            hours_used = print_used_time/3600;
            minute_used = (print_used_time - (hours_used*3600))/60;
            second_used =  print_used_time%60;
            /* ת��Ϊ�ַ��� */
            sprintf(text_buffer,"%02d:%02d:%02d",hours_used,minute_used,second_used);  
            /* ������������¶���ʾ */
            TEXT_SetText(UsedTime,text_buffer);
            
            break;
        
		default:
		WM_DefaultProc(pMsg);
	}			
}


/**
  * �� �� ��: _cbPrintSetup(WM_MESSAGE* pMsg) 
  * ��    ��: �ļ���ӡ���ý���
  * ��    ��: pMsg
  * �� �� ֵ: ��
  */
static uint16_t ExtruderTmpSet = 0; //�����������¶ȴ�С
static uint16_t BedTmpSet = 0; //�ȴ������¶ȴ�С
static void _cbPrintSetup(WM_MESSAGE* pMsg)
{
	BUTTON_Handle ExtruderTmpIncButton,ExtruderTmpDecButton,BedTmpIncButton,BedTmpDecButton,\
		FanSpdIncButton,FanSpdDecButton,PrintSpdIncButton,PrintSpdDecButton,ExtruderQtyIncButton,\
		ExtruderQtyDecButton,ExtruderTmpText,BedTmpText,ReturnButton;
	WM_HWIN hWin = pMsg->hWin;
    char text_buffer[20]={0};
    int16_t temp = 0,temp1 = 0;
	switch (pMsg->MsgId) 
	{
		case WM_CREATE:
			/* ���þ۽�*/
			WM_SetFocus(hWin);
			/* �������ͼƬ��ť �����ڴ�ӡ���̵Ķ���ز����ĸ��� */
			ExtruderTmpIncButton = BUTTON_CreateEx(110,27,56,56,  hWin, WM_CF_SHOW, 0, PT_BUTTON_EXTRTMP_INC);
			BUTTON_SetBitmapEx(ExtruderTmpIncButton,BUTTON_BI_UNPRESSED, &bmPrint_set_inc_xg, 0 ,0);
            BUTTON_SetBitmapEx(ExtruderTmpIncButton,BUTTON_BI_PRESSED, &bmPrint_set_inc, 0 ,0);

			ExtruderTmpDecButton = BUTTON_CreateEx(248,27,56,56,  hWin, WM_CF_SHOW, 0, PT_BUTTON_EXTRTMP_DEC);
			BUTTON_SetBitmapEx(ExtruderTmpDecButton,BUTTON_BI_UNPRESSED, &bmPrint_set_dec_xg, 0 ,0);
            BUTTON_SetBitmapEx(ExtruderTmpDecButton,BUTTON_BI_PRESSED, &bmPrint_set_dec, 0 ,0);

			BedTmpIncButton = BUTTON_CreateEx(110,85,56,56,  hWin, WM_CF_SHOW, 0, PT_BUTTON_BEDTMP_INC);
			BUTTON_SetBitmapEx(BedTmpIncButton,BUTTON_BI_UNPRESSED, &bmPrint_set_inc_xg, 0 ,0);
            BUTTON_SetBitmapEx(BedTmpIncButton,BUTTON_BI_PRESSED, &bmPrint_set_inc, 0 ,0);

			BedTmpDecButton = BUTTON_CreateEx(248,85,56,56,  hWin, WM_CF_SHOW, 0, PT_BUTTON_BEDTMP_DEC);
			BUTTON_SetBitmapEx(BedTmpDecButton,BUTTON_BI_UNPRESSED, &bmPrint_set_dec_xg, 0 ,0);
            BUTTON_SetBitmapEx(BedTmpDecButton,BUTTON_BI_PRESSED, &bmPrint_set_dec, 0 ,0);
        
			ReturnButton = BUTTON_CreateEx(118,167,74,52,  hWin, WM_CF_SHOW, 0, PT_BUTTON_RETURN);
			BUTTON_SetBitmapEx(ReturnButton,BUTTON_BI_UNPRESSED, &bmfile_return_xg, 0 ,0); 
            BUTTON_SetBitmapEx(ReturnButton,BUTTON_BI_PRESSED, &bmfile_return, 0 ,0);            
        
            temp  = getTemperature(0);
            temp1 = getTargetTemperature(0);       
            sprintf(text_buffer,"%02d/%02d",temp,temp1);
            ExtruderTmpText = TEXT_CreateEx(160,40,90,30, hWin, WM_CF_SHOW, TEXT_CF_LEFT,EXTRUDER_TARGET_TEMPERATURE_TXET,text_buffer);
            TEXT_SetFont(ExtruderTmpText,&GUI_FontHZ24);
            TEXT_SetTextAlign(ExtruderTmpText,GUI_TA_HCENTER);
        
            temp  = getTemperature(1);
            temp1 = getTargetTemperature(1);    
            sprintf(text_buffer,"%02d/%02d",temp,temp1);   
            BedTmpText = TEXT_CreateEx(160,100,90,30, hWin, WM_CF_SHOW, TEXT_CF_LEFT,BED_TARGET_TEMPERATURE_TXET,text_buffer);
            TEXT_SetFont(BedTmpText,&GUI_FontHZ24);
            TEXT_SetTextAlign(BedTmpText,GUI_TA_HCENTER);
            
            break;
		case WM_KEY:	
			/* ����ĳ�������͵���ǰ��������Ĵ���*/
            switch (((WM_KEY_INFO*)(pMsg->Data.p))->Key) 
            { 
				case GUI_KEY_ESCAPE:
                    GUI_EndDialog(hWin, 1);
                    break;
				case GUI_KEY_TAB:
					WM_SetFocusOnNextChild(hWin);
					break;
            }
		case WM_PAINT:
			GUI_SetBkColor(BK_COLOR_2);
            GUI_SetColor(GUI_TRANSPARENT);
            GUI_Clear();
            /* ʹ���ⲿ���� */
            GUI_UC_SetEncodeNone();
		    GUI_SetFont(&GUI_FontHZ24);
			GUI_SetBkColor(BK_COLOR_2);
			GUI_SetColor(GUI_BLACK);
            GUI_DispStringAt("��ͷ�¶�:",6,40); 
            GUI_DispStringAt("�ȴ��¶�:",6,100); 
            GUI_UC_SetEncodeUTF8();
			break;
		case WM_NOTIFY_PARENT:
			if (pMsg->Data.v == WM_NOTIFICATION_RELEASED) 
			{
				int Id = WM_GetId(pMsg->hWinSrc);
				switch (Id) 
				{
					case PT_BUTTON_EXTRTMP_INC:
                        setTargetHotendIncDec(5,0);
                        ExtruderTmpText = WM_GetDialogItem(pMsg->hWin, EXTRUDER_TARGET_TEMPERATURE_TXET); 
                        temp  = getTemperature(0);
                        temp1 = getTargetTemperature(0);       
                        sprintf(text_buffer,"%02d/%02d",temp,temp1);     
                        TEXT_SetText(ExtruderTmpText,text_buffer);
                        TEXT_SetTextAlign(ExtruderTmpText,GUI_TA_HCENTER);                    
						break;
					case PT_BUTTON_EXTRTMP_DEC:
                        setTargetHotendIncDec(-5,0);
                        ExtruderTmpText = WM_GetDialogItem(pMsg->hWin, EXTRUDER_TARGET_TEMPERATURE_TXET);    
                        temp  = getTemperature(0);
                        temp1 = getTargetTemperature(0);       
                        sprintf(text_buffer,"%02d/%02d",temp,temp1);     
                        TEXT_SetText(ExtruderTmpText,text_buffer);                   
                        TEXT_SetTextAlign(ExtruderTmpText,GUI_TA_HCENTER);
						break;
					case PT_BUTTON_BEDTMP_INC:
                        setTargetBedIncDec(5);
                        BedTmpText = WM_GetDialogItem(pMsg->hWin, BED_TARGET_TEMPERATURE_TXET);    
                        temp  = getTemperature(1);
                        temp1 = getTargetTemperature(1);       
                        sprintf(text_buffer,"%02d/%02d",temp,temp1);   
                        TEXT_SetText(BedTmpText,text_buffer);  
                        TEXT_SetTextAlign(BedTmpText,GUI_TA_HCENTER);
						break;						
					case PT_BUTTON_BEDTMP_DEC:
                        setTargetBedIncDec(-5);
                        BedTmpText = WM_GetDialogItem(pMsg->hWin, BED_TARGET_TEMPERATURE_TXET);    
                        temp  = getTemperature(1);
                        temp1 = getTargetTemperature(1);       
                        sprintf(text_buffer,"%02d/%02d",temp,temp1);      
                        TEXT_SetText(BedTmpText,text_buffer);  
                        TEXT_SetTextAlign(BedTmpText,GUI_TA_HCENTER);
						break;
					case PT_BUTTON_FANSPD_INC:
						break;						
					case PT_BUTTON_FANSPD_DEC:
						break;
					case PT_BUTTON_EXTRSPD_INC:
						break;						
					case PT_BUTTON_EXTRSPD_DEC:
						break;
					case PT_BUTTON_EXTRQTY_INC:
						break;						
					case PT_BUTTON_EXTRQTY_DEC:
						break;
					case PT_BUTTON_RETURN:
						_DeleteFrame();
						_CreateFrame(&_cbPrinting);							
						break;
				}
			}
			break;
        case TEMPERATRUE_REPORT:  //�����¶���ʾ��Ϣ��ÿ���޸�һ��
        
            /* ��ȡ BED_TARGET_TEMPERATURE_TXET ��� */
            BedTmpText = WM_GetDialogItem(pMsg->hWin, BED_TARGET_TEMPERATURE_TXET);
            /* ��ȡ�¶����� */
            temp  = getTemperature(1); 
            temp1 = getTargetTemperature(1); 
            /* ת��Ϊ�ַ��� */
            sprintf(text_buffer,"%02d/%02d",temp,temp1);     
            /* ������������¶���ʾ */
            TEXT_SetText(BedTmpText,text_buffer);   
        
            /* ��ȡEXTRUDER_TARGET_TEMPERATURE_TXET ��� */
            ExtruderTmpText = WM_GetDialogItem(pMsg->hWin, EXTRUDER_TARGET_TEMPERATURE_TXET);
            /* ��ȡ�¶����� */
            temp = getTemperature(0); 
            temp1 = getTargetTemperature(0);
            /* ת��Ϊ�ַ��� */
            sprintf(text_buffer,"%02d/%02d",temp,temp1);  
            /* ������������¶���ʾ */
            TEXT_SetText(ExtruderTmpText,text_buffer);
            break;
		default:
		WM_DefaultProc(pMsg);
	}
}
