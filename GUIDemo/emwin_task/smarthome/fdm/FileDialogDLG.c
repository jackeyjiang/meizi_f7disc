/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.28                          *
*        Compiled Jan 30 2015, 16:41:06                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
#include "filelist.h"
#include "string.h"
#include "stdio.h"
#include "melzi.h"
// USER END

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define LEN_ITEM_TEXT _MAX_PATH_LENGTH

#define ID_FRAMEWIN_0 (GUI_ID_USER + 0x00)
#define ID_LISTVIEW_0 (GUI_ID_USER + 0x01)
#define ID_DROPDOWN_0 (GUI_ID_USER + 0x02)
#define ID_BUTTON_0 (GUI_ID_USER + 0x03)
#define ID_BUTTON_1 (GUI_ID_USER + 0x04)
#define ID_BUTTON_2 (GUI_ID_USER + 0x05)


// USER START (Optionally insert additional defines)
typedef struct {
	U32 Row;
	U32 Col;
} CELL_EDIT_ORG;
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
static char * _aTable_1[][4] = {
	{ "623499-0010001", "1", "Item 1","Item 1" },
	{ "623499-0010002", "2", "Item 2","Item 1" },
	{ "623499-0010003", "3", "Item 3","Item 1" },
	{ "623499-0010004", "4", "Item 4","Item 1" },
	{ "623499-0010005", "5", "Item 5","Item 1" },
	{ "623499-0010006", "6", "Item 6","Item 1" },
	{ "623499-0010007", "7", "Item 7","Item 1" },
	{ "623499-0010008", "8", "Item 8","Item 1" },
};
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
	{ FRAMEWIN_CreateIndirect, "FileDialog", ID_FRAMEWIN_0, 0, 0, 480, 272, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Top",			ID_BUTTON_0, 230, 10, 55, 20, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "True",			ID_BUTTON_2, 300, 10, 55, 20, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Close",			ID_BUTTON_1, 380, 10, 80, 20, 0, 0x0, 0 },
	{ DROPDOWN_CreateIndirect, "Dropdown",  ID_DROPDOWN_0, 10, 10, 200, 20, 0, 0x0, 0 },
	{ LISTVIEW_CreateIndirect, "Listview",  ID_LISTVIEW_0, 5, 35, 470, 210, 0, 0x0, 0 },

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
static void _cbCellEdit(WM_MESSAGE * pMsg);

extern WM_HWIN CreatePrinting(void);  
// USER END

