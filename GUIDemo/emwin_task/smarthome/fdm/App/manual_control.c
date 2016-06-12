/**
  ******************************************************************************
  * 文件: manual_control.c
  * 作者: Jack
  * 版本: V1.0.0
  * 描述: 手动控制界面
  ******************************************************************************
  *
  *                  版权所有 (C): LeiTek (leitek.taobao.com)
  *                                www.leitek.com
  *
  ******************************************************************************
  */
  
/* Includes ------------------------------------------------------------------*/
#include "stdbool.h"
#include "stm32f7xx.h"
#include "GUI.h"

/* Defines ------------------------------------------------------------------ */
#define TEMPERTURE_SHOW_BUTTON

/** 外部引用图片文件  **/
//extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_celsius;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_0_1_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_0_1;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_1_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_1;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_10_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_10;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_bed_tmp_dec_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_bed_tmp_dec;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_bed_tmp_inc_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_bed_tmp_inc;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_extruder_tmp_dec_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_extruder_tmp_dec;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_extruder_tmp_inc_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_extruder_tmp_inc;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_home_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_home;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_left_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_left;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_right_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_right;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_up_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_up;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_dwon_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_dwon;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_e_inc_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_e_inc;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_e_dec_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_e_dec;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_z_inc_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_z_inc;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_z_dec_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_z_dec;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_return_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_return;
//extern GUI_CONST_STORAGE GUI_BITMAP bmbutton_pressed;

/** 外部引用程序 **/
extern void _cbToolUse(WM_MESSAGE* pMsg);

/**
  * 函 数 名: _cbManualControl(WM_MESSAGE* pMsg) 
  * 描    述:手动控制界面
  * 参    数: pMsg
  * 返 回 值: 无
  */
