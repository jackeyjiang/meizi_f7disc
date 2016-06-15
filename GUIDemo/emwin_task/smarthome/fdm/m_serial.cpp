//================================================================
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

extern ARM_DRIVER_USART Driver_USART6;
static ARM_DRIVER_USART * USARTdrv = &Driver_USART6;

void myUSART_callback(uint32_t event)
{
    switch (event)
    {
    case ARM_USART_EVENT_RECEIVE_COMPLETE:    
    case ARM_USART_EVENT_TRANSFER_COMPLETE:
    case ARM_USART_EVENT_SEND_COMPLETE:
    case ARM_USART_EVENT_TX_COMPLETE:
        /* Success: Wakeup Thread */
        //osSignalSet(tid_myUART_Thread, 0x01);
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
// 新建class无意义    
}
#endif

void serial::setSem(void) {
    semTxReady = osSemaphoreCreate(osSemaphore(semTxReady),0);
    semRxReady = osSemaphoreCreate(osSemaphore(semRxReady),0);
}
/*================================================================
// 启动串口
//===============================================================*/
void serial::begin(void) {

    ARM_DRIVER_VERSION     version;
    ARM_USART_CAPABILITIES drv_capabilities;
    char                   cmd;
 
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
    /*Configure the USART to 9600 Bits/sec */
    USARTdrv->Control(ARM_USART_MODE_ASYNCHRONOUS |
                      ARM_USART_DATA_BITS_8 |
                      ARM_USART_PARITY_NONE |
                      ARM_USART_STOP_BITS_1 |
                      ARM_USART_FLOW_CONTROL_NONE, 9600);
     
    /* Enable Receiver and Transmitter lines */
    USARTdrv->Control (ARM_USART_CONTROL_TX, 1);
    USARTdrv->Control (ARM_USART_CONTROL_RX, 1);
 
    USARTdrv->Send("\n Melzi start \n", 15);
    
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
    
#if 0
//=================================================================

/**
  * @brief UART MSP Initialization 
  *        This function configures the hardware resources used in this example: 
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration  
  *           - DMA configuration for transmission request by peripheral 
  *           - NVIC configuration for DMA interrupt request enable
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
  static DMA_HandleTypeDef hdma_tx;
  static DMA_HandleTypeDef hdma_rx;
  
  GPIO_InitTypeDef  GPIO_InitStruct;
  
  /*##-1- Enable peripherals and GPIO Clocks #################################*/
  /* Enable GPIO TX/RX clock */
  USARTx_TX_GPIO_CLK_ENABLE();
  USARTx_RX_GPIO_CLK_ENABLE();

  /* Enable USARTx clock */
  USARTx_CLK_ENABLE();

  /* Enable DMA clock */
  DMAx_CLK_ENABLE();
  
  /*##-2- Configure peripheral GPIO ##########################################*/  
  /* UART TX GPIO pin configuration  */
  GPIO_InitStruct.Pin       = USARTx_TX_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLUP;
  GPIO_InitStruct.Speed     = GPIO_SPEED_HIGH;
  GPIO_InitStruct.Alternate = USARTx_TX_AF;

  HAL_GPIO_Init(USARTx_TX_GPIO_PORT, &GPIO_InitStruct);

  /* UART RX GPIO pin configuration  */
  GPIO_InitStruct.Pin = USARTx_RX_PIN;
  GPIO_InitStruct.Alternate = USARTx_RX_AF;

  HAL_GPIO_Init(USARTx_RX_GPIO_PORT, &GPIO_InitStruct);

  /*##-3- Configure the DMA ##################################################*/
  /* Configure the DMA handler for Transmission process */
  hdma_tx.Instance                 = USARTx_TX_DMA_STREAM;
  hdma_tx.Init.Channel             = USARTx_TX_DMA_CHANNEL;
  hdma_tx.Init.Direction           = DMA_MEMORY_TO_PERIPH;
  hdma_tx.Init.PeriphInc           = DMA_PINC_DISABLE;
  hdma_tx.Init.MemInc              = DMA_MINC_ENABLE;
  hdma_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
  hdma_tx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
  hdma_tx.Init.Mode                = DMA_NORMAL;
  hdma_tx.Init.Priority            = DMA_PRIORITY_LOW;

  HAL_DMA_Init(&hdma_tx);

  /* Associate the initialized DMA handle to the UART handle */
  __HAL_LINKDMA(huart, hdmatx, hdma_tx);

  /* Configure the DMA handler for reception process */
  hdma_rx.Instance                 = USARTx_RX_DMA_STREAM;
  hdma_rx.Init.Channel             = USARTx_RX_DMA_CHANNEL;
  hdma_rx.Init.Direction           = DMA_PERIPH_TO_MEMORY;
  hdma_rx.Init.PeriphInc           = DMA_PINC_DISABLE;
  hdma_rx.Init.MemInc              = DMA_MINC_ENABLE;
  hdma_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
  hdma_rx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
  hdma_rx.Init.Mode                = DMA_NORMAL;
  hdma_rx.Init.Priority            = DMA_PRIORITY_HIGH;

  HAL_DMA_Init(&hdma_rx);

  /* Associate the initialized DMA handle to the the UART handle */
  __HAL_LINKDMA(huart, hdmarx, hdma_rx);
    
  /*##-4- Configure the NVIC for DMA #########################################*/
  /* NVIC configuration for DMA transfer complete interrupt (USART6_TX) */
  HAL_NVIC_SetPriority(USARTx_DMA_TX_IRQn, 0, 1);
  HAL_NVIC_EnableIRQ(USARTx_DMA_TX_IRQn);
    
  /* NVIC configuration for DMA transfer complete interrupt (USART6_RX) */
  HAL_NVIC_SetPriority(USARTx_DMA_RX_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(USARTx_DMA_RX_IRQn);
  
  /* NVIC for USART, to catch the TX complete */
  HAL_NVIC_SetPriority(USARTx_IRQn, 0, 1);
  HAL_NVIC_EnableIRQ(USARTx_IRQn);
}

/**
  * @brief UART MSP De-Initialization
  *        This function frees the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO, DMA and NVIC configuration to their default state
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart)
{

  /*##-1- Reset peripherals ##################################################*/
  USARTx_FORCE_RESET();
  USARTx_RELEASE_RESET();

  /*##-2- Disable peripherals and GPIO Clocks #################################*/
  /* Configure USARTx Tx as alternate function  */
  HAL_GPIO_DeInit(USARTx_TX_GPIO_PORT, USARTx_TX_PIN);
  /* Configure USARTx Rx as alternate function  */
  HAL_GPIO_DeInit(USARTx_RX_GPIO_PORT, USARTx_RX_PIN);
   
  /*##-3- Disable the DMA #####################################################*/
  /* De-Initialize the DMA channel associated to reception process */
  if(huart->hdmarx != 0)
  {
    HAL_DMA_DeInit(huart->hdmarx);
  }
  /* De-Initialize the DMA channel associated to transmission process */
  if(huart->hdmatx != 0)
  {
    HAL_DMA_DeInit(huart->hdmatx);
  }  
  
  /*##-4- Disable the NVIC for DMA ###########################################*/
  HAL_NVIC_DisableIRQ(USARTx_DMA_TX_IRQn);
  HAL_NVIC_DisableIRQ(USARTx_DMA_RX_IRQn);
}

#endif