/*********************************************************************
*
*       _cbDialog
*/
extern WM_HWIN  hWinInfo; 
extern FILE_LIST_STRUCT fileList;
static void _cbDialog(WM_MESSAGE * pMsg) {
	WM_HWIN hItem;
	int     NCode;
	int     Id;
	int     i,j;
	// USER START (Optionally insert additional variables)
	WM_HWIN hWin = pMsg->hWin;
	SCROLLBAR_Handle       hScrollbar;
	static CELL_EDIT_ORG    CellEditOrg;
	GUI_RECT         ItemRect;
	char             acItemText[LEN_ITEM_TEXT];
	char             acItemDir[LEN_ITEM_TEXT];
	static WM_HWIN   hCellEdit = 0;
	// USER END

	switch (pMsg->MsgId) {
	case WM_INIT_DIALOG:
		//
		// Initialization of 'Listview'
		//
		FRAMEWIN_SetTitleHeight(hWin, 25);
		FRAMEWIN_SetFont(hWin, GUI_FONT_20B_ASCII);
		FRAMEWIN_SetTextAlign(hWin, GUI_TA_CENTER | GUI_TA_VCENTER);

		hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTVIEW_0);
		LISTVIEW_AddColumn(hItem, 200, "Name", GUI_TA_LEFT | GUI_TA_VCENTER);
		LISTVIEW_AddColumn(hItem, 80, "Size", GUI_TA_LEFT | GUI_TA_VCENTER);
		LISTVIEW_AddColumn(hItem, 80, "Type", GUI_TA_LEFT | GUI_TA_VCENTER);
		LISTVIEW_SetGridVis(hItem, 1);
		LISTVIEW_AddColumn(hItem, 80, "Attrib", GUI_TA_LEFT | GUI_TA_VCENTER);
		// USER START (Optionally insert additional code for further widget initialization)
		//读取根目录下所有的文件，存入结构体中，然后再显示
		fill_filelist(fileList.currentFloderPath);
		hItem = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_0);
		DROPDOWN_AddString(hItem,fileList.currentFloderPath);

		hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTVIEW_0);
		hScrollbar = SCROLLBAR_CreateAttached(hItem,SCROLLBAR_CF_VERTICAL);  //创建窗口的子控件
		SCROLLBAR_SetWidth(hScrollbar,18); //设置滚动条宽度为20

		for (i = 0; i < fileList.fileCnt; i++) {	
			LISTVIEW_AddRow(hItem, NULL); 
			LISTVIEW_SetItemText(hItem,0,i,fileList.fileInfo[i].fileName);
			//LISTVIEW_SetItemText(hItem,i,1,fileList.fileInfo[i].fileSize);
			LISTVIEW_SetItemText(hItem,2,i,fileList.fileInfo[i].fileExt);
			LISTVIEW_SetItemText(hItem,3,i,fileList.fileInfo[i].fileAttribe);
		}	
		// USER END
		break;
	case WM_NOTIFY_PARENT:
		Id    = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch(Id) {
		case ID_LISTVIEW_0: // Notifications sent by 'Listview'
			switch(NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				hItem = WM_GetDialogItem(hWin, ID_LISTVIEW_0);
				if (pMsg->hWinSrc == hItem) {
					CellEditOrg.Row = LISTVIEW_GetSel(hItem);
					CellEditOrg.Col = LISTVIEW_GetSelCol(hItem);	
				}   
				// USER END
				break;
			case WM_NOTIFICATION_SEL_CHANGED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			// USER START (Optionally insert additional code for further notification handling)
			// USER END
			}
			break;
		case ID_DROPDOWN_0: // Notifications sent by 'Dropdown'
			switch(NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_SEL_CHANGED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			// USER START (Optionally insert additional code for further notification handling)
			// USER END
			}
			break;
		case ID_BUTTON_0: // Notifications sent by 'Top'
			switch(NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				//strcpy(fileList.currentFloderPath,fileList.topFloderPath);
				char *ptr_font = strchr(fileList.currentFloderPath, '\\');
				char *ptr_next = strrchr(fileList.currentFloderPath, '\\');
				if(strcmp(ptr_font,ptr_next)==0) break;
				else{
					memset(ptr_next,0,strlen(ptr_next));
					ptr_next = strrchr(fileList.currentFloderPath, '\\');
					memset(ptr_next+1,0,strlen(ptr_next)-1);
				}
				printf("fileList.currentFloderPath:%s\n",fileList.currentFloderPath);
				memset(fileList.fileInfo,0,sizeof(fileList.fileInfo));
				fill_filelist(fileList.currentFloderPath);
				hItem = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_0);
				DROPDOWN_DeleteItem(hItem,0);
				DROPDOWN_AddString(hItem,fileList.currentFloderPath);
				hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTVIEW_0);
				LISTVIEW_DeleteAllRows(hItem);
				for (i = 0; i < fileList.fileCnt; i++) {	
					LISTVIEW_AddRow(hItem, NULL); 
					LISTVIEW_SetItemText(hItem,0,i,fileList.fileInfo[i].fileName);
					//LISTVIEW_SetItemText(hItem,i,1,fileList.fileInfo[i].fileSize);
					LISTVIEW_SetItemText(hItem,2,i,fileList.fileInfo[i].fileExt);
					LISTVIEW_SetItemText(hItem,3,i,fileList.fileInfo[i].fileAttribe);
				}		
				// USER END
				break;
			// USER START (Optionally insert additional code for further notification handling)
			// USER END
			}
			break;
		case ID_BUTTON_1: // Notifications sent by 'Close'
			switch(NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				memset(fileList.currentFloderPath,0,sizeof(fileList.currentFloderPath));
				GUI_EndDialog(hWin, 0);
				// USER END
				break;
			// USER START (Optionally insert additional code for further notification handling)
			// USER END
			}
			break;
		case ID_BUTTON_2: // Notifications sent by 'True'
			switch(NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				hItem = WM_GetDialogItem(hWin, ID_LISTVIEW_0);
				LISTVIEW_GetItemTextSorted(hItem, 0, CellEditOrg.Row, acItemText, LEN_ITEM_TEXT);
				LISTVIEW_GetItemTextSorted(hItem, 3, CellEditOrg.Row, acItemDir , LEN_ITEM_TEXT);
				if(acItemDir[4]=='D'){  //文件夹
					char *ptr = strrchr(fileList.currentFloderPath, '\\');
					memset(ptr+1,0,strlen(ptr)-1);
					//strcpy(fileList.topFloderPath,fileList.currentFloderPath);
					sprintf(fileList.currentFloderPath,"%s%s\\",fileList.currentFloderPath,acItemText);
					printf("fileList.currentFloderPath:%s,acItemText:%s\n",fileList.currentFloderPath,acItemText);	
					memset(fileList.fileInfo,0,sizeof(fileList.fileInfo));
					//刷新listview 和 Dropdown
					//读取根目录下所有的文件，存入结构体中，然后再显示
					fill_filelist(fileList.currentFloderPath);
					hItem = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_0);
					DROPDOWN_DeleteItem(hItem,0);
					DROPDOWN_AddString(hItem,fileList.currentFloderPath);
					hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTVIEW_0);
					LISTVIEW_DeleteAllRows(hItem);
					
					for (i = 0; i < fileList.fileCnt; i++) {	
						LISTVIEW_AddRow(hItem, NULL); 
						LISTVIEW_SetItemText(hItem,0,i,fileList.fileInfo[i].fileName);
						//LISTVIEW_SetItemText(hItem,i,1,fileList.fileInfo[i].fileSize);
						LISTVIEW_SetItemText(hItem,2,i,fileList.fileInfo[i].fileExt);
						LISTVIEW_SetItemText(hItem,3,i,fileList.fileInfo[i].fileAttribe);
					}		
				}else if(acItemDir[5]=='A'){  //文件名
					printf("acItemText:%s\n",acItemText);
                    GUI_EndDialog(hWin, 0);
                    CreatePrinting();
                    //melzi_start(); //3D 打印机的主程序
				}
				//重绘窗口
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
*       CreateFileDialog
*/
WM_HWIN CreateFileDialog(void);
WM_HWIN CreateFileDialog(void) {
	WM_HWIN hWin;

	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}

