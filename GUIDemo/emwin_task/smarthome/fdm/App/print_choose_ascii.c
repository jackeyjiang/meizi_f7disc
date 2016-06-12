/**
  ******************************************************************************
  * 文件: print_choose.c
  * 作者: Jack
  * 版本: V1.0.0
  * 描述: 选择文件打印
  ******************************************************************************
  *
  *                  版权所有 (C): LeiTek (leitek.taobao.com)
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

/** 外部引用图片文件  **/
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

/** 外部引用函数 **/
extern void _ShowBMPEx(const char * sFilename);
extern void CreateFileBrower(void);
extern void	setTargetHotendIncDec( int16_t celsius, uint8_t extruder);
extern void	setTargetBedIncDec(int16_t celsius);
extern WM_HWIN CreateStopWarning(void);

/** 内部函数 **/
static void _cbPrintSetup(WM_MESSAGE* pMsg);

/**
  * 函 数 名: _cbFileScan(WM_MESSAGE* pMsg) 
  * 描    述: 打印文件选择界面
  * 参    数: pMsg
  * 返 回 值: 无
  */
  
void _cbFileScan(WM_MESSAGE* pMsg) 
{
	BUTTON_Handle UpButton,DownButton,ChooseButton,ReturnButton;
	WM_HWIN hWin = pMsg->hWin;
	switch (pMsg->MsgId) 
	{
		case WM_CREATE:
			/* 设置聚焦*/
			WM_SetFocus(hWin);
			/* 创建四个图片按钮 */
			UpButton = BUTTON_CreateEx(235,12,74,52,  hWin, WM_CF_SHOW, 0, FILE_BUTTON_UP);
			BUTTON_SetBitmapEx(UpButton,BUTTON_BI_UNPRESSED, &bmfile_up_xg, 0 ,0);

			DownButton = BUTTON_CreateEx(235,67,74,52,  hWin, WM_CF_SHOW, 0, FILE_BUTTON_DOWN);
			BUTTON_SetBitmapEx(DownButton,BUTTON_BI_UNPRESSED, &bmfile_down_xg, 0 ,0);

			ChooseButton = BUTTON_CreateEx(235,122,74,52,  hWin, WM_CF_SHOW, 0, FILE_BUTTON_CHOOSE);
			BUTTON_SetBitmapEx(ChooseButton,BUTTON_BI_UNPRESSED, &bmfile_ture_xg, 0 ,0);

			ReturnButton = BUTTON_CreateEx(235,177,74,52,  hWin, WM_CF_SHOW, 0, FILE_BUTTON_RETURN);
			BUTTON_SetBitmapEx(ReturnButton,BUTTON_BI_UNPRESSED, &bmfile_return_xg, 0 ,0);
        
            /* 文件遍历 */
        
            /* 显示文件夹/文件名 图标与文字 */
            
			break;
		case WM_KEY:
			/* 按下某个键后发送到当前包含焦点的窗口*/
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
					case FILE_BUTTON_UP: //上翻一页
						
						break;
					case FILE_BUTTON_DOWN: //下翻一页
					
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
  * 函 数 名: _cbPrinting(WM_MESSAGE* pMsg) 
  * 描    述: 文件打印界面
  * 参    数: pMsg
  * 返 回 值: 无
  */
bool print_status = false; //true:暂停 false:继续
__IO uint64_t print_start_time = 0;    //打印开始时间 (ms)
__IO uint64_t print_current_time = 0;  //当前时间 (ms)
__IO uint64_t print_used_time = 0;     //用时多长时间 (s)
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
			/* 设置聚焦*/
			WM_SetFocus(hWin);
			/* 创建三个图片按钮 ，控制打印状态*/
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
            
            /* 进度条显示 */
            PrintFileSchedule = PROGBAR_CreateEx(23,97,274,32, hWin, WM_CF_SHOW,PROGBAR_CF_HORIZONTAL ,PRINT_SCHEDULE);
            PROGBAR_SetFont(PrintFileSchedule,GUI_FONT_16B_ASCII);
            
            /* 热床温度显示 */
            BedTemperatrue = TEXT_CreateEx(68,16,40,20, hWin, WM_CF_SHOW, TEXT_CF_LEFT,BED_CURRENT_TEMPERATURE_TXET,"--/--");
            TEXT_SetFont(BedTemperatrue,GUI_FONT_16B_ASCII);            
            
            /* 挤出机温度显示 */
            ExtruderTemperatrue = TEXT_CreateEx(165,16,50,20, hWin, WM_CF_SHOW, TEXT_CF_LEFT,EXTRUDER_CURRENT_TEMPERATURE_TXET,"--/--");
            TEXT_SetFont(ExtruderTemperatrue,GUI_FONT_16B_ASCII);
          
            /* 速度显示 */
            PrintSpeed = TEXT_CreateEx(280,16,50,20, hWin, WM_CF_SHOW, TEXT_CF_LEFT,PRINT_SPPED_TXET,"100");
            TEXT_SetFont(PrintSpeed,GUI_FONT_16B_ASCII);
  
            /* 用时显示 */
            UsedTime = TEXT_CreateEx(80,50,100,20, hWin, WM_CF_SHOW, TEXT_CF_LEFT,USED_TIME_TXET,"--:--:--");
            TEXT_SetFont(UsedTime,GUI_FONT_16B_ASCII);
            
            /* 剩余时间显示 */
            RemainTime = TEXT_CreateEx(255,50,100,20, hWin, WM_CF_SHOW, TEXT_CF_LEFT,REMAIN_TIME_TXET,"--:--:--");
            TEXT_SetFont(RemainTime,GUI_FONT_16B_ASCII);
            
			break;
		case WM_KEY:	
			/* 按下某个键后发送到当前包含焦点的窗口*/
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
        
            //文件名显示
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
                            /* 获取 PRINT_BUTTON_START 句柄 */
                            StartButton = WM_GetDialogItem(pMsg->hWin, PRINT_BUTTON_START);
                            /* 显示新的按钮图片 */
                            BUTTON_SetBitmapEx(StartButton,BUTTON_BI_UNPRESSED, &bmPrint_pause_xg, 0 ,0);
                            BUTTON_SetBitmapEx(StartButton,BUTTON_BI_PRESSED, &bmPrint_pause, 0 ,0);
                            /* 更改打印显示状态 */
                            print_status = false;
							/* 继续电机运动 */ 
							printPlay();
                            /* 继续读取SD卡数据 */
                            //sd_print_start();
                            
                        }else{
                            StartButton = WM_GetDialogItem(pMsg->hWin, PRINT_BUTTON_START);                             
                            BUTTON_SetBitmapEx(StartButton,BUTTON_BI_UNPRESSED, &bmPrint_start_xg, 0 ,0);
                            BUTTON_SetBitmapEx(StartButton,BUTTON_BI_PRESSED, &bmPrint_start, 0 ,0);
                            /* 更改打印显示状态 */
                            print_status = true;
                            /* 暂停读取SD卡数据 */
                            sd_print_suspend();
							/* 暂停电机运动 */ 
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
        case TEMPERATRUE_REPORT:  //处理温度显示信息，每秒修改一次
        
            /* 获取 BED_CURRENT_TEMPERATURE_TXET 句柄 */
            BedTemperatrue = WM_GetDialogItem(pMsg->hWin, BED_CURRENT_TEMPERATURE_TXET);
            /* 获取温度数据 */
            temp  = getTemperature(1); 
            temp1 = getTargetTemperature(1); 
            /* 转换为字符串 */
            sprintf(text_buffer,"%02d/%02d",temp,temp1);     
            /* 输出到挤出机温度显示 */
            TEXT_SetText(BedTemperatrue,text_buffer);   
        
            /* 获取EXTRUDER_CURRENT_TEMPERATURE_TXET 句柄 */
            ExtruderTemperatrue = WM_GetDialogItem(pMsg->hWin, EXTRUDER_CURRENT_TEMPERATURE_TXET);
            /* 获取温度数据 */
            temp = getTemperature(0); 
            temp1 = getTargetTemperature(0);
            /* 转换为字符串 */
            sprintf(text_buffer,"%02d/%02d",temp,temp1);  
            /* 输出到挤出机温度显示 */
            TEXT_SetText(ExtruderTemperatrue,text_buffer);
        
            /* 获取 PRINT_SCHEDULE 句柄 */
            PrintFileSchedule = WM_GetDialogItem(pMsg->hWin, PRINT_SCHEDULE); 
            /* 获取 进度值  */
            temp = c_sdReader_getPercentDone();
            /* 输出到进度条百分比显示 */
            PROGBAR_SetValue(PrintFileSchedule,temp);

            /* 已经用时显示 ，剩余时间显示 */
            UsedTime  = WM_GetDialogItem(pMsg->hWin, USED_TIME_TXET); 
            print_current_time = GUI_GetTime();
            print_used_time = (print_current_time - print_start_time)/1000;
            hours_used = print_used_time/3600;
            minute_used = (print_used_time - (hours_used*3600))/60;
            second_used =  print_used_time%60;
            /* 转换为字符串 */
            sprintf(text_buffer,"%02d:%02d:%02d",hours_used,minute_used,second_used);  
            /* 输出到挤出机温度显示 */
            TEXT_SetText(UsedTime,text_buffer);
            
            break;
        
		default:
		WM_DefaultProc(pMsg);
	}			
}


