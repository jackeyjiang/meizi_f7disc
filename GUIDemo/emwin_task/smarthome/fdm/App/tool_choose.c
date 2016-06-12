/**
  ******************************************************************************
  * 文件: tool_choose.c
  * 作者: Jack
  * 版本: V1.0.0
  * 描述: 选择工具
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
#include "GUI.h"

/** 外部引用图片文件  **/
extern GUI_CONST_STORAGE GUI_BITMAP bmTool_auto_leveling_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmTool_auto_leveling;
extern GUI_CONST_STORAGE GUI_BITMAP bmTool_manual_leveling_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmTool_manual_leveling;
extern GUI_CONST_STORAGE GUI_BITMAP bmTool_manual_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmTool_manual;
extern GUI_CONST_STORAGE GUI_BITMAP bmSys_return_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmSys_return;
//extern GUI_CONST_STORAGE GUI_BITMAP bmbutton_pressed;

extern GUI_CONST_STORAGE GUI_BITMAP bmleveling_next_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmleveling_next;
extern GUI_CONST_STORAGE GUI_BITMAP bmleveling_return_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmleveling_return;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_level_image;
/** 外部引用程序 **/
extern void _cbManualControl(WM_MESSAGE* pMsg);
/** 内部函数 **/
static void _cbManualLeveling(WM_MESSAGE* pMsg);

/**
  * 函 数 名: _cbToolUse(WM_MESSAGE* pMsg) 
  * 描    述: 工具选择
  * 参    数: pMsg
  * 返 回 值: 无
  */
