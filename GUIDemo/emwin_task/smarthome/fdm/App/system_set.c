/**
  ******************************************************************************
  * 文件: system_set.c
  * 作者: Jack
  * 版本: V1.0.0
  * 描述: 系统设置子设置
  ******************************************************************************
  *
  *                  版权所有 (C): LeiTek (leitek.taobao.com)
  *                                www.leitek.com
  *
  ******************************************************************************
  */
  
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "jack_emwin.h"
#include "jack_button_value.h"
#include "ltk_debug.h"
#include "ts_calibrate.h"
#include "GUI.h"
//#include "configuration.h"

/** 外部引用图片文件  **/
extern GUI_CONST_STORAGE GUI_BITMAP bmSys_info_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmSys_info;
extern GUI_CONST_STORAGE GUI_BITMAP bmSys_moniter_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmSys_moniter;
extern GUI_CONST_STORAGE GUI_BITMAP bmSys_default_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmSys_default;
extern GUI_CONST_STORAGE GUI_BITMAP bmSys_return_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmSys_return;
//extern GUI_CONST_STORAGE GUI_BITMAP bmbutton_pressed;

/** 外部引用函数 **/
extern WM_HWIN CreateSetDefaultWaring(void);
/** 内部函数 **/
static void _cbSysInfo(WM_MESSAGE* pMsg);
void _cbChooseFrame(WM_MESSAGE* pMsg);

/**
  * 函 数 名: _cbSysSet(WM_MESSAGE* pMsg) 
  * 描    述: 系统设置界面
  * 参    数: pMsg
  * 返 回 值: 无
  */
