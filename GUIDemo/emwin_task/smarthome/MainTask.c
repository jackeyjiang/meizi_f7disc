/*
*********************************************************************************************************
*	                                  
*	模块名称 : 智能家居界面设计
*	文件名称 : MainTask.c
*	版    本 : V3.0
*	说    明 : 实验内容
*              1. 本实例有两个个值得大家学习的地方:
*                 (1). ICONVIEW控件的使用。
*                 (2). 所有界面支持触摸也支持按键操作。
*              2. 按键K2实现对话框的删除。
*                 按键K3实现ICONVIEW的聚焦。
*				  摇杆UP键实现ICONVIEW选项的上移。
*				  摇杆DOWN键实现ICONVIEW选项的下移。
*				  摇杆LIGHT键实现ICONVIEW选项的左移。
*				  摇杆RIGHT键实现ICONVIEW选项的右移。
*				  摇杆OK键实现对话框的创建。
*                                     
*	修改记录 :
*		版本号    日期          作者          说明
*		V1.0    2014-06-21    Eric2013        首发
*             								 实际测试中发现三个问题，值得大家注意：
*                							 (1). 使用ICONVIEW的WM_NOTIFICATION_CLICKED消息会使得打开一次对话框后，再将其关闭。
*                      							  再次操作ICONVIEW的时候需要点击两次才有效果。
*                 							 (2). 显示游标后，设置显示图片为565格式，GUI_DrawBitmap(&bmButtonLine, 0, 272-44);无法显示了。
*                      							  显示游标后，设置显示图片为32位ARGB格式，GUI_DrawBitmap(&bmButtonLine, 0, 272-44);可以显示。
*                 							 (3). 使能hWinMain窗口使用内存设备后（WM_SetCreateFlags(WM_CF_MEMDEV);），窗口上建立了ICONVIEW.
*                      							  4.3寸可以正常显示，7寸和5寸屏不能，使用外部SRAM作为emWin动态内存或者修改LCDConf.C中的5寸
*                      							  和7寸的输出都是480*272解决，使用原始尺寸将造成图标不显示，向此窗口发送消息造成死机。
*	    V2.0    2015-04-15    Eric2013       1. 升级固件库到V1.5.0
*                                            2. 升级BSP板级支持包 
*                                            3. 升级fatfs到0.11
*                                            4. 升级STemWin到5.26
*                                            5. 更改为新的四点触摸校准算法，并重查编排触摸检测任务
*                                            6. 添加7寸800*480分辨率电容屏支持，添加3.5寸480*320的ILI9488支持。
*                                            7. 重新编排uCOS-III的任务。
*                                            8. V2.0版本使用外部2MB SRAM作为emWin动态内存，V1.0版本存在的问题已经得到解决。
*	    V3.0    2015-12-18  Eric2013         1. 升级BSP板级支持包 
*                                            2. 升级STemWin到5.28
*                                            3. 添加4.3寸和5寸电容屏支持。
*	
*	Copyright (C), 2015-2020, 安富莱电子 www.armfly.com
*
*********************************************************************************************************
*/
//#include "includes.h"
#include "stdint.h"
#include "MainTask.h"


/*
*********************************************************************************************************
*                                       引用外部定义
*********************************************************************************************************
*/ 
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYahei;
extern GUI_CONST_STORAGE GUI_BITMAP bmTopLine;
extern GUI_CONST_STORAGE GUI_BITMAP bma;
extern GUI_CONST_STORAGE GUI_BITMAP bmb;
extern GUI_CONST_STORAGE GUI_BITMAP bmc;
extern GUI_CONST_STORAGE GUI_BITMAP bmd;
extern GUI_CONST_STORAGE GUI_BITMAP bme;
extern GUI_CONST_STORAGE GUI_BITMAP bmf;
extern GUI_CONST_STORAGE GUI_BITMAP bmg;
extern GUI_CONST_STORAGE GUI_BITMAP bmh;
extern GUI_CONST_STORAGE GUI_BITMAP bmi;
extern GUI_CONST_STORAGE GUI_BITMAP bmj;
extern GUI_CONST_STORAGE GUI_BITMAP bmButtonLine;