// USER START (Optionally insert additional public code)
/*********************************************************************
*
*       _cbCellEdit
*
* Function description
*   Callback function of the EDIT widget which is created above a
*   LISTVIEW cell.
*/
static void _cbCellEdit(WM_MESSAGE * pMsg) {
	CELL_EDIT_ORG   CellEditOrg;
	WM_KEY_INFO   * pKeyInfo;
	WM_HWIN         hList;
	char            acText[LEN_ITEM_TEXT];

	switch (pMsg->MsgId) {
	case WM_KEY:
		pKeyInfo = (WM_KEY_INFO *)pMsg->Data.p;
		if (pKeyInfo->PressedCnt == 0) {
			if (pKeyInfo->Key == GUI_KEY_ENTER) {
				WM_SetFocus(WM_GetParent(pMsg->hWin));
				WM_DeleteWindow(pMsg->hWin);
				break;
			}
		}
		EDIT_Callback(pMsg);
		break;
	case WM_SET_FOCUS:
		if (pMsg->Data.v == 0) {
			WM_DeleteWindow(pMsg->hWin);
		} else {
			EDIT_Callback(pMsg);
		}
		break;
	case WM_DELETE:
		EDIT_GetUserData(pMsg->hWin, &CellEditOrg, sizeof(CELL_EDIT_ORG));
		hList = WM_GetParent(pMsg->hWin);
		EDIT_GetText(pMsg->hWin, acText, LEN_ITEM_TEXT);
		LISTVIEW_SetItemTextSorted(hList, 0, CellEditOrg.Row, acText);
		break;
	default:
		EDIT_Callback(pMsg);
	}
}
// USER END

/*************************** End of file ****************************/
