/*
*********************************************************************************************************
*                                     
*   模块名称 : 智能家居界面设计
*   文件名称 : MainTask.c
*   版    本 : V3.0
*   说    明 : 实验内容
*              1. 本实例有两个个值得大家学习的地方:
*                 (1). ICONVIEW控件的使用。
*                 (2). 所有界面支持触摸也支持按键操作。
*              2. 按键K2实现对话框的删除。
*                 按键K3实现ICONVIEW的聚焦。
*                 摇杆UP键实现ICONVIEW选项的上移。
*                 摇杆DOWN键实现ICONVIEW选项的下移。
*                 摇杆LIGHT键实现ICONVIEW选项的左移。
*                 摇杆RIGHT键实现ICONVIEW选项的右移。
*                 摇杆OK键实现对话框的创建。
*                                     
*   修改记录 :
*       版本号    日期          作者          说明
*       V1.0    2014-06-21    Eric2013        首发
*                                            实际测试中发现三个问题，值得大家注意：
*                                            (1). 使用ICONVIEW的WM_NOTIFICATION_CLICKED消息会使得打开一次对话框后，再将其关闭。
*                                                 再次操作ICONVIEW的时候需要点击两次才有效果。
*                                            (2). 显示游标后，设置显示图片为565格式，GUI_DrawBitmap(&bmButtonLine, 0, 272-44);无法显示了。
*                                                 显示游标后，设置显示图片为32位ARGB格式，GUI_DrawBitmap(&bmButtonLine, 0, 272-44);可以显示。
*                                            (3). 使能hWinMain窗口使用内存设备后（WM_SetCreateFlags(WM_CF_MEMDEV);），窗口上建立了ICONVIEW.
*                                                 4.3寸可以正常显示，7寸和5寸屏不能，使用外部SRAM作为emWin动态内存或者修改LCDConf.C中的5寸
*                                                 和7寸的输出都是480*272解决，使用原始尺寸将造成图标不显示，向此窗口发送消息造成死机。
*       V2.0    2015-04-15    Eric2013       1. 升级固件库到V1.5.0
*                                            2. 升级BSP板级支持包 
*                                            3. 升级fatfs到0.11
*                                            4. 升级STemWin到5.26
*                                            5. 更改为新的四点触摸校准算法，并重查编排触摸检测任务
*                                            6. 添加7寸800*480分辨率电容屏支持，添加3.5寸480*320的ILI9488支持。
*                                            7. 重新编排uCOS-III的任务。
*                                            8. V2.0版本使用外部2MB SRAM作为emWin动态内存，V1.0版本存在的问题已经得到解决。
*       V3.0    2015-12-18  Eric2013         1. 升级BSP板级支持包 
*                                            2. 升级STemWin到5.28
*                                            3. 添加4.3寸和5寸电容屏支持。
*   
*   Copyright (C), 2015-2020, 安富莱电子 www.armfly.com
*
*********************************************************************************************************
*/
//#include "includes.h"
#include "stdint.h"
#include "MainTask.h"
#include "filelist.h"


/*
*********************************************************************************************************
*                                       引用外部定义
*********************************************************************************************************
*/ 
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYahei;

extern GUI_CONST_STORAGE GUI_BITMAP bmappliance;
extern GUI_CONST_STORAGE GUI_BITMAP bmcamera;
extern GUI_CONST_STORAGE GUI_BITMAP bmcurtain;
extern GUI_CONST_STORAGE GUI_BITMAP bmdialogue;
extern GUI_CONST_STORAGE GUI_BITMAP bmhome;
extern GUI_CONST_STORAGE GUI_BITMAP bmlight;
extern GUI_CONST_STORAGE GUI_BITMAP bmmicrophone;
extern GUI_CONST_STORAGE GUI_BITMAP bmmusic;
extern GUI_CONST_STORAGE GUI_BITMAP bmsafety;
extern GUI_CONST_STORAGE GUI_BITMAP bmsound;
extern GUI_CONST_STORAGE GUI_BITMAP bmvideo;
extern GUI_CONST_STORAGE GUI_BITMAP bmsmart_home;
extern GUI_CONST_STORAGE GUI_BITMAP bmset;
/*
*********************************************************************************************************
*                                      变量和数组
*********************************************************************************************************
*/ 
WM_HWIN  hWinInfo;   /* 通过ICONVIEW所打开窗口的句柄 */
WM_HWIN  hWinICON;   /* ICONVIEW控件句柄 */
WM_HWIN  hWinMain;   /* 主窗口句柄, ICONVIEW控件建立在这个窗口上面 */
WM_HWIN  hWinWavePage;   /* 温度查询窗口 */
uint8_t s_ucSelIconIndex = 0;   /* 选择的ICON，默认不选择任何 */