extern GUI_CONST_STORAGE GUI_BITMAP bmsmart_home_04;
extern GUI_CONST_STORAGE GUI_BITMAP bmsmart_home_04_Press;

/*
*********************************************************************************************************
*                                      变量和数组
*********************************************************************************************************
*/ 
WM_HWIN  hWinInfo;   /* 通过ICONVIEW所打开窗口的句柄 */
WM_HWIN  hWinICON;   /* ICONVIEW控件句柄 */
WM_HWIN  hWinMain;   /* 主窗口句柄, ICONVIEW控件建立在这个窗口上面 */
uint8_t	s_ucSelIconIndex = 0;	/* 选择的ICON，默认不选择任何 */

/* 用于桌面ICONVIEW图标的创建 */
typedef struct 
{
	const GUI_BITMAP * pBitmap;
	const char       * pText;
} BITMAP_ITEM;

/* 用于桌面ICONVIEW图标的创建 */
static const BITMAP_ITEM _aBitmapItem[] = 
{
	{&bma,    "视频监控 "},
	{&bmb,    "灯光控制 "},
	{&bmc,    "智能门窗 "},
	{&bmd,    "电器控制 "},

	{&bme,    "信息查询 "},
	{&bmf,    "安防报警 "},
	{&bmg,    "背景音乐 "},
	{&bmh,    "情景模式 "},

	{&bmi,    "定时管理 "},
	{&bmj,    "系统设置 "},
};

/*
*********************************************************************************************************
*                                     宏定义
*********************************************************************************************************
*/ 
#define ID_WINDOW_0    (GUI_ID_USER + 0x00)
#define ID_FRAMEWIN_0  (GUI_ID_USER + 0x01)
#define ID_GRAPH_0     (GUI_ID_USER + 0x02)
#define ID_TEXT_0      (GUI_ID_USER + 0x03)
#define ID_TEXT_1      (GUI_ID_USER + 0x04)
#define ID_TEXT_2      (GUI_ID_USER + 0x05)
#define ID_TEXT_3      (GUI_ID_USER + 0x06)
#define ID_TEXT_4      (GUI_ID_USER + 0x07)
#define ID_TEXT_5      (GUI_ID_USER + 0x08)
#define ID_TEXT_6      (GUI_ID_USER + 0x09)
#define ID_TEXT_7      (GUI_ID_USER + 0x0A)
#define ID_TEXT_8      (GUI_ID_USER + 0x0B)
#define ID_TEXT_9      (GUI_ID_USER + 0x0C)
#define ID_TEXT_10     (GUI_ID_USER + 0x0D)

#define ID_BUTTON_0    (GUI_ID_USER + 0x10)
#define ID_BUTTON_1    (GUI_ID_USER + 0x11)
#define ID_BUTTON_2    (GUI_ID_USER + 0x12)
#define ID_BUTTON_3    (GUI_ID_USER + 0x13)
#define ID_BUTTON_4    (GUI_ID_USER + 0x14)
#define ID_BUTTON_5    (GUI_ID_USER + 0x15)
#define ID_BUTTON_6    (GUI_ID_USER + 0x16)
#define ID_BUTTON_7    (GUI_ID_USER + 0x17)
#define ID_BUTTON_8    (GUI_ID_USER + 0x18)
#define ID_BUTTON_9    (GUI_ID_USER + 0x19)

#define ID_TimerTime    1

/*
*********************************************************************************************************
*                                     对话框GUI_WIDGET_CREATE_INFO类型数组
*********************************************************************************************************
*/ 
static const GUI_WIDGET_CREATE_INFO _aDialogCreate1[] = {
    { FRAMEWIN_CreateIndirect,  "Caption",           0,                       0,  0,  480,272,0,0},
    { SLIDER_CreateIndirect,     NULL,               GUI_ID_SLIDER0,          115,56, 248,46, 0,0},
    { BUTTON_CreateIndirect,    "BUTTON0",           GUI_ID_BUTTON0,          115,143,248,32, 0,0}
};

