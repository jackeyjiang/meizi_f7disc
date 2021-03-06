/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.30                          *
*        Compiled Jul  1 2015, 10:50:32                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
#include "stdbool.h"
#include "../MainTask.h"
// USER END

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0 (GUI_ID_USER + 0x00)
#define ID_BUTTON_0 (GUI_ID_USER + 0x01)
#define ID_SLIDER_0 (GUI_ID_USER + 0x02)
#define ID_TEXT_0 (GUI_ID_USER + 0x03)
#define ID_SLIDER_1 (GUI_ID_USER + 0x04)
#define ID_TEXT_1 (GUI_ID_USER + 0x05)
#define ID_BUTTON_1 (GUI_ID_USER + 0x06)
#define ID_BUTTON_2 (GUI_ID_USER + 0x07)
#define ID_BUTTON_3 (GUI_ID_USER + 0x08)

// USER START (Optionally insert additional defines)
extern GUI_CONST_STORAGE GUI_BITMAP bmnext;
extern GUI_CONST_STORAGE GUI_BITMAP bmon_off;
extern GUI_CONST_STORAGE GUI_BITMAP bmreturn;
extern GUI_CONST_STORAGE GUI_BITMAP bmupon;
extern GUI_CONST_STORAGE GUI_BITMAP bmnext_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmon_off_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmreturn_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmupon_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmlight_bulb_on;
extern GUI_CONST_STORAGE GUI_BITMAP bmlight_bulb_off;
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
	{ WINDOW_CreateIndirect, "LigthControl", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "RETURN", ID_BUTTON_0, 400, 0, 80, 80, 0, 0x0, 0 },
	{ SLIDER_CreateIndirect, "Slider", ID_SLIDER_0, 100, 80,  280, 35, 0, 0x0, 0 },
	{ TEXT_CreateIndirect,   "light",  ID_TEXT_0,   30, 90,   60, 30, 0, 0x0, 0 },
	{ SLIDER_CreateIndirect, "Slider", ID_SLIDER_1, 100, 150, 280, 35, 0, 0x0, 0 },
	{ TEXT_CreateIndirect,   "Color",  ID_TEXT_1,   30, 160,  60, 30, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "ON/OFF", ID_BUTTON_1, 400,192, 80, 80, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "UPON", ID_BUTTON_2, 0  ,0  , 80, 80, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "NEXT", ID_BUTTON_3, 0  ,192, 80, 80, 0, 0x0, 0 },
	// USER START (Optionally insert additional widgets)
	// USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