void _cbManualControl(WM_MESSAGE* pMsg)
{
	BUTTON_Handle X_IncButton,X_DecButton,Y_IncButton,Y_DecButton,Z_IncButton,Z_DecButton,\
		E_IncButton,E_DecButton,Extruder_TmpIncButton,Extruder_TmpDecButton,Bed_TmpIncButton,\
		Bed_TmpDecButton,Range_10Button,Range_1Button,Range_0_1Button,Home_Button,Return_Button,\
        ExtruderTmpText,BedTmpText,ExtruderTmp_SwitchButton,BedTmp_SwitchButton,RangeText;
	WM_HWIN hWin = pMsg->hWin;
    const char motion_range[3][4]={"0.1","1","10"}; //按键按一次电机运行的长度
    //const float motion_range_f[3]={ 0.1,1,10}; //温度控制级别
    static uint8_t motion_range_select = 2; //用户选择的长度
    char command_buff[20]={0}; //指令缓存区
    char text_buffer[20]={0};
    int16_t temp = 0,temp1 = 0;
	switch (pMsg->MsgId) 
	{
		case WM_CREATE:	
            /* 设置聚焦*/		
            WM_SetFocus(hWin);
			/* 创建手动控制界面的按钮 */
			Home_Button = BUTTON_CreateEx(128,68,63,63,  hWin, WM_CF_SHOW, 0, MANUAL_BUTTON_HOME);
			BUTTON_SetBitmapEx(Home_Button,BUTTON_BI_UNPRESSED, &bmmanual_home_xg, 0 ,0);
            BUTTON_SetBitmapEx(Home_Button,BUTTON_BI_PRESSED, &bmmanual_home, 0 ,0);
        
			X_IncButton = BUTTON_CreateEx(192,68, 63,63, hWin, WM_CF_SHOW, 0, MANUAL_BUTTON_X_INC);
			BUTTON_SetBitmapEx(X_IncButton,BUTTON_BI_UNPRESSED, &bmmanual_right_xg, 0 ,0);
            BUTTON_SetBitmapEx(X_IncButton,BUTTON_BI_PRESSED, &bmmanual_right, 0 ,0);
        
			X_DecButton = BUTTON_CreateEx(64,68,63,63, hWin, WM_CF_SHOW, 0, MANUAL_BUTTON_X_DEC);
			BUTTON_SetBitmapEx(X_DecButton,BUTTON_BI_UNPRESSED, &bmmanual_left_xg, 0 ,0);
            BUTTON_SetBitmapEx(X_DecButton,BUTTON_BI_PRESSED, &bmmanual_left, 0 ,0);

			Y_IncButton = BUTTON_CreateEx(128,4, 63,63,  hWin, WM_CF_SHOW, 0, MANUAL_BUTTON_Y_INC);
			BUTTON_SetBitmapEx(Y_IncButton,BUTTON_BI_UNPRESSED, &bmmanual_up_xg, 0 ,0);
            BUTTON_SetBitmapEx(Y_IncButton,BUTTON_BI_PRESSED, &bmmanual_up, 0 ,0);

			Y_DecButton = BUTTON_CreateEx(128,132,63,63,  hWin, WM_CF_SHOW, 0, MANUAL_BUTTON_Y_DEC);
			BUTTON_SetBitmapEx(Y_DecButton,BUTTON_BI_UNPRESSED, &bmmanual_dwon_xg, 0 ,0);
            BUTTON_SetBitmapEx(Y_DecButton,BUTTON_BI_PRESSED, &bmmanual_dwon, 0, 0);

			Z_IncButton = BUTTON_CreateEx(192,132,63,63, hWin, WM_CF_SHOW, 0, MANUAL_BUTTON_Z_INC);
			BUTTON_SetBitmapEx(Z_IncButton,BUTTON_BI_UNPRESSED, &bmmanual_z_inc_xg, 0 ,0);
            BUTTON_SetBitmapEx(Z_IncButton,BUTTON_BI_PRESSED, &bmmanual_z_inc, 0 ,0);

			Z_DecButton = BUTTON_CreateEx(192,4,  63,63,   hWin, WM_CF_SHOW, 0, MANUAL_BUTTON_Z_DEC);
			BUTTON_SetBitmapEx(Z_DecButton,BUTTON_BI_UNPRESSED, &bmmanual_z_dec_xg, 0 ,0);
            BUTTON_SetBitmapEx(Z_DecButton,BUTTON_BI_PRESSED, &bmmanual_z_dec, 0 ,0);
            
			E_IncButton = BUTTON_CreateEx(64,132,63,63,  hWin, WM_CF_SHOW, 0, MANUAL_BUTTON_E_INC);
			BUTTON_SetBitmapEx(E_IncButton,BUTTON_BI_UNPRESSED, &bmmanual_e_inc_xg, 0 ,0);
            BUTTON_SetBitmapEx(E_IncButton,BUTTON_BI_PRESSED, &bmmanual_e_inc, 0 ,0);

			E_DecButton = BUTTON_CreateEx(64,4 , 63,63,  hWin, WM_CF_SHOW, 0, MANUAL_BUTTON_E_DEC);
			BUTTON_SetBitmapEx(E_DecButton,BUTTON_BI_UNPRESSED, &bmmanual_e_dec_xg, 0 ,0);
            BUTTON_SetBitmapEx(E_DecButton,BUTTON_BI_PRESSED, &bmmanual_e_dec, 0 ,0);

			Bed_TmpIncButton = BUTTON_CreateEx(262,20,50,50,   hWin, WM_CF_SHOW, 0, MANUAL_BUTTON_BEDTMP_INC);
			BUTTON_SetBitmapEx(Bed_TmpIncButton,BUTTON_BI_UNPRESSED, &bmmanual_bed_tmp_inc_xg, 0 ,0);
            BUTTON_SetBitmapEx(Bed_TmpIncButton,BUTTON_BI_PRESSED, &bmmanual_bed_tmp_inc, 0 ,0);

			Bed_TmpDecButton = BUTTON_CreateEx(262,110,50,50,  hWin, WM_CF_SHOW, 0, MANUAL_BUTTON_BEDTMP_DEC);
			BUTTON_SetBitmapEx(Bed_TmpDecButton,BUTTON_BI_UNPRESSED, &bmmanual_bed_tmp_dec_xg, 0 ,0);
            BUTTON_SetBitmapEx(Bed_TmpDecButton,BUTTON_BI_PRESSED, &bmmanual_bed_tmp_dec, 0 ,0);
            
#ifdef TEMPERTURE_SHOW_BUTTON  
            temp = getTemperature(0);
            temp1 = getTargetTemperature(0); 
            sprintf(text_buffer,"%02d/%02d",temp,temp1);   
            ExtruderTmp_SwitchButton = BUTTON_CreateEx(5,78,50,25,  hWin, WM_CF_SHOW, 0, MANUAL_BUTTON_EXTRTMP_SWITCH);
            BUTTON_SetText(ExtruderTmp_SwitchButton,text_buffer);
            
            temp  = getTemperature(1);
            temp1 = getTargetTemperature(1);
            sprintf(text_buffer,"%02d/%02d",temp,temp1); 
            BedTmp_SwitchButton = BUTTON_CreateEx(260,78,50,25, hWin, WM_CF_SHOW, 0, MANUAL_BUTTON_BEDTMP_SWITCH);
            BUTTON_SetText(BedTmp_SwitchButton,text_buffer);
#else       
            temp = getTemperature(0);
            temp1 = getTargetTemperature(0); 
            sprintf(text_buffer,"%02d/%02d",temp,temp1);   
            ExtruderTmpText = TEXT_CreateEx(11,78,60,20, hWin, WM_CF_SHOW, TEXT_CF_LEFT,MANUAL_EXTRUDER_ALL_TEMPERATURE_TXET,text_buffer);
   
            temp  = getTemperature(1);
            temp1 = getTargetTemperature(1);
            sprintf(text_buffer,"%02d/%02d",temp,temp1); 
            BedTmpText = TEXT_CreateEx(266,78,60,20, hWin, WM_CF_SHOW, TEXT_CF_LEFT,MANUAL_BED_ALL_TEMPERATURE_TXET,text_buffer);
#endif

			Extruder_TmpIncButton = BUTTON_CreateEx(8,20,50,50,   hWin, WM_CF_SHOW, 0, MANUAL_BUTTON_EXTRTMP_INC);
			BUTTON_SetBitmapEx(Extruder_TmpIncButton,BUTTON_BI_UNPRESSED, &bmmanual_extruder_tmp_inc_xg, 0 ,0);
            BUTTON_SetBitmapEx(Extruder_TmpIncButton,BUTTON_BI_PRESSED, &bmmanual_extruder_tmp_inc, 0 ,0);

			Extruder_TmpDecButton = BUTTON_CreateEx(8,110,50,50,  hWin, WM_CF_SHOW, 0, MANUAL_BUTTON_EXTRTMP_DEC);
			BUTTON_SetBitmapEx(Extruder_TmpDecButton,BUTTON_BI_UNPRESSED, &bmmanual_extruder_tmp_dec_xg, 0 ,0);
            BUTTON_SetBitmapEx(Extruder_TmpDecButton,BUTTON_BI_PRESSED, &bmmanual_extruder_tmp_dec, 0 ,0);
            
            Range_0_1Button = BUTTON_CreateEx(64,196,63,43,  hWin, WM_CF_SHOW, 0, MANUAL_BUTTON_01_RANGE);
			BUTTON_SetBitmapEx(Range_0_1Button,BUTTON_BI_UNPRESSED, &bmmanual_0_1_xg, 0 ,0);
            BUTTON_SetBitmapEx(Range_0_1Button,BUTTON_BI_PRESSED, &bmmanual_0_1, 0 ,0);
            
            Range_1Button = BUTTON_CreateEx(128,196,63,43,   hWin, WM_CF_SHOW, 0, MANUAL_BUTTON_1_RANGE);
			BUTTON_SetBitmapEx(Range_1Button,BUTTON_BI_UNPRESSED, &bmmanual_1_xg, 0 ,0);
            BUTTON_SetBitmapEx(Range_1Button,BUTTON_BI_PRESSED, &bmmanual_1, 0 ,0);
            
            Range_10Button = BUTTON_CreateEx(192,196,63,43,   hWin, WM_CF_SHOW, 0, MANUAL_BUTTON_10_RANGE);
			BUTTON_SetBitmapEx(Range_10Button,BUTTON_BI_UNPRESSED, &bmmanual_10_xg, 0 ,0);
            BUTTON_SetBitmapEx(Range_10Button,BUTTON_BI_PRESSED, &bmmanual_10, 0 ,0);

            sprintf(text_buffer,"%s",motion_range[motion_range_select]);  
            RangeText = TEXT_CreateEx(20,200,40,20, hWin, WM_CF_SHOW, TEXT_CF_LEFT,RANGE_TEXT,text_buffer);

			Return_Button = BUTTON_CreateEx(256,176,64,63,  hWin, WM_CF_SHOW, 0, MANUAL_BUTTON_RETURN);
			BUTTON_SetBitmapEx(Return_Button,BUTTON_BI_UNPRESSED, &bmmanual_return_xg, 0 ,0);
            BUTTON_SetBitmapEx(Return_Button,BUTTON_BI_PRESSED, &bmmanual_return, 0 ,0);

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
                memset(command_buff,0,sizeof(command_buff));
                enquecommand("G91 \r\n");
				switch (Id) 
				{
					case MANUAL_BUTTON_HOME:{
                        sprintf(command_buff,"G28 \r\n");
                        enquecommand(command_buff);
					}break;
					case MANUAL_BUTTON_X_INC:{
                        sprintf(command_buff,"G0 X%s F4800 \r\n",motion_range[motion_range_select]);
                        enquecommand(command_buff);
                    }break;
					case MANUAL_BUTTON_X_DEC:{
                        sprintf(command_buff,"G0 X-%s F4800 \r\n",motion_range[motion_range_select]);
                        enquecommand(command_buff);
                    }break;
					case MANUAL_BUTTON_Y_INC:{
                        sprintf(command_buff,"G0 Y%s F4800 \r\n",motion_range[motion_range_select]); 
                        enquecommand(command_buff);                        
                    }break;
					case MANUAL_BUTTON_Y_DEC:{
                        sprintf(command_buff,"G0 Y-%s F4800 \r\n",motion_range[motion_range_select]);
                        enquecommand(command_buff);                     
                    }break;
					case MANUAL_BUTTON_Z_INC:{
                        sprintf(command_buff,"G0 Z%s F480 \r\n",motion_range[motion_range_select]);   
                        enquecommand(command_buff);
                    }break;
					case MANUAL_BUTTON_Z_DEC:{
                        sprintf(command_buff,"G0 Z-%s F480 \r\n",motion_range[motion_range_select]);   
                        enquecommand(command_buff);
                    }break;
					case MANUAL_BUTTON_E_INC:{
                        sprintf(command_buff,"G0 E%s F180 \r\n",motion_range[motion_range_select]);   
                        enquecommand(command_buff);
                    }break;
					case MANUAL_BUTTON_E_DEC:{
                        sprintf(command_buff,"G0 E-%s F1000 \r\n",motion_range[motion_range_select]);   
                        enquecommand(command_buff);
                    }break;
                    case MANUAL_BUTTON_EXTRTMP_SWITCH:{
                        if(0 == getTargetTemperature(0)) 
                            setTargetHotend(200,0);
                        else 
                            setTargetHotend(0,0);
                        ExtruderTmp_SwitchButton = WM_GetDialogItem(pMsg->hWin, MANUAL_BUTTON_EXTRTMP_SWITCH);   
                        temp = getTemperature(0);
                        temp1 = getTargetTemperature(0); 
                        sprintf(text_buffer,"%02d/%02d",temp,temp1);
                        BUTTON_SetText(ExtruderTmp_SwitchButton,text_buffer);
                    }break;
                    case MANUAL_BUTTON_BEDTMP_SWITCH:{
                        if(0 == getTargetTemperature(1))
                           setTargetBed(50); 
                        else
                           setTargetBed(0); 
                        BedTmp_SwitchButton = WM_GetDialogItem(pMsg->hWin, MANUAL_BUTTON_BEDTMP_SWITCH);      
                        temp  = getTemperature(1);
                        temp1 = getTargetTemperature(1);
                        sprintf(text_buffer,"%02d/%02d",temp,temp1);     
                        //TEXT_SetText(BedTmpText,text_buffer);   
                        BUTTON_SetText(BedTmp_SwitchButton,text_buffer);   
                    }break;
					case MANUAL_BUTTON_BEDTMP_INC:{
                        //判断如果设定温度为0 则直接设置为50
                        //if(0 == getTargetTemperature(1)) setTargetBed(50);
                        setTargetBedIncDec(5);
                        //BedTmpText = WM_GetDialogItem(pMsg->hWin, MANUAL_BED_ALL_TEMPERATURE_TXET);   
                        BedTmp_SwitchButton = WM_GetDialogItem(pMsg->hWin, MANUAL_BUTTON_BEDTMP_SWITCH);      
                        temp  = getTemperature(1);
                        temp1 = getTargetTemperature(1);
                        sprintf(text_buffer,"%02d/%02d",temp,temp1);     
                        //TEXT_SetText(BedTmpText,text_buffer);   
                        BUTTON_SetText(BedTmp_SwitchButton,text_buffer);                        
                    }break;
					case MANUAL_BUTTON_BEDTMP_DEC:{
                        //判断如果设定温度为0 则直接设置为50
                        //if(0 == getTargetTemperature(1)) setTargetBed(50);  
                        setTargetBedIncDec(-5); 
                        //BedTmpText = WM_GetDialogItem(pMsg->hWin, MANUAL_BED_ALL_TEMPERATURE_TXET);
                        BedTmp_SwitchButton = WM_GetDialogItem(pMsg->hWin, MANUAL_BUTTON_BEDTMP_SWITCH);   
                        temp  = getTemperature(1);
                        temp1 = getTargetTemperature(1);
                        sprintf(text_buffer,"%02d/%02d",temp,temp1);     
                        //TEXT_SetText(BedTmpText,text_buffer);   
                        BUTTON_SetText(BedTmp_SwitchButton,text_buffer);
                    }break;
					case MANUAL_BUTTON_EXTRTMP_INC:{
                        //判断如果设定温度为0 则直接设置为200
                        //if(0 == getTargetTemperature(0)) setTargetHotend(200,0);                       
                        setTargetHotendIncDec(5,0); 
                        //ExtruderTmpText = WM_GetDialogItem(pMsg->hWin, MANUAL_EXTRUDER_ALL_TEMPERATURE_TXET);   
                        ExtruderTmp_SwitchButton = WM_GetDialogItem(pMsg->hWin, MANUAL_BUTTON_EXTRTMP_SWITCH);   
                        temp = getTemperature(0);
                        temp1 = getTargetTemperature(0); 
                        sprintf(text_buffer,"%02d/%02d",temp,temp1);
                        BUTTON_SetText(ExtruderTmp_SwitchButton,text_buffer);
                        //TEXT_SetText(ExtruderTmpText,text_buffer);   
                    }break;
					case MANUAL_BUTTON_EXTRTMP_DEC:{
                        //判断如果设定温度为0 则直接设置为200
                        //if(0 == getTargetTemperature(0)) setTargetHotend(200,0);         
                        setTargetHotendIncDec(-5,0);
                        //ExtruderTmpText = WM_GetDialogItem(pMsg->hWin, MANUAL_EXTRUDER_ALL_TEMPERATURE_TXET);
                        ExtruderTmp_SwitchButton = WM_GetDialogItem(pMsg->hWin, MANUAL_BUTTON_EXTRTMP_SWITCH); 
                        temp  = getTemperature(0); 
                        temp1 = getTargetTemperature(0);                         
                        sprintf(text_buffer,"%02d/%02d",temp,temp1);
                        BUTTON_SetText(ExtruderTmp_SwitchButton,text_buffer);                        
                        //TEXT_SetText(ExtruderTmpText,text_buffer);                      
                    }break;                    
  					case MANUAL_BUTTON_01_RANGE:{
                        motion_range_select = 0;
                        RangeText = WM_GetDialogItem(pMsg->hWin, RANGE_TEXT);   
                        TEXT_SetText(RangeText,motion_range[motion_range_select]);   
                    }break;                  
  					case MANUAL_BUTTON_1_RANGE:{
                        motion_range_select = 1;
                        RangeText = WM_GetDialogItem(pMsg->hWin, RANGE_TEXT);   
                        TEXT_SetText(RangeText,motion_range[motion_range_select]);  
                    }break;  
  					case MANUAL_BUTTON_10_RANGE:{
                        motion_range_select = 2;
                        RangeText = WM_GetDialogItem(pMsg->hWin, RANGE_TEXT);   
                        TEXT_SetText(RangeText,motion_range[motion_range_select]);  
                    }break;                      
					case MANUAL_BUTTON_RETURN:{
						_DeleteFrame();
						_CreateFrame(&_cbToolUse);				
                    }break;
				}
                enquecommand("G90 \r\n");
			}
			break;
        case TEMPERATRUE_REPORT:  //处理温度显示信息，每秒修改一次  °没有字库支持       
            //BedTmpText = WM_GetDialogItem(pMsg->hWin, MANUAL_BED_ALL_TEMPERATURE_TXET);   
            BedTmp_SwitchButton = WM_GetDialogItem(pMsg->hWin, MANUAL_BUTTON_BEDTMP_SWITCH);   
            temp  = getTemperature(1);
            temp1 = getTargetTemperature(1);
            sprintf(text_buffer,"%02d/%02d",temp,temp1);
            //TEXT_SetText(BedTmpText,text_buffer);   
            BUTTON_SetText(BedTmp_SwitchButton,text_buffer); 
            //ExtruderTmpText = WM_GetDialogItem(pMsg->hWin, MANUAL_EXTRUDER_ALL_TEMPERATURE_TXET);   
            ExtruderTmp_SwitchButton = WM_GetDialogItem(pMsg->hWin, MANUAL_BUTTON_EXTRTMP_SWITCH); 
            temp = getTemperature(0);
            temp1 = getTargetTemperature(0); 
            sprintf(text_buffer,"%02d/%02d",temp,temp1);    
            //TEXT_SetText(ExtruderTmpText,text_buffer);  
            BUTTON_SetText(ExtruderTmp_SwitchButton,text_buffer);   
            break;
		default:
		WM_DefaultProc(pMsg);
	}
}