/*
*********************************************************************************************************
*	函 数 名: InitDialog1
*	功能说明: 回调函数中的控件初始化消息
*	形    参：pMsg 指针参数            
*	返 回 值: 无
*********************************************************************************************************
*/
void InitDialog1(WM_MESSAGE * pMsg)
{
    WM_HWIN hWin = pMsg->hWin;
    //
    //FRAMEWIN
    //
	FRAMEWIN_SetFont(hWin,&GUI_FontYahei);
	FRAMEWIN_SetText(hWin, _aBitmapItem[s_ucSelIconIndex].pText);
    FRAMEWIN_SetTextAlign(hWin,GUI_TA_VCENTER|GUI_TA_CENTER);
    FRAMEWIN_AddCloseButton(hWin, FRAMEWIN_BUTTON_RIGHT, 0);
    FRAMEWIN_AddMaxButton(hWin, FRAMEWIN_BUTTON_RIGHT, 1);
    FRAMEWIN_AddMinButton(hWin, FRAMEWIN_BUTTON_RIGHT, 2);
    FRAMEWIN_SetTitleHeight(hWin,28);
}

/*
*********************************************************************************************************
*	函 数 名: _cbCallback1
*	功能说明: 回调函数
*	形    参：pMsg 指针参数            
*	返 回 值: 无
*********************************************************************************************************
*/
static void _cbCallback1(WM_MESSAGE * pMsg) 
{
    int NCode, Id;
    WM_HWIN hWin = pMsg->hWin;
    switch (pMsg->MsgId) 
    {
        case WM_PAINT:
            break;
		
        case WM_INIT_DIALOG:
            InitDialog1(pMsg);
            break;
		
        case WM_KEY:
            switch (((WM_KEY_INFO*)(pMsg->Data.p))->Key) 
            {
                case GUI_KEY_ESCAPE:
                    GUI_EndDialog(hWin, 1);
                    break;
                case GUI_KEY_ENTER:
                    GUI_EndDialog(hWin, 0);
                    break;
            }
            break;
			
        case WM_NOTIFY_PARENT:
            Id = WM_GetId(pMsg->hWinSrc); 
            NCode = pMsg->Data.v;        
            switch (Id) 
            {
                case GUI_ID_OK:
                    if(NCode==WM_NOTIFICATION_RELEASED)
                        GUI_EndDialog(hWin, 0);
                    break;
                case GUI_ID_CANCEL:
                    if(NCode==WM_NOTIFICATION_RELEASED)
                        GUI_EndDialog(hWin, 0);
                    break;

            }
            break;
			
        default:
            WM_DefaultProc(pMsg);
    }
}

