//=============================================================
#ifndef __STD_HARDWARESERIAL_H__
#define __STD_HARDWARESERIAL_H__
//=============================================================
#include "stdint.h"
#include "stm32f746xx.h"
#include "stm32f7xx_hal_dma.h"
#include "m_Print.h"
#include "cmsis_os.h"
#include "typeDefine.h"
#include "m_ringBuffer.h"
#include "sysConf.h"

//=============================================================
#if 1
typedef struct usart_dev {
    USART_TypeDef           *reg;
    IRQn_Type               txDmaIrq;
    IRQn_Type               rxDmaIrq;
    DMA_Stream_TypeDef *    rxDma;
    DMA_Stream_TypeDef *    txDma;
    uint8                   rxPin;
    uint8                   txPin;
    char *                  rxBuf;
    char *                  txBuf;
    uint16                  rxSize;
    uint16                  txSize;
}usart_dev;
#endif
class serial : public Print {
public:
    serial(usart_dev* udev);
    void setSem(void);
    osSemaphoreId semTxReady;
    osSemaphoreId semRxReady;
public:
    /* I/O */
    void    begin(void);
    uint8   read(void);
    void    end(void);
    uint32  available(void);
    virtual void write(uint8  );
    virtual void write(uint8 *);
    void    waitTxFinish()   {txFinish=false; while(!txFinish) osDelay(1);}
    using   Print::write;
    void    flush(void);
    void    rxIsr();
    void    txIsr();
private:
    void    dmaTxFxn(void);
    usart_dev *usart_device;
    uint16  txHead;
    uint16  txTail;
    uint16  rxPos;
    BOOL    txFinish;
    uint32  band;
    ring_buffer     rxRingbuf;
    ring_buffer     txRingbuf;
    uint8_t txBuf   [USB_SERIAL_TX_LENGTH];
    uint8_t rxBuf   [USB_SERIAL_RX_LENGTH];
};
//================================================================
#if SERIAL1_USE == TRUE
extern serial serial1;
#endif
#if SERIAL2_USE == TRUE
extern serial serial2;
#endif
#ifdef __cplusplus
extern "C" {
#endif
void __irq_dma1_channel4(void);
void __irq_dma1_channel7(void);
#ifdef __cplusplus
}
#endif

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* User can use this section to tailor USARTx/UARTx instance used and associated 
   resources */
/* Definition for USARTx clock resources */
#define USARTx                           USART6
#define USARTx_CLK_ENABLE()              __USART6_CLK_ENABLE()
#define DMAx_CLK_ENABLE()                __HAL_RCC_DMA2_CLK_ENABLE()
#define USARTx_RX_GPIO_CLK_ENABLE()      __GPIOC_CLK_ENABLE()
#define USARTx_TX_GPIO_CLK_ENABLE()      __GPIOC_CLK_ENABLE()

#define USARTx_FORCE_RESET()             __USART6_FORCE_RESET()
#define USARTx_RELEASE_RESET()           __USART6_RELEASE_RESET()

/* Definition for USARTx Pins */
#define USARTx_TX_PIN                    GPIO_PIN_6
#define USARTx_TX_GPIO_PORT              GPIOC
#define USARTx_TX_AF                     GPIO_AF8_USART6
#define USARTx_RX_PIN                    GPIO_PIN_7
#define USARTx_RX_GPIO_PORT              GPIOC
#define USARTx_RX_AF                     GPIO_AF8_USART6

/* Definition for USARTx's DMA */
#define USARTx_TX_DMA_STREAM              DMA2_Stream6
#define USARTx_RX_DMA_STREAM              DMA2_Stream1
#define USARTx_TX_DMA_CHANNEL             DMA_CHANNEL_5
#define USARTx_RX_DMA_CHANNEL             DMA_CHANNEL_5


/* Definition for USARTx's NVIC */
#define USARTx_DMA_TX_IRQn                DMA2_Stream6_IRQn
#define USARTx_DMA_RX_IRQn                DMA2_Stream1_IRQn
#define USARTx_DMA_TX_IRQHandler          DMA2_Stream6_IRQHandler
#define USARTx_DMA_RX_IRQHandler          DMA2_Stream1_IRQHandler

/* Definition for USARTx's NVIC */
#define USARTx_IRQn                      USART6_IRQn
#define USARTx_IRQHandler                USART6_IRQHandler

/* Size of Trasmission buffer */
#define TXBUFFERSIZE                      (COUNTOF(aTxBuffer) - 1)
/* Size of Reception buffer */
#define RXBUFFERSIZE                      TXBUFFERSIZE
  
/* Exported macro ------------------------------------------------------------*/
#define COUNTOF(__BUFFER__)   (sizeof(__BUFFER__) / sizeof(*(__BUFFER__)))
/* Exported functions ------------------------------------------------------- */

#endif

