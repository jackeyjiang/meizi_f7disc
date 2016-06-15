//=====================================================================
#include "m_include.h"
#include "m_exti.h"
#include "m_gpio.h"
#include "m_pins.h"
#include "m_nvic.h"
//=====================================================================
#ifdef __cplusplus
    extern "C" {
#endif /* __cplusplus */
//=====================================================================
// exit 接口函数结构
typedef struct exti_channel {
    void  (*handler)(void);
    uint8 arg;
} exti_channel;
//
//=====================================================================
// exit 接口函数表
static exti_channel exti_channels[] = {
    { .handler = NULL, .arg = 0 },  // EXTI0
    { .handler = NULL, .arg = 1 },  // EXTI1
    { .handler = NULL, .arg = 2 },  // EXTI2
    { .handler = NULL, .arg = 3 },  // EXTI3
    { .handler = NULL, .arg = 4 },  // EXTI4
    { .handler = NULL, .arg = 5 },  // EXTI5
    { .handler = NULL, .arg = 6 },  // EXTI6
    { .handler = NULL, .arg = 7 },  // EXTI7
    { .handler = NULL, .arg = 8 },  // EXTI8
    { .handler = NULL, .arg = 9 },  // EXTI9
    { .handler = NULL, .arg = 10},  // EXTI10
    { .handler = NULL, .arg = 11},  // EXTI11
    { .handler = NULL, .arg = 12},  // EXTI12
    { .handler = NULL, .arg = 13},  // EXTI13
    { .handler = NULL, .arg = 14},  // EXTI14
    { .handler = NULL, .arg = 15},  // EXTI15
};
//
//=====================================================================
// exit 中断函数
static void dispatch_extis(uint32 start, uint32 stop) {
    uint32 pr = EXTI->PR;
    uint32 handled_msk = 0;

    for (uint32 exti = start; exti <= stop; exti++) {
        uint32 eb = (1U << exti);
        if ((pr & eb)==0)   continue;
        voidFuncPtr handler = exti_channels[exti].handler;
        handled_msk        |= eb;
        if (!handler)       continue;
        handler();
    }
    EXTI->PR = handled_msk;
}
//
//=====================================================================
// exit 中断函数
static  void dispatch_single_exti(uint32 exti) {
    voidFuncPtr handler = exti_channels[exti].handler;

    if (!handler)
        return;
    handler();
    EXTI->PR = (1U << exti);
}
//
//=====================================================================
// exit 中断函数
void EXTI0_IRQHandler(void)      {dispatch_single_exti(0);   }
void EXTI1_IRQHandler(void)      {dispatch_single_exti(1);   }
void EXTI2_IRQHandler(void)      {dispatch_single_exti(2);   }
void EXTI3_IRQHandler(void)      {dispatch_single_exti(3);   }
void EXTI4_IRQHandler(void)      {dispatch_single_exti(4);   }
void EXTI9_5_IRQHandler(void)    {dispatch_extis(5, 9);      }
void EXTI15_10_IRQHandler(void)  {dispatch_extis(10, 15);    }
#ifdef __cplusplus
}
#endif /* __cplusplus */
//=====================================================================
// 开始设定引脚中断
//=====================================================================
void c_exti::begin(uint8 pin, voidFuncPtr handler, exti_trigger_mode mode) {
    
    if (pin >= BOARD_NR_GPIO_PINS)
        return;
    
    uint8 num = PIN_MAP[pin].gpio_bit;
    //
    //========================================
    //-- 中断函数植入
    exti_channels[num].handler = handler;
    //
    //========================================
    
    //
    //========================================
    //-- 中断允许?
   
    //
    //========================================
    //-- 中断开启
    #if 1
    if (num < 5) {
        nvic.irqEnable((IRQn_Type)(EXTI0_IRQn + num));
    } else if (num < 10) {
        nvic.irqEnable(EXTI9_5_IRQn);
    } else {
        nvic.irqEnable(EXTI15_10_IRQn);
    }
    #endif
}
//
//=====================================================================
// 设定引脚中断模式
//=====================================================================
void  c_exti::setMode(uint8 pin, exti_trigger_mode mode) {
    uint8 num = PIN_MAP[pin].gpio_pin;
    switch (mode) {
    case EXTI_RISING:

        break;
    case EXTI_FALLING:

        break;
    case EXTI_RISING_FALLING:

        break;
    }
}
//
//=====================================================================
// 暂停
//=====================================================================
void c_exti::pause (uint8 pin ) {
    
}
//=====================================================================
// 开启
//=====================================================================
void c_exti::resume(uint8 pin) {
    
}
//=====================================================================
// 开始设定引脚中断
//=====================================================================
void c_exti::close(uint8 pin) {
    uint8 num = PIN_MAP[pin].gpio_pin;
    //
    //========================================
    //-- 中断关闭
    
    //========================================
    //-- 中断函数删除
    exti_channels[num].handler = NULL;
}
//=====================================================================
c_exti exti;
//
//=====================================================================