/*
*********************************************************************************************************
*                                     对话框GUI_WIDGET_CREATE_INFO类型数组
*********************************************************************************************************
*/ 
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = 
{
	{ WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Monitor", ID_BUTTON_0, -4,  41, 74, 74, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Calorifier", ID_BUTTON_1, 83,  18, 74, 74, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Lamp", ID_BUTTON_2,170,  41, 74, 74, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Condition", ID_BUTTON_3,235, 105, 74, 74, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Television", ID_BUTTON_4,258, 192, 74, 74, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Profile", ID_BUTTON_5, 83, 193, 74, 74, 0, 0x0, 0 },
};
#if 0
/*
*********************************************************************************************************
*	函 数 名: Caculate_RTC
*	功能说明: 显示RTC时间
*	形    参：pMsg 指针参数            
*	返 回 值: 无
*********************************************************************************************************
*/
extern RTC_TimeTypeDef  RTC_TimeStructure;
extern RTC_InitTypeDef  RTC_InitStructure;
extern RTC_AlarmTypeDef RTC_AlarmStructure;
extern RTC_DateTypeDef  RTC_DateStructure;
static void Caculate_RTC(WM_MESSAGE * pMsg)
{
	  char buf[30];
	  WM_HWIN hWin = pMsg->hWin;

	  RTC_GetTime(RTC_Format_BIN, &RTC_TimeStructure);
	  RTC_GetDate(RTC_Format_BIN, &RTC_DateStructure);

	  sprintf(buf, 
	          "%0.2d:%0.2d:%0.2d", 
			  RTC_TimeStructure.RTC_Hours, 
			  RTC_TimeStructure.RTC_Minutes,
			  RTC_TimeStructure.RTC_Seconds);
	  TEXT_SetText(WM_GetDialogItem(hWin,ID_TEXT_10), buf);
 
	  sprintf(buf, 
	          "20%0.2d/%0.2d/%0.2d", 
			  RTC_DateStructure.RTC_Year, 
			  RTC_DateStructure.RTC_Month, 
			  RTC_DateStructure.RTC_Date);
	  TEXT_SetText(WM_GetDialogItem(hWin,ID_TEXT_9), buf); 			  	          
}
#endif
/*
*********************************************************************************************************
*	函 数 名: _cbDialogInfo
*	功能说明: 主窗口的回调函数
*	形    参：pMsg   参数指针
*	返 回 值: 无
*********************************************************************************************************
*/
static void _cbDialog(WM_MESSAGE * pMsg) 
{
	WM_HWIN hItem;
	WM_MESSAGE pMsgInfo;
	int NCode, Id;

	switch (pMsg->MsgId) 
	{

		case WM_PAINT:
			//GUI_DrawGradientH(0, 44, 240- 1, 272 - 44, 0xdda0dd, 0xe14169);
		    //GUI_DrawGradientH(240, 44, 480-1, 272-44, 0xe14169, 0xdda0dd);
			
			//GUI_DrawBitmap(&bmButtonLine, 0, 272-44);
		    //GUI_DrawBitmap(&bmTopLine, 0, 0);
          //GUI_DrawBitmap(&bmindex_bg, 0 , 0);
            GUI_SetBkColor(GUI_CYAN);
            GUI_Clear();

            //GUI_SetColor(GUI_WHITE);
            //GUI_DrawCircle(120,230,175);

            GUI_SetColor(GUI_BLUE);
            GUI_AA_FillCircle(120, 230, 120);

            GUI_SetColor(GUI_BLACK);
            GUI_AA_FillCircle(120, 230, 115);

            GUI_SetColor(GUI_LIGHTGRAY);
            GUI_AA_FillCircle(120, 230, 62);

            GUI_SetColor(GUI_DARKGRAY);
            GUI_AA_FillCircle(120, 230, 40);
#if 0
            GUI_SetColor(GUI_GRAY);
            GUI_FillCircle(120, 230, 37);

            GUI_SetColor(GUI_GRAY);
            GUI_FillCircle(33,78,37);
            GUI_SetColor(GUI_WHITE);
            GUI_DrawCircle(33,78,37);

            GUI_SetColor(GUI_GRAY);
            GUI_FillCircle(120,55,37);
            GUI_SetColor(GUI_WHITE);
            GUI_DrawCircle(120,55,37);

            GUI_SetColor(GUI_GRAY);
            GUI_FillCircle(207,78,37);
            GUI_SetColor(GUI_WHITE);
            GUI_DrawCircle(207,78,37);

            GUI_SetColor(GUI_GRAY);
            GUI_FillCircle(272,142,37);
            GUI_SetColor(GUI_WHITE);
            GUI_DrawCircle(272,142,37);

            GUI_SetColor(GUI_GRAY);   
            GUI_FillCircle(295,229,37);
            GUI_SetColor(GUI_WHITE);
            GUI_DrawCircle(295,229,37);
#endif		
			break;
		
		case WM_INIT_DIALOG:
			#if 0
			/* 创建文本 */
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
			TEXT_SetTextColor(hItem, GUI_WHITE);
			TEXT_SetFont(hItem, &GUI_FontYahei);
			TEXT_SetText(hItem, " 智能家居STemWin客户端   " );

			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_9);
			TEXT_SetFont(hItem, GUI_FONT_16B_ASCII);
			TEXT_SetTextColor(hItem, 0x00FFFFFF);
			TEXT_SetText(hItem, "2014-06-17");
			
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_10);
			TEXT_SetFont(hItem, GUI_FONT_16B_ASCII);
			TEXT_SetTextColor(hItem, 0x00FFFFFF);
			TEXT_SetText(hItem, "00:00:00");
			#endif
			/* 创建按键 */		
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
			BUTTON_SetBitmapEx(hItem,BUTTON_BI_UNPRESSED,&bmsmart_home_04,12,12);
			BUTTON_SetBitmapEx(hItem,BUTTON_BI_PRESSED,&bmsmart_home_04_Press,12,12);
			
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
			BUTTON_SetBitmapEx(hItem,BUTTON_BI_UNPRESSED,&bmsmart_home_04,12,12);
			BUTTON_SetBitmapEx(hItem,BUTTON_BI_PRESSED,&bmsmart_home_04_Press,12,12);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
			BUTTON_SetBitmapEx(hItem,BUTTON_BI_UNPRESSED,&bmsmart_home_04,12,12);
			BUTTON_SetBitmapEx(hItem,BUTTON_BI_PRESSED,&bmsmart_home_04_Press,12,12);
			
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
			BUTTON_SetBitmapEx(hItem,BUTTON_BI_UNPRESSED,&bmsmart_home_04,12,12);
			BUTTON_SetBitmapEx(hItem,BUTTON_BI_PRESSED,&bmsmart_home_04_Press,12,12);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);
			BUTTON_SetBitmapEx(hItem,BUTTON_BI_UNPRESSED,&bmsmart_home_04,12,12);
			BUTTON_SetBitmapEx(hItem,BUTTON_BI_PRESSED,&bmsmart_home_04_Press,12,12);
			