void _cbToolUse(WM_MESSAGE* pMsg) 
{
	BUTTON_Handle ManualButton,ManuallevelButton,AutolevelButton,ReurnButton;
	WM_HWIN hWin = pMsg->hWin;
	switch (pMsg->MsgId) 
	{
		case WM_CREATE:
            /* 设置聚焦*/
			WM_SetFocus(hWin);
			/* 创建四个图片按钮 */
			ManualButton = BUTTON_CreateEx(11, 44, 94, 94,  hWin, WM_CF_SHOW, 0, TOOL_BUTTON_MANUAL);
			BUTTON_SetBitmapEx(ManualButton,BUTTON_BI_UNPRESSED, &bmTool_manual_xg, 0 ,0);
            BUTTON_SetBitmapEx(ManualButton,BUTTON_BI_PRESSED, &bmTool_manual, 0 ,0); 
        
			AutolevelButton = BUTTON_CreateEx(111, 44, 94, 94,  hWin, WM_CF_SHOW, 0, TOOL_BUTTON_AUTO_LEVELING);
			BUTTON_SetBitmapEx(AutolevelButton,BUTTON_BI_UNPRESSED, &bmTool_auto_leveling_xg, 0 ,0);
            BUTTON_SetBitmapEx(AutolevelButton,BUTTON_BI_PRESSED, &bmTool_auto_leveling, 0 ,0);

			ManuallevelButton = BUTTON_CreateEx(211, 44, 94, 94 ,  hWin, WM_CF_SHOW, 0, TOOL_BUTTON_MANUAL_LEVELING);
			BUTTON_SetBitmapEx(ManuallevelButton,BUTTON_BI_UNPRESSED, &bmTool_manual_leveling_xg, 0 ,0);
            BUTTON_SetBitmapEx(ManuallevelButton,BUTTON_BI_PRESSED, &bmTool_manual_leveling, 0 ,0);

			ReurnButton = BUTTON_CreateEx(116, 170, 94, 52,  hWin, WM_CF_SHOW, 0, TOOL_BUTTON_RETURN);
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
            GUI_SetColor(GUI_TRANSPARENT);
            GUI_Clear();
			break;
		case WM_NOTIFY_PARENT:
			if (pMsg->Data.v == WM_NOTIFICATION_RELEASED) 
			{
				int Id = WM_GetId(pMsg->hWinSrc);
				switch (Id) 
				{
					case TOOL_BUTTON_MANUAL:
						_DeleteFrame();
						_CreateFrame(&_cbManualControl);
						break;
					case TOOL_BUTTON_MANUAL_LEVELING:
						_DeleteFrame();
						_CreateFrame(&_cbManualLeveling);
                        enquecommand("G28\r\n");
						break;
					case TOOL_BUTTON_AUTO_LEVELING:
                        GUI_MessageBox("Sorry,do not support this function!","Sorry",GUI_MESSAGEBOX_CF_MODAL);
						break;
					case TOOL_BUTTON_RETURN:
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
  * 函 数 名: _cbManualLeveling(WM_MESSAGE* pMsg) 
  * 描    述: 手动调平界面
  * 参    数: pMsg
  * 返 回 值: 无
  */
#define MANUAL_LEVELING_CNT 3
static uint8_t ManualLevelingState = 0;
const  uint8_t ManualLeveling[MANUAL_LEVELING_CNT][20]={"G0 X90 Y10 F2400\r\n","G0 X170 Y170 F2400\r\n","G0 X10 Y170 F2400\r\n"};
void _cbManualLeveling(WM_MESSAGE* pMsg) 
{
    uint32_t NCode,Id;
	BUTTON_Handle NextButton,ReurnButton;
	WM_HWIN hWin = pMsg->hWin;
	switch (pMsg->MsgId) 
	{
		case WM_CREATE:
            /* 设置聚焦*/
			WM_SetFocus(hWin);
			/* 创建两个图片按钮 */
			NextButton = BUTTON_CreateEx(66, 140, 82, 56 ,  hWin, WM_CF_SHOW, 0, MANUAL_LEVEL_NEXT);
			BUTTON_SetBitmapEx(NextButton,BUTTON_BI_UNPRESSED, &bmleveling_next_xg, 0 ,0);
            BUTTON_SetBitmapEx(NextButton,BUTTON_BI_PRESSED, &bmleveling_next, 0 ,0);

			ReurnButton = BUTTON_CreateEx(175, 140, 82, 56 ,  hWin, WM_CF_SHOW, 0, MANUAL_LEVEL_RETURN);
			BUTTON_SetBitmapEx(ReurnButton,BUTTON_BI_UNPRESSED, &bmleveling_return_xg, 0 ,0);  
            BUTTON_SetBitmapEx(ReurnButton,BUTTON_BI_PRESSED, &bmleveling_return, 0 ,0);
          
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
            //GUI_DrawBitmap(&bmmanual_level_image, 66 , 55); 
            GUI_SetColor(GUI_WHITE);
            GUI_SetFont(&GUI_FontHZ16);
            GUI_DispStringHCenterAt("Please wait for extruder stop",160,50);
            GUI_DispStringHCenterAt("To do leveling ",160,90);
			break;
		case WM_NOTIFY_PARENT:
            Id = WM_GetId(pMsg->hWinSrc);
            NCode = pMsg->Data.v;
            switch (Id) 
            {
                case MANUAL_LEVEL_NEXT:
                    if(NCode==WM_NOTIFICATION_CLICKED){
                        enquecommand("G90 \r\n");
                        enquecommand(ManualLeveling[ManualLevelingState]);
                        ManualLevelingState = (ManualLevelingState+1)%MANUAL_LEVELING_CNT;
                        //st_synchronize();
                    }else if(NCode==WM_NOTIFICATION_RELEASED){
                       //do nothing
                    }
                    break;
                case MANUAL_LEVEL_RETURN:
                    if(NCode==WM_NOTIFICATION_CLICKED){
                        //do nothing
                    }else if(NCode==WM_NOTIFICATION_RELEASED){
                        GUI_EndDialog(hWin, 0);
                        ManualLevelingState = 0;
                        code_flush();
                        _DeleteFrame();
                        _CreateFrame(&_cbToolUse);
                    }                        
                    break;
            }
			break;
		default:
		WM_DefaultProc(pMsg);
	}

}   