WM_HWIN    _hWarningDlg;  
WM_HWIN    _ChooseFrame;  
void _cbSysSet(WM_MESSAGE* pMsg)
{
	int i=0;
	BUTTON_Handle SysInfoButton,MonitCalibraButton,SetDefaultButton,ReturnButton;
	WM_HWIN hWin = pMsg->hWin;
	WM_HWIN hItem;
	switch (pMsg->MsgId) 
	{
		case WM_CREATE:
			/* 设置聚焦*/
			WM_SetFocus(hWin);
			/* 创建四个图片按钮 */
			SysInfoButton = BUTTON_CreateEx(11, 44, 94, 94,  hWin, WM_CF_SHOW, 0, SYS_BUTTON_INFO);
			BUTTON_SetBitmapEx(SysInfoButton,BUTTON_BI_UNPRESSED, &bmSys_info_xg, 0 ,0);
            BUTTON_SetBitmapEx(SysInfoButton,BUTTON_BI_PRESSED, &bmSys_info, 0 ,0);  

			MonitCalibraButton = BUTTON_CreateEx(111, 44, 94, 94, hWin, WM_CF_SHOW, 0, SYS_BUTTON_MONIT);
			BUTTON_SetBitmapEx(MonitCalibraButton,BUTTON_BI_UNPRESSED, &bmSys_moniter_xg, 0 ,0);
            BUTTON_SetBitmapEx(MonitCalibraButton,BUTTON_BI_PRESSED, &bmSys_moniter, 0 ,0); 
        
			SetDefaultButton = BUTTON_CreateEx(211, 44, 94, 94 ,hWin, WM_CF_SHOW, 0, SYS_BUTTON_DEFAULT);
			BUTTON_SetBitmapEx(SetDefaultButton,BUTTON_BI_UNPRESSED, &bmSys_default_xg, 0 ,0);
            BUTTON_SetBitmapEx(SetDefaultButton,BUTTON_BI_PRESSED, &bmSys_default, 0 ,0);   

			ReturnButton = BUTTON_CreateEx(116, 170, 94, 52, hWin, WM_CF_SHOW, 0, SYS_BUTTON_RETURN);
			BUTTON_SetBitmapEx(ReturnButton,BUTTON_BI_UNPRESSED, &bmSys_return_xg, 0 ,0);
            BUTTON_SetBitmapEx(ReturnButton,BUTTON_BI_PRESSED, &bmSys_return, 0 ,0);   

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
			GUI_Clear();
			break;
		case WM_NOTIFY_PARENT:
			if (pMsg->Data.v == WM_NOTIFICATION_RELEASED) 
			{
				int Id = WM_GetId(pMsg->hWinSrc);
				switch (Id) 
				{
					case SYS_BUTTON_INFO:
						_DeleteFrame();
						_CreateFrame(&_cbSysInfo);
						break;
					case SYS_BUTTON_MONIT:				
                        /* ts_calibrate是属于是循环函数,关闭 TIM_TOUCH 避免不要
                           的扫描坐标，以免影响GUI的运行 */
                        TIM_Cmd(TIM_TOUCH,DISABLE); 
                        ts_calibrate();
                        _DeleteFrame();
                        _CreateFrame(&_cbSysSet);
                        TIM_Cmd(TIM_TOUCH,ENABLE);
						break;
					case SYS_BUTTON_WIFI:
					
						break;
					case SYS_BUTTON_DEFAULT:
						/* 增加对话框机制*/
                        _hWarningDlg = CreateSetDefaultWaring();
						break;
					case SYS_BUTTON_LANGUAGE:
					
						break;
					case SYS_BUTTON_RETURN:
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
  * 函 数 名: _cbSysInfo(WM_MESSAGE* pMsg) 
  * 描    述: 显示系统信息
  * 参    数: pMsg
  * 返 回 值: 无
  */
void _cbSysInfo(WM_MESSAGE* pMsg)
{
	BUTTON_Handle ReurnButton;
	WM_HWIN hWin = pMsg->hWin;
	switch (pMsg->MsgId) 
	{
		case WM_CREATE:
            /* 设置聚焦*/
			WM_SetFocus(hWin);
			/* 创建返回按键按钮 */
			ReurnButton = BUTTON_CreateEx(118,174,94, 52,  hWin, WM_CF_SHOW, 0, SYS_INFO_BUTTON_RETURN);
			BUTTON_SetBitmapEx(ReurnButton,BUTTON_BI_UNPRESSED, &bmSys_return_xg, 0 ,0);
            BUTTON_SetBitmapEx(ReurnButton,BUTTON_BI_PRESSED, &bmSys_return, 0 ,0);
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
			GUI_Clear();
            GUI_UC_SetEncodeNone();
			GUI_SetFont(&GUI_FontHZ16);
            GUI_DispStringAt("MODEL:7H3DFDM-FW ",30,20);
            GUI_DispStringAt("VERSION: V0.01",30,50);
            GUI_DispStringAt("SYSINFO: IN TEST  ",30,80);
		    GUI_DispStringAt(__DATE__ " " __TIME__,50,110);
            GUI_UC_SetEncodeUTF8();
			//_ShowBMPEx("1.bmp");
			break;
		case WM_NOTIFY_PARENT:
			if (pMsg->Data.v == WM_NOTIFICATION_RELEASED) 
			{
				int Id = WM_GetId(pMsg->hWinSrc);
				switch (Id) 
				{
					case SYS_INFO_BUTTON_RETURN:
						_DeleteFrame();
						_CreateFrame(&_cbSysSet);						
						break;
				}
			}
			break;
		default:
		WM_DefaultProc(pMsg);
	}
}

/**
  * 函 数 名: _cbChooseFrame(WM_MESSAGE* pMsg) 
  * 描    述: 选择对话框
  * 参    数: pMsg
  * 返 回 值: 无
  */
void _cbChooseFrame(WM_MESSAGE* pMsg)
{
	BUTTON_Handle YesButton,NoButton,CancelButton;
	WM_HWIN hWin = pMsg->hWin;
	switch (pMsg->MsgId) 
	{
		case WM_CREATE:
            /* 设置聚焦*/
			WM_SetFocus(hWin);
			/* 创建返回按键按钮 */
			YesButton = BUTTON_CreateEx(80,80,30, 15,  hWin, WM_CF_SHOW, 0, SYS_INFO_BUTTON_RETURN);
			//BUTTON_SetBitmapEx(YesButton,BUTTON_BI_UNPRESSED, &bmSys_return_xg, 0 ,0);
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
			GUI_Clear();
//			GUI_SetFont(&GUI_FontHZ16);
//          GUI_DispStringAt("firmware version : V0.01",30,30);
//          GUI_DispStringAt("Compile time: ",30,80);
//		    GUI_DispStringAt(STRING_VERSION_CONFIG_H,50,130);
			//_ShowBMPEx("1.bmp");
			break;
		case WM_NOTIFY_PARENT:
			if (pMsg->Data.v == WM_NOTIFICATION_RELEASED) 
			{
				int Id = WM_GetId(pMsg->hWinSrc);
				switch (Id) 
				{
					case SYS_INFO_BUTTON_RETURN:
						_DeleteFrame();
						_CreateFrame(&_cbSysSet);						
						break;
				}
			}
			break;
		default:
		WM_DefaultProc(pMsg);
	}
}