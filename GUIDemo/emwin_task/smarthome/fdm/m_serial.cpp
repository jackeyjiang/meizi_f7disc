//================================================================
#include "string.h"
#include "stm32f7xx.h"
#include "stm32f7xx_hal_dma.h"
#include "stm32f7xx_hal_usart.h"
#include "Driver_USART.h"
#include "cmsis_os.h"
#include "m_include.h"
#include "m_serial.h"
#include "m_gpio.h"
#include "m_pins.h"
#include "m_nvic.h"


osSemaphoreDef(semTxReady);
osSemaphoreDef(semRxReady);

osMutexId printMutexId;
osMutexDef(printMutexId);

extern ARM_DRIVER_USART Driver_USART6;
extern osThreadId osThreadId_commuTask;
static ARM_DRIVER_USART * USARTdrv = &Driver_USART6;

void myUSART_callback(uint32_t event)
{
    switch (event)
    {
    case ARM_USART_EVENT_RECEIVE_COMPLETE:
        break;
    case ARM_USART_EVENT_TRANSFER_COMPLETE:
        break;
    case ARM_USART_EVENT_SEND_COMPLETE:
        /* Success: Wakeup Thread */
        //osMutexRelease(printMutexId);        
        break;
    case ARM_USART_EVENT_TX_COMPLETE:

        break;
 
    case ARM_USART_EVENT_RX_TIMEOUT:
         __breakpoint(0);  /* Error: Call debugger or replace with custom error handling */
        break;
 
    case ARM_USART_EVENT_RX_OVERFLOW:
    case ARM_USART_EVENT_TX_UNDERFLOW:
        __breakpoint(0);  /* Error: Call debugger or replace with custom error handling */
        break;
    }
}

/*================================================================
// 串口类
//===============================================================*/
#if 1
serial::serial(usart_dev* dev)
{
    usart_device = dev;
    txHead = txTail = 0;
}
#endif

void serial::setSem(void) {
    semTxReady = osSemaphoreCreate(osSemaphore(semTxReady),0);
    semRxReady = osSemaphoreCreate(osSemaphore(semRxReady),0);
    printMutexId = osMutexCreate(osMutex(printMutexId));
}
/*================================================================
// 启动串口
//===============================================================*/
void serial::begin(void) {

    ARM_DRIVER_VERSION     version;
    ARM_USART_CAPABILITIES drv_capabilities;
    
    char                   cmd;
    static  char           text_show[20]={"I am Jackey Jiang\n"};
 
  #ifdef DEBUG
    version = USARTdrv->GetVersion();
    if (version.api < 0x200)   /* requires at minimum API version 2.00 or higher */
    {                          /* error handling */
        return;
    }
    drv_capabilities = USARTdrv->GetCapabilities();
    if (drv_capabilities.event_tx_complete == 0)
    {                          /* error handling */
        return;
    }
  #endif
 
    /*Initialize the USART driver */
    USARTdrv->Initialize(myUSART_callback);
    /*Power up the USART peripheral */
    USARTdrv->PowerControl(ARM_POWER_FULL);
    /*Configure the USART to 115200 Bits/sec */
    USARTdrv->Control(ARM_USART_MODE_ASYNCHRONOUS |
                      ARM_USART_DATA_BITS_8 |
                      ARM_USART_PARITY_NONE |
                      ARM_USART_STOP_BITS_1 |
                      ARM_USART_FLOW_CONTROL_NONE, 256000);
     
    /* Enable Receiver and Transmitter lines */
    USARTdrv->Control (ARM_USART_CONTROL_TX, 1);
    USARTdrv->Control (ARM_USART_CONTROL_RX, 1);
 
    USARTdrv->Send("\n Melzi start \n", 15);
    //USARTdrv->Send(&text_show[0], 20);
    
    rb_init(&rxRingbuf, sizeof(rxBuf),rxBuf);
    rb_init(&txRingbuf, sizeof(txBuf),txBuf);
    
//    osSignalWait(0x01, osWaitForever);
//     
//    while (1)
//    {
//        USARTdrv->Receive(&cmd, 1);          /* Get byte from UART */
//        osSignalWait(0x01, osWaitForever);
//        if (cmd == 13)                       /* CR, send greeting  */
//        {
//          USARTdrv->Send("\nHello World!", 12);
//          osSignalWait(0x01, osWaitForever);
//        }
// 
//    }

}

/*================================================================
// 关闭串口
//===============================================================*/
void serial::end(void) {
    USARTdrv->Control (ARM_USART_CONTROL_TX, 0);
    USARTdrv->Control (ARM_USART_CONTROL_RX, 0);
}

//=================================================================
// 判读是否有数据
//=================================================================
uint8 serial::read(void) {
  #if 1
    char ch = usart_device->rxBuf[usart_device->rxSize-rxPos];
    if (--rxPos == 0)
		rxPos=usart_device->rxSize;
    return ch;
  #endif
}

//=================================================================
// 判读是否有数据
//=================================================================
uint32 serial::available(void) {
  #if 0
    if (usart_device->rxDma->NDTR == rxPos)
        return 0;
    return usart_device->rxSize-rxPos;
  #else
    if(rxPos == USARTdrv->GetRxCount())
        return 0;
    return usart_device->rxSize-rxPos;
  #endif
}