/**
  * 函 数 名: _cbPrintSetup(WM_MESSAGE* pMsg) 
  * 描    述: 文件打印设置界面
  * 参    数: pMsg
  * 返 回 值: 无
  */
static uint16_t ExtruderTmpSet = 0; //挤出机设置温度大小
static uint16_t BedTmpSet = 0; //热床设置温度大小
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
			/* 设置聚焦*/
			WM_SetFocus(hWin);
			/* 创建五个图片按钮 ，用于打印过程的对相关参数的更改 */
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
			/* 按下某个键后发送到当前包含焦点的窗口*/
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
            /* 使用外部字体 */
            GUI_UC_SetEncodeNone();
		    GUI_SetFont(&GUI_FontHZ24);
			GUI_SetBkColor(BK_COLOR_2);
			GUI_SetColor(GUI_BLACK);
            GUI_DispStringAt("喷头温度:",6,40); 
            GUI_DispStringAt("热床温度:",6,100); 
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
        case TEMPERATRUE_REPORT:  //处理温度显示信息，每秒修改一次
        
            /* 获取 BED_TARGET_TEMPERATURE_TXET 句柄 */
            BedTmpText = WM_GetDialogItem(pMsg->hWin, BED_TARGET_TEMPERATURE_TXET);
            /* 获取温度数据 */
            temp  = getTemperature(1); 
            temp1 = getTargetTemperature(1); 
            /* 转换为字符串 */
            sprintf(text_buffer,"%02d/%02d",temp,temp1);     
            /* 输出到挤出机温度显示 */
            TEXT_SetText(BedTmpText,text_buffer);   
        
            /* 获取EXTRUDER_TARGET_TEMPERATURE_TXET 句柄 */
            ExtruderTmpText = WM_GetDialogItem(pMsg->hWin, EXTRUDER_TARGET_TEMPERATURE_TXET);
            /* 获取温度数据 */
            temp = getTemperature(0); 
            temp1 = getTargetTemperature(0);
            /* 转换为字符串 */
            sprintf(text_buffer,"%02d/%02d",temp,temp1);  
            /* 输出到挤出机温度显示 */
            TEXT_SetText(ExtruderTmpText,text_buffer);
            break;
		default:
		WM_DefaultProc(pMsg);
	}
}
