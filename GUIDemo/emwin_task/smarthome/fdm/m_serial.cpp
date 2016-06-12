//================================================================
#include "stm32f7xx.h"
#include "stm32f7xx_hal_dma.h"
#include "stm32f7xx_hal_usart.h"
#include "m_include.h"
#include "m_serial.h"
#include "m_gpio.h"
#include "m_pins.h"
/*================================================================
// 串口类
//===============================================================*/
#if 0
serial::serial(usart_dev* dev)
{ 
    usart_device = dev;
    
    txHead = txTail = 0;
    //-----------------------------------
    //== 功能电源打开 ==
//    rcc.powerOn(usart_device->clk_id);
//    rcc.powerOn(usart_device->clk_dma);
    
    //-----------------------------------
    // 1. 引脚定义
    gpio.setPinMode(dev->txPin);  
    gpio.setPinMode(dev->rxPin);

    //-----------------------------------
    // 2. 定义发送中断事件
    //nvic.irqEnable(dev->txDmaIrq);
    
    //-----------------------------------
    // 5. 定义接收DMA
    //DMA_InitTypeDef      DMA_InitStructure;
    HAL_DMA_DeInit(&dev->rxDma);
    
    dev->rxDma.Init.Channel = DMA_CHANNEL_5;
    dev->rxDma.Init.Direction = DMA_PERIPH_TO_MEMORY;
    dev->rxDma.Init.PeriphInc = DMA_PINC_DISABLE;
    dev->rxDma.Init.MemInc = DMA_MINC_ENABLE;
    dev->rxDma.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
    dev->rxDma.Init.MemDataAlignment = DMA_MDATAALIGN_WORD;
    dev->rxDma.Init.Mode = DMA_PFCTRL
    dev->rxDma.Init.Priority = DMA_PRIORITY_VERY_HIGH;
    dev->rxDma.Init.FIFOMode = DMA_FIFOMODE_ENABLE;
    dev->rxDma.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_FULL;
    dev->rxDma.Init.MemBurst = DMA_MBURST_INC4;
    dev->rxDma.Init.PeriphBurst = DMA_PBURST_INC4;
    
    dev->rxDma.Instance = DMA2_Stream4;

    /* Associate the DMA handle */
    __HAL_LINKDMA(hsd, hdmarx, dma_rx_handle);
    
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)dev->reg + 0x04;
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)dev->rxBuf;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_BufferSize = dev->rxSize;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(dev->rxDma, &DMA_InitStructure);
    DMA_Cmd(dev->rxDma, ENABLE);
    USART_DMACmd(dev->reg, USART_DMAReq_Rx, ENABLE);
    rxPos = DMA_GetCurrDataCounter(dev->rxDma);

    //-----------------------------------
    // 6. 定义发送DMA
    DMA_DeInit(dev->txDma);
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)dev->reg + 0x04;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(dev->txDma, &DMA_InitStructure);
    DMA_ITConfig(dev->txDma, DMA_IT_TC, ENABLE);
    dev->txDma->CNDTR = 0;
    USART_DMACmd(dev->reg, USART_DMAReq_Tx, ENABLE);
    USART_Cmd(dev->reg, ENABLE);
}
#endif
/*================================================================
// 起动串口
//===============================================================*/
void serial::begin(uint32 ibaud) {
    
    USART_HandleTypeDef USART_InitStructure;
    USART_InitStructure.Init.BaudRate = ibaud;
    USART_InitStructure.Init.WordLength = USART_WORDLENGTH_8B;
    USART_InitStructure.Init.StopBits = USART_STOPBITS_1;
    USART_InitStructure.Init.Parity = USART_PARITY_NONE;
    USART_InitStructure.Init.Mode = USART_MODE_TX_RX;
    HAL_USART_Init(&USART_InitStructure);//usart_device->reg, &USART_InitStructure
    band = ibaud;
}

/*================================================================
// 关闭串口
//===============================================================*/
void serial::end(void) {
    //rcc.powerOff(usart_device->clk_id);
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
  #if 1
    if (usart_device->rxDma->NDTR == rxPos)
        return 0;
    return usart_device->rxSize-rxPos;
  #endif
}

//=================================================================
// DMA 写入数据
//=================================================================
void serial::dmaTxFxn(void) {
  #if 1
    usart_device->txDma->CR =  (uint32_t)&usart_device->txBuf[txTail];
    if (txHead > txTail) {
        usart_device->txDma->M0AR = txHead-txTail;
        txTail=txHead;
    } else {
        usart_device->txDma->M1AR = usart_device->txSize-txTail;
        txTail = 0;
    }
    //DMA_Cmd(usart_device->txDma, ENABLE);
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
    //-----------------------------------
    // 1. 数据放入txBuf
    usart_device->txBuf[txHead] = ch;
    //-----------------------------------
    // 2. Head + 1
    txHead = (txHead + 1) % usart_device->txSize;
    if (!(usart_device->txDma->CR & 1)) {
        dmaTxFxn();
    }
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
    char serial1Rxbuf[SERIAL1_RX_LENGTH];
    char serial1Txbuf[SERIAL1_TX_LENGTH];

    usart_dev  usart1 = {.reg     = USART1, 
//                         .clk_id  = RCC_USART1, 
//                         .clk_dma = RCC_DMA1,
//                         .txDmaIrq= DMA1_Channel4_IRQn,
                         .rxDma   = DMA1_Stream6,
                         .txDma   = DMA1_Stream7,
                         .rxPin   = BOARD_USART6_RX_PIN, 
                         .txPin   = BOARD_USART6_TX_PIN, 
                         .rxBuf   = serial1Rxbuf,
                         .txBuf   = serial1Txbuf,
                         .rxSize  = SERIAL1_RX_LENGTH,
                         .txSize  = SERIAL1_TX_LENGTH};
    serial  serial1;//(&usart1);
    //serial1 = &usart1;                 

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
    char serial2Rxbuf[SERIAL2_RX_LENGTH];
    char serial2Txbuf[SERIAL2_TX_LENGTH];
    #if 1
    usart_dev  usart2 = {.reg     = USART2, 
//                         .clk_id  = RCC_USART2, 
//                         .clk_dma = RCC_DMA1,
//                         .txDmaIrq= DMA1_Channel7_IRQn,
                         .rxDma   = DMA1_Stream6,
                         .txDma   = DMA1_Stream7,
                         .rxPin   = BOARD_USART6_RX_PIN, 
                         .txPin   = BOARD_USART6_TX_PIN, 
                         .rxBuf   = serial2Rxbuf,
                         .txBuf   = serial2Txbuf,
                         .rxSize  = SERIAL2_RX_LENGTH,
                         .txSize  = SERIAL2_TX_LENGTH};
    serial  serial2;//(&usart2);
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
//=================================================================