//			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5);
//			BUTTON_SetBitmapEx(hItem,BUTTON_BI_UNPRESSED,&bmsmart_home_04,12,12);
			GUI_EnableAlpha(0);
			break;
			
		case WM_TIMER:
			/* 显示时间和日期 */
			//Caculate_RTC(pMsg);
			/* 重启定时器 */
			//WM_RestartTimer(pMsg->Data.v, 1000);
			break;
		
		/*  发送按下的消息 */
		case MSG_SetENTER:
			pMsgInfo.MsgId = WM_NOTIFY_PARENT;
			pMsgInfo.hWinSrc = hWinICON;
			pMsgInfo.Data.v = WM_NOTIFICATION_RELEASED;
			WM_SendMessage(pMsg->hWin, &pMsgInfo);	
			break;
		
		/*  设置ICON的聚焦 */
		case MSG_SetICONFocus:
			WM_SetFocus(hWinICON);
			break;
		
		/* 删除通过ICON创建的对话框 */
		case MSG_Delect:
			WM_DeleteWindow(hWinInfo);
			break;
			
		case WM_NOTIFY_PARENT:
			Id    = WM_GetId(pMsg->hWinSrc);      /* Id of widget */
			NCode = pMsg->Data.v;                 /* Notification code */
			switch (Id) 
			{
				/* 点击ICONVIEW上相应的图标，打开相应的窗口 */
				case GUI_ID_ICONVIEW0:
					switch (NCode) 
					{
						case  WM_NOTIFICATION_RELEASED:
							
							s_ucSelIconIndex  = ICONVIEW_GetSel(pMsg->hWinSrc);
						
							switch( ICONVIEW_GetSel(pMsg->hWinSrc))
							{
								/* 视频监控 */
								case 0:
									hWinInfo = GUI_CreateDialogBox(_aDialogCreate1, GUI_COUNTOF(_aDialogCreate1), &_cbCallback1, 0, 0, 0);				
								    break;	
								
								/* 灯光控制 */
								case 1:
									hWinInfo = GUI_CreateDialogBox(_aDialogCreate1, GUI_COUNTOF(_aDialogCreate1), &_cbCallback1, 0, 0, 0);				
									break;	
								
								/* 智能门窗 */
								case 2:
									hWinInfo = GUI_CreateDialogBox(_aDialogCreate1, GUI_COUNTOF(_aDialogCreate1), &_cbCallback1, 0, 0, 0);				
								    break;	
								
								/* 电器控制 */
								case 3:
									hWinInfo = GUI_CreateDialogBox(_aDialogCreate1, GUI_COUNTOF(_aDialogCreate1), &_cbCallback1, 0, 0, 0);				
								    break;
								
								/* 信息查询 */
								case 4:
									hWinInfo = GUI_CreateDialogBox(_aDialogCreate1, GUI_COUNTOF(_aDialogCreate1), &_cbCallback1, 0, 0, 0);				
								    break;	
								
								/* 安防报警 */
								case 5:
									hWinInfo = GUI_CreateDialogBox(_aDialogCreate1, GUI_COUNTOF(_aDialogCreate1), &_cbCallback1, 0, 0, 0);				
								    break;	
								
								/* 背景音乐 */
								case 6:
									hWinInfo = GUI_CreateDialogBox(_aDialogCreate1, GUI_COUNTOF(_aDialogCreate1), &_cbCallback1, 0, 0, 0);				
								    break;	
								
								/* 情景模式 */
								case 7:
									hWinInfo = GUI_CreateDialogBox(_aDialogCreate1, GUI_COUNTOF(_aDialogCreate1), &_cbCallback1, 0, 0, 0);				
								    break;	
								
								/* 定时管理 */
								case 8:
									hWinInfo = GUI_CreateDialogBox(_aDialogCreate1, GUI_COUNTOF(_aDialogCreate1), &_cbCallback1, 0, 0, 0);				
								    break;
								
								/* 系统设置 */
								case 9:
									hWinInfo = GUI_CreateDialogBox(_aDialogCreate1, GUI_COUNTOF(_aDialogCreate1), &_cbCallback1, 0, 0, 0);				
								    break;
								
								default:
									break;
							}	
						 break;
					}
				break;
			}
			break;
			
		default:
			WM_DefaultProc(pMsg);
	}
}