static int BUTTON_DrawSkin(const WIDGET_ITEM_DRAW_INFO *pDrawItemInfo);
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static bool light_state = false;
static void _cbDialog(WM_MESSAGE * pMsg) {
	int NCode;
	int Id;
	// USER START (Optionally insert additional variables)
	WM_HWIN hItem;
	WM_HWIN hWin = pMsg->hWin;
	// USER END

	switch (pMsg->MsgId) {
		case WM_PAINT:
		GUI_SetColor(GUI_WHITE);
		GUI_SetBkColor(BACK_COLOR_0);
		GUI_Clear();
		//GUI_DrawBitmapEx(&bmlight_bulb,112,8,240,136,1,1);
		if( light_state )
			GUI_DrawBitmap(&bmlight_bulb_on,112,8);
		else 
			GUI_DrawBitmap(&bmlight_bulb_off,112,8);
		break;

		case WM_INIT_DIALOG:
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
		BUTTON_SetBitmapEx(hItem,BUTTON_BI_UNPRESSED,&bmreturn,0,0);
		BUTTON_SetBitmapEx(hItem,BUTTON_BI_PRESSED,&bmreturn_xg,0,0);
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
		BUTTON_SetBitmapEx(hItem,BUTTON_BI_UNPRESSED,&bmon_off,0,0);
		BUTTON_SetBitmapEx(hItem,BUTTON_BI_PRESSED,&bmon_off_xg,0,0);	
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
		BUTTON_SetBitmapEx(hItem,BUTTON_BI_UNPRESSED,&bmupon,0,0);
		BUTTON_SetBitmapEx(hItem,BUTTON_BI_PRESSED,&bmupon_xg,0,0);	
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
		BUTTON_SetBitmapEx(hItem,BUTTON_BI_UNPRESSED,&bmnext,0,0);
		BUTTON_SetBitmapEx(hItem,BUTTON_BI_PRESSED,&bmnext_xg,0,0);	
		
		break;

		case WM_NOTIFY_PARENT:
		Id    = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch(Id) 
		{
			case ID_BUTTON_0: // Notifications sent by 'Button'
			switch(NCode) 
			{
				case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				GUI_EndDialog(hWin, 0);
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
			case ID_SLIDER_0: // Notifications sent by 'Slider'
			switch(NCode) 
			{
				case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				case WM_NOTIFICATION_VALUE_CHANGED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			// USER START (Optionally insert additional code for further notification handling)
			// USER END
			}
			break;
			case ID_SLIDER_1: // Notifications sent by 'Slider'
			switch(NCode) 
			{
				case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				case WM_NOTIFICATION_VALUE_CHANGED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
			case ID_BUTTON_1: // Notifications sent by 'ON/OFF'
			switch(NCode) 
			{
				case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				light_state = !light_state;
				WM_Paint(hWin); //重绘窗口
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
			case ID_BUTTON_2: // Notifications sent by 'Button'
			switch(NCode) 
			{
				case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
			case ID_BUTTON_3: // Notifications sent by 'Button'
			switch(NCode) 
			{
				case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
			// USER START (Optionally insert additional code for further Ids)
			// USER END
		}
		break;
		// USER START (Optionally insert additional message handling)
		// USER END
		default:
		WM_DefaultProc(pMsg);
		break;
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
*       CreateLigthControl
*/
WM_HWIN CreateLigthControl(void);
WM_HWIN CreateLigthControl(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)
/*
*********************************************************************************************************
*	函 数 名: MainTask
*	功能说明: 主函数
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
static int BUTTON_DrawSkin(const WIDGET_ITEM_DRAW_INFO *pDrawItemInfo)
{
	GUI_RECT GUI_Rect;
    switch(pDrawItemInfo->Cmd)
    {
		case WIDGET_ITEM_DRAW_TEXT:
		GUI_SetColor(GUI_BLACK);
		switch(WM_GetId(pDrawItemInfo->hWin)) 
		{
			if (BUTTON_IsPressed(pDrawItemInfo->hWin)) {
				//GUI_SetColor(GUI_MAKE_TRANS(GUI_YELLOW));
				
			} else {
				GUI_SetColor(GUI_BLACK);
			}
			GUI_AA_DrawRoundedRect(pDrawItemInfo->x0 -1 , pDrawItemInfo->y0 -1, pDrawItemInfo->x1 +1, pDrawItemInfo->y1 +1, 7);
			/*if (_Halt) {
			pBm = &bmplay;
			} else {
			pBm = &bmstop;
			}
			GUI_DrawBitmap(pBm, ((pDrawItemInfo->x1 - pDrawItemInfo->x0) - pBm->XSize) / 2 + 1, ((pDrawItemInfo->y1 - pDrawItemInfo->y0) - pBm->YSize) / 2 + 1);
			*/
		}break;	
		#if 0
        case WIDGET_ITEM_DRAW_BACKGROUND:{
//			GUI_Rect.x0 = pDrawItemInfo->x0;
//			GUI_Rect.y0 = pDrawItemInfo->y0;
//			GUI_Rect.x1 = pDrawItemInfo->x1;
//			GUI_Rect.y1 = pDrawItemInfo->y1;
//			GUI_DrawArc
		    //
			// Windows8 style flat buttons
			//
		  if (BUTTON_IsPressed(pDrawItemInfo->hWin)) {      
			GUI_SetColor(0xA8A851);
			GUI_AA_DisableHiRes();
			GUI_AA_FillRoundedRect(pDrawItemInfo->x0 -1 , pDrawItemInfo->y0 -1, pDrawItemInfo->x1 +1, pDrawItemInfo->y1 +1, 1);
		  } else {
			GUI_SetColor(GUI_BLACK);
			GUI_AA_DisableHiRes();
			GUI_AA_DrawRoundedRect(pDrawItemInfo->x0 -1 , pDrawItemInfo->y0 -1, pDrawItemInfo->x1 +1, pDrawItemInfo->y1 +1, 1);
		  }
        }break;
		#endif
//        case WIDGET_ITEM_CREATE:

//        break;
        default:
            return BUTTON_DrawSkinFlex(pDrawItemInfo);
    }
    return 0;
}
// USER END

/*************************** End of file ****************************/