/* 用于桌面ICONVIEW图标的创建 */
typedef struct 
{
    const GUI_BITMAP * pBitmap;
    const char       * pText;
} BITMAP_ITEM;

/* 用于桌面ICONVIEW图标的创建 */
static const BITMAP_ITEM _aBitmapItem[] = 
{
    {&bmcamera,    "视频监控 "},
    {&bmlight,     "灯光控制 "},
    {&bmcurtain,   "智能门窗 "},
    {&bmappliance, "电器控制 "},

    {&bmdialogue,  "信息查询 "},
    {&bmsafety,    "安防报警 "},
    {&bmmusic,     "背景音乐 "},
    {&bmset,       "系统设置 "},
};

/*
*********************************************************************************************************
*                                     宏定义
*********************************************************************************************************
*/ 
#define ID_WINDOW_0    (GUI_ID_USER + 0x20)
#define ID_FRAMEWIN_0  (GUI_ID_USER + 0x21)
#define ID_GRAPH_0     (GUI_ID_USER + 0x22)
#define ID_TEXT_0      (GUI_ID_USER + 0x23)
#define ID_TEXT_1      (GUI_ID_USER + 0x24)
#define ID_TEXT_2      (GUI_ID_USER + 0x25)
#define ID_TEXT_3      (GUI_ID_USER + 0x26)
#define ID_TEXT_4      (GUI_ID_USER + 0x27)
#define ID_TEXT_5      (GUI_ID_USER + 0x28)
#define ID_TEXT_6      (GUI_ID_USER + 0x29)
#define ID_TEXT_7      (GUI_ID_USER + 0x2A)
#define ID_TEXT_8      (GUI_ID_USER + 0x2B)
#define ID_TEXT_9      (GUI_ID_USER + 0x2C)
#define ID_TEXT_10     (GUI_ID_USER + 0x2D)

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