/*
*********************************************************************************************************
*	函 数 名: MainTask
*	功能说明: 主函数
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
BUTTON_SKINFLEX_PROPS Props;
void MainTask(void) 
{


	uint8_t i;
	
	/* 使能所有窗口使用emWin内存设备，包括桌面窗口 */
	WM_SetCreateFlags(WM_CF_MEMDEV);
	
	/* 初始化并创建对话框 */
	GUI_Init();
	WM_SetDesktopColor(GUI_BLUE);
	
	/* 设置皮肤上 */
	FRAMEWIN_SetDefaultSkin(FRAMEWIN_SKIN_FLEX);
	PROGBAR_SetDefaultSkin(PROGBAR_SKIN_FLEX);
	FRAMEWIN_SetDefaultSkin(FRAMEWIN_SKIN_FLEX);
	PROGBAR_SetDefaultSkin(PROGBAR_SKIN_FLEX);
	BUTTON_SetDefaultSkin(BUTTON_SKIN_FLEX);
	CHECKBOX_SetDefaultSkin(CHECKBOX_SKIN_FLEX);
	DROPDOWN_SetDefaultSkin(DROPDOWN_SKIN_FLEX);
	SCROLLBAR_SetDefaultSkin(SCROLLBAR_SKIN_FLEX);
	SLIDER_SetDefaultSkin(SLIDER_SKIN_FLEX);
	HEADER_SetDefaultSkin(HEADER_SKIN_FLEX);
	RADIO_SetDefaultSkin(RADIO_SKIN_FLEX);
	
	/* 换肤函数 */
	BUTTON_GetSkinFlexProps(&Props,BUTTON_SKINFLEX_PI_FOCUSSED);
	Props.aColorFrame[0]=0x007FB13C;
	Props.aColorFrame[1]=0x008FFF8F;
	Props.aColorFrame[2]=0x00FFFFFF;
	Props.Radius = 37;
	BUTTON_SetSkinFlexProps(&Props,BUTTON_SKINFLEX_PI_FOCUSSED);
	
	BUTTON_GetSkinFlexProps(&Props,BUTTON_SKINFLEX_PI_PRESSED);
	Props.aColorFrame[0]=0x007FB13C;
	Props.aColorFrame[1]=0x008FFF8F;
	Props.aColorFrame[2]=GUI_BLUE;
	Props.Radius = 37;
	BUTTON_SetSkinFlexProps(&Props,BUTTON_SKINFLEX_PI_PRESSED);
	
	BUTTON_GetSkinFlexProps(&Props,BUTTON_SKINFLEX_PI_ENABLED);
	Props.aColorFrame[0]=0x007FB13C;
	Props.aColorFrame[1]=0x008FFF8F;
	Props.aColorFrame[2]=0x00FFFFFF;
	Props.Radius = 37;
	BUTTON_SetSkinFlexProps(&Props,BUTTON_SKINFLEX_PI_ENABLED);
		
	/* 使能UTF-8解码用于汉字显示 */
	GUI_UC_SetEncodeUTF8();
	hWinMain = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);   