//=================================================================
// DMA 写入数据
//=================================================================
void serial::dmaTxFxn(void) {
  #if 0
    usart_device->txDma->CR =  (uint32_t)&usart_device->txBuf[txTail];
    if (txHead > txTail) {
        usart_device->txDma->M0AR = txHead-txTail;
        txTail=txHead;
    } else {
        usart_device->txDma->M1AR = usart_device->txSize-txTail;
        txTail = 0;
    }
    //DMA_Cmd(usart_device->txDma, ENABLE);
   
  #else
    if (txHead > txTail) {
        while( ARM_DRIVER_OK == USARTdrv->Send(&usart_device->txBuf[txTail],txHead-txTail))
        //printf("&usart_device->txBuf[txTail] = %s, txHead-txTail = %d\n",&usart_device->txBuf[txTail],(txHead-txTail));
        txTail = txHead; 
    } else {
        USARTdrv->Send(&usart_device->txBuf[txTail],usart_device->txSize-txTail);
        //printf("&usart_device->txBuf[txTail] = %s, usart_device->txSize-txTail = %d\n",&usart_device->txBuf[txTail],usart_device->txSize-txTail);
        txTail = 0; 
    }      
  #endif
}
//=================================================================
// 写入字节数据
//=================================================================
void serial::write(uint8 *str) {

    while (*str) {
        write(*str++);
    }
}
//=================================================================
// 写入字节数据
//=================================================================
void serial::write(uint8 ch) {
  #if 1
    ARM_USART_STATUS       drv_status;
    //-----------------------------------
    // 1. 数据放入txBuf
    usart_device->txBuf[txHead] = ch;
    //-----------------------------------
    // 2. Head + 1
    txHead = (txHead + 1) % usart_device->txSize;
    
    // 3. Send
    drv_status = USARTdrv->GetStatus();
    while(drv_status.tx_busy == 1);
    //osMutexWait(printMutexId,osWaitForever);
    dmaTxFxn();
    
  #endif
}
//=================================================================
// 清空接收区域
//=================================================================
void serial::flush(void) {
  #if 1
    rxPos = usart_device->rxDma->NDTR;
  #endif
}
//=================================================================
//== 数据发送完成，允许下次发送
void serial::txIsr() {
  #if 1
    txFinish=false;
    //DMA_Cmd(usart_device->txDma, DISABLE);
    if (txHead!=txTail) {
        dmaTxFxn();
    } else {
        txFinish=true;
    }
  #endif
}
//=================================================================
// 实体定义
#if SERIAL1_USE == TRUE
    static char serial1Rxbuf[SERIAL1_RX_LENGTH];
    static char serial1Txbuf[SERIAL1_TX_LENGTH];

    usart_dev  usart1 = {.reg     = USART6, 
//                         .clk_id  = RCC_USART1, 
//                         .clk_dma = RCC_DMA1,
                         .txDmaIrq= DMA2_Stream4_IRQn,
                         .rxDma   = DMA2_Stream6,
                         .txDma   = DMA2_Stream7,
                         .rxPin   = BOARD_USART6_RX_PIN, 
                         .txPin   = BOARD_USART6_TX_PIN, 
                         .rxBuf   = serial1Rxbuf,
                         .txBuf   = serial1Txbuf,
                         .rxSize  = SERIAL1_RX_LENGTH,
                         .txSize  = SERIAL1_TX_LENGTH};
    serial  serial1(&usart1);          
    #ifdef __cplusplus
    extern "C" {
    #endif
        void __irq_dma1_channel4(void) {
            //DMA_ClearITPendingBit(DMA1_IT_TC4);
            serial1.txIsr();
        }
    #ifdef __cplusplus
    }
    #endif 
#endif
#if SERIAL2_USE == TRUE
    static char serial2Rxbuf[SERIAL2_RX_LENGTH];
    static char serial2Txbuf[SERIAL2_TX_LENGTH];
    #if 1
    usart_dev  usart2 = {.reg     = USART2, 
//                         .clk_id  = RCC_USART2, 
//                         .clk_dma = RCC_DMA1,
                         .txDmaIrq= DMA1_Stream7_IRQn,
                         .rxDma   = DMA1_Stream6,
                         .txDma   = DMA1_Stream7,
                         .rxPin   = BOARD_USART6_RX_PIN, 
                         .txPin   = BOARD_USART6_TX_PIN, 
                         .rxBuf   = serial2Rxbuf,
                         .txBuf   = serial2Txbuf,
                         .rxSize  = SERIAL2_RX_LENGTH,
                         .txSize  = SERIAL2_TX_LENGTH};
    serial  serial2(&usart2);
    #endif
    #ifdef __cplusplus
    extern "C" {
    #endif                   
        void __irq_dma1_channel7(void) {
            //DMA_ClearITPendingBit(DMA1_IT_TC7);
            //serial2.txIsr();
        }
    #ifdef __cplusplus
    }
    #endif 
#endif
    