/* 用于桌面ICONVIEW子窗口的建立 */
extern WM_HWIN CreateLigthControl(void);
extern WM_HWIN CreateFdm(void);
extern WM_HWIN CreateTemperatureWavePage(void);
extern WM_HWIN CreateListWheelPage(void);
/*
*********************************************************************************************************
*   函 数 名: InitDialog1
*   功能说明: 回调函数中的控件初始化消息
*   形    参：pMsg 指针参数            
*   返 回 值: 无
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
*   函 数 名: _cbCallback1
*   功能说明: 回调函数
*   形    参：pMsg 指针参数            
*   返 回 值: 无
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
//  { TEXT_CreateIndirect, "Text", ID_TEXT_0, 130, 10, 200, 20, 0, 0x64, 0 },
//  { TEXT_CreateIndirect, "Text", ID_TEXT_9,  351, 16, 71, 17, 0, 0x64, 0  },
//  { TEXT_CreateIndirect, "Text", ID_TEXT_10, 424, 16, 57, 20, 0, 0x64, 0 },
};
#if 0
/*
*********************************************************************************************************
*   函 数 名: Caculate_RTC
*   功能说明: 显示RTC时间
*   形    参：pMsg 指针参数            
*   返 回 值: 无
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
*   函 数 名: _cbDialogInfo
*   功能说明: 主窗口的回调函数
*   形    参：pMsg   参数指针
*   返 回 值: 无
*********************************************************************************************************
*/
extern FILE_LIST_STRUCT fileList;
static void _cbDialog(WM_MESSAGE * pMsg) 
{
    WM_HWIN hItem;
    WM_MESSAGE pMsgInfo;
    int NCode, Id;

    switch (pMsg->MsgId) 
    {

        case WM_PAINT:
            GUI_SetColor(GUI_WHITE);
            GUI_SetBkColor(BACK_COLOR_0);
            GUI_Clear();
            break;
        
        case WM_INIT_DIALOG:
            break;
            
        case WM_TIMER:
            /* 显示时间和日期 */
            //Caculate_RTC(pMsg);
            /* 重启定时器 */
            //WM_RestartTimer(pMsg->Data.v, 1000);
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
                            #if 1
                            switch( ICONVIEW_GetSel(pMsg->hWinSrc))
                            {
                                /* 视频监控 */
                                case 0:
                                    hWinInfo = GUI_CreateDialogBox(_aDialogCreate1, GUI_COUNTOF(_aDialogCreate1), &_cbCallback1, 0, 0, 0);              
                                    break;  
                                
                                /* 灯光控制 */
                                case 1:
                                    //hWinInfo = GUI_CreateDialogBox(_aDialogCreate1, GUI_COUNTOF(_aDialogCreate1), &_cbCallback1, 0, 0, 0);    
                                    hWinInfo = CreateLigthControl();    
                                    break;  
                                
                                /* 智能门窗 */
                                case 2:
                                    hWinInfo = GUI_CreateDialogBox(_aDialogCreate1, GUI_COUNTOF(_aDialogCreate1), &_cbCallback1, 0, 0, 0);              
                                    break;  
                                
                                /* 电器控制 */
                                case 3:
                                    //hWinInfo = GUI_CreateDialogBox(_aDialogCreate1, GUI_COUNTOF(_aDialogCreate1), &_cbCallback1, 0, 0, 0);
                                    hWinInfo = CreateFdm();                     
                                    break;
                                
                                /* 信息查询 */
                                case 4:
                                    //hWinInfo = GUI_CreateDialogBox(_aDialogCreate1, GUI_COUNTOF(_aDialogCreate1), &_cbCallback1, 0, 0, 0);                
                                    hWinWavePage = hWinInfo = CreateTemperatureWavePage();
                                    break;  
                                
                                /* 安防报警 */
                                case 5:
                                    hWinInfo = GUI_CreateDialogBox(_aDialogCreate1, GUI_COUNTOF(_aDialogCreate1), &_cbCallback1, 0, 0, 0);              
                                    break;  
                                
                                /* 背景音乐 */
                                case 6:
                                    hWinInfo = GUI_CreateDialogBox(_aDialogCreate1, GUI_COUNTOF(_aDialogCreate1), &_cbCallback1, 0, 0, 0);              
                                    break;  
                                
                                
                                /* 系统设置 */
                                case 7:
                                    hWinInfo = GUI_CreateDialogBox(_aDialogCreate1, GUI_COUNTOF(_aDialogCreate1), &_cbCallback1, 0, 0, 0);              
                                    //hWinInfo = CreateListWheelPage();
                                    break;
                                
                                default:
                                    break;
                            }   
                            #endif
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
*   函 数 名: MainTask
*   功能说明: 主函数
*   形    参：无
*   返 回 值: 无
*********************************************************************************************************
*/
void MainTask(void) 
{
    uint8_t i;
    
    /* 使能所有窗口使用emWin内存设备，包括桌面窗口 */
    WM_SetCreateFlags(WM_CF_MEMDEV);
    
    /* 初始化并创建对话框 */
    GUI_Init();
    //GUI_CURSOR_Show();
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
#if 1       
    /* 使能UTF-8解码用于汉字显示 */
    GUI_UC_SetEncodeUTF8();
    WM_EnableMemdev(WM_HBKWIN);
    hWinMain = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);   

    /*在指定位置创建指定尺寸的ICONVIEW 小工具*/
    hWinICON = ICONVIEW_CreateEx(15,
                             15, 
                             480,
                             272,
                             hWinMain,                   
                             WM_CF_SHOW | WM_CF_HASTRANS,     
                             ICONVIEW_CF_AUTOSCROLLBAR_V,   //0,
                             GUI_ID_ICONVIEW0,
                             105,
                             115
                             );
    
#endif

#if 1
    /* 向ICONVIEW 小工具添加新图标 */
    for (i = 0; i < GUI_COUNTOF(_aBitmapItem); i++) 
    {   
        ICONVIEW_AddBitmapItem(hWinICON, _aBitmapItem[i].pBitmap, _aBitmapItem[i].pText);
    }
#endif  

#if 1
    /* 设置要用于绘制标签的颜色 */
    ICONVIEW_SetTextColor(hWinICON,ICONVIEW_CI_SEL,GUI_BLACK);
    ICONVIEW_SetTextColor(hWinICON,ICONVIEW_CI_UNSEL,GUI_BLACK);
    //ICONVIEW_SetTextColor(hWinICON,ICONVIEW_CI_DISABLED,GUI_BLACK);
    
    /* 设置小工具的背景色 32 位颜色值的前8 位可用于alpha混合处理效果*/
    ICONVIEW_SetBkColor(hWinICON, ICONVIEW_CI_SEL, GUI_RED | 0x80000000);   
    
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

#if 0
      while (1) {
           GUI_Exec();
      }
#else
      while (1) {
        WM_HWIN hDlg;
        WM_HWIN hGraph;
        extern  int _Stop;
        extern  void _AddValues(void);

        hGraph = 0;
        if (!_Stop) {
            if((hWinWavePage == hWinInfo)&&(hWinInfo!=0)){
              if (!hGraph) {
                hGraph = WM_GetDialogItem(hDlg, ID_GRAPH_0);
              }
              _AddValues();
          }
        }
        GUI_Exec();
    }
#endif
}


/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
  