#if 0
	/*在指定位置创建指定尺寸的ICONVIEW 小工具*/
	hWinICON = ICONVIEW_CreateEx(20,
						     45, 
							 440,
							 200,
	                         hWinMain, 				     
							 WM_CF_SHOW | WM_CF_HASTRANS,     
	                         0,//ICONVIEW_CF_AUTOSCROLLBAR_V, 	
							 GUI_ID_ICONVIEW0,
							 82,
							 80
							 );
	


#if 0
	/* 向ICONVIEW 小工具添加新图标 */
	for (i = 0; i < GUI_COUNTOF(_aBitmapItem); i++) 
	{	
		ICONVIEW_AddBitmapItem(hWinICON, _aBitmapItem[i].pBitmap, _aBitmapItem[i].pText);
	}
#endif	

#if 0
	/* 设置小工具的背景色 32 位颜色值的前8 位可用于alpha混合处理效果*/
	ICONVIEW_SetBkColor(hWinICON, ICONVIEW_CI_SEL, GUI_WHITE | 0x80000000);
	
	/* 设置字体 */
	ICONVIEW_SetFont(hWinICON, &GUI_FontYahei);
	
	/* 设置图标在x 或y 方向上的间距。*/
	ICONVIEW_SetSpace(hWinICON, GUI_COORD_Y, 10);
	
	/* 设置对齐方式 在5.22版本中最新加入的 */
	ICONVIEW_SetIconAlign(hWinICON, ICONVIEW_IA_HCENTER|ICONVIEW_IA_TOP);
#endif

#if 0
	WM_CreateTimer(WM_GetClientWindow(hWinMain),
				   ID_TimerTime,
				   20,
				   0);
#endif
#endif
	while(1)
	{
		GUI_Delay(20);
	}

}

#if 0
#define GUI_MAKE_COLOR(ABGR)  (ABGR)
#define GUI_MAKE_TRANS(Alpha) (Alpha)

static int _DrawSkin_BUTTON(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo) {
  const GUI_BITMAP * pBm;
  switch (pDrawItemInfo->Cmd) {
  case WIDGET_ITEM_DRAW_TEXT:
    GUI_SetColor(GUI_BLACK);
    switch(WM_GetId(pDrawItemInfo->hWin)) {
    case INDEX_BUTTON_SYS:
      if (BUTTON_IsPressed(pDrawItemInfo->hWin)) {
        GUI_SetColor(GUI_MAKE_TRANS(GUI_YELLOW));
      } else {
        GUI_SetColor(GUI_BLACK);
      }
     /*if (_Halt) {
        pBm = &bmplay;
      } else {
        pBm = &bmstop;
      }
      GUI_DrawBitmap(pBm, ((pDrawItemInfo->x1 - pDrawItemInfo->x0) - pBm->XSize) / 2 + 1, ((pDrawItemInfo->y1 - pDrawItemInfo->y0) - pBm->YSize) / 2 + 1);
      */
      break;
    case GUI_ID_NEXT:
      if (BUTTON_IsPressed(pDrawItemInfo->hWin)) {
        GUI_SetColor(GUI_YELLOW);
      } else {
        GUI_SetColor(GUI_BLACK);
      }
      //GUI_DrawBitmap(&bmforward, ((pDrawItemInfo->x1 - pDrawItemInfo->x0) - bmforward.XSize) / 2 + 1, ((pDrawItemInfo->y1 - pDrawItemInfo->y0) - bmforward.YSize) / 2 + 1);
      break;
    }
    break;
  case WIDGET_ITEM_DRAW_BACKGROUND:
    #if 1
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
    #else
      //
      // Glassy buttons
      //
      if (BUTTON_IsPressed(pDrawItemInfo->hWin)) {
        GUI_DrawBitmap(&bmbutton_1, pDrawItemInfo->x0, pDrawItemInfo->y0);
      } else {
        GUI_DrawBitmap(&bmbutton_0, pDrawItemInfo->x0, pDrawItemInfo->y0);
      }
    #endif
    break;
  default:
    //
    // Use the default skinning routine for processing all other commands
    //
    return BUTTON_DrawSkinFlex(pDrawItemInfo);
  }
  return 0;
}
#endif


/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
  