//=============================================================================
#ifndef     __M_INCLUDE_H__
#define     __M_INCLUDE_H__
//=============================================================================
#include    "sysConf.h"
#include    <stdio.h>
#include    <Global.h>
//=============================================================================
// 库文件                                                                    //
//=============================================================================
#include "stm32f7xx_hal.h"

//=============================================================================
// 环形队列                                                               //
//=============================================================================
#include "m_ringBuffer.h"
//=============================================================================
//  RCC                                                                      //
//=============================================================================
#if 0
#include "m_mapleInit.h"
//=============================================================================
//  dma                                                                //
//=============================================================================
#include "m_dma.h"
//=============================================================================
//  RCC                                                                      //
//=============================================================================
#include "m_rcc.h"

//=============================================================================
//  EEP 数据存储                                                                      //
//=============================================================================
#include "m_eep.h"

//=============================================================================
//  NVIC                                                                     //
//=============================================================================
#include "m_nvic.h"

//=============================================================================
//  ADC                                                                      //
//=============================================================================
#include "m_adc.h"

//=============================================================================
//  EXIT                                                                     //
//=============================================================================
#include "m_exti.h"

//=============================================================================
//  GPIO                                                                     //
//=============================================================================
#include "m_gpio.h"

//=============================================================================
//  TIMER                                                                    //
//=============================================================================
//#include "m_timer.h"

//=============================================================================
//  pins                                                                     //
//=============================================================================
#include "m_pins.h"

//=============================================================================
//  fat file system                                                          //
//=============================================================================
#include "rl_fs.h"			
//=============================================================================
//  print                                                                    //
//=============================================================================
#include "m_Print.h"

//=============================================================================
//  serial                                                                   //
//=============================================================================
#include "m_serial.h"

//=============================================================================
//  usb                                                                      //
//  code:4584  RO-DATA:0    RW-DATA:65  ZI-DATA:200                          //
//=============================================================================
#ifdef USB_SERIAL_USE
#include "usb_lib.h"
#include "m_usb.h"
#endif 

//=============================================================================
//  usb 虚拟串口                                                             //
//  code:1740  RO-DATA: 296 RW-DATA:161 ZI-DATA:264                          //
//=============================================================================
#ifdef USB_SERIAL_USE
//#include "m_usbSerial.h"
#endif

//=============================================================================
//                                                                           //
//=============================================================================
#include "language.h"
#endif
//=============================================================================
// 步进电机控制                                                              //
//=============================================================================
#include "stepMoto.h"
//
//=============================================================================
// 温度控制                                                                  //
//=============================================================================
#include "temperature.h"
//
//=============================================================================
// 通讯协议                                                                  //
//=============================================================================
#include "commu.h"
//
//=============================================================================
// 通讯协议                                                                  //
//=============================================================================
#include "Gcode.h"
//
//=============================================================================
// eeprom 存储                                                                 //
//=============================================================================
#include "Eeprom.h"
//
//=============================================================================
// sdReader                                                                  //
//=============================================================================
#include "sdReader.h"

#if 0
//
//=============================================================================
// U8glib 
//=============================================================================
#include "U8glib.h"
//
//=============================================================================
// lcd 
//=============================================================================
#include "U8GLIB_ST7920_128X64_RRD.h"
#include "lcd.h"
//
//=============================================================================
// spi 
//=============================================================================
#include "m_spi.h"
//
//=============================================================================
// spi 
//=============================================================================
#include "m_dac.h"
//
//=============================================================================
#endif

#ifdef __RTX
extern uint32_t os_time;

__inline uint32_t osKernelSysTick(void) { 
  return os_time; 
}
#endif

#endif



