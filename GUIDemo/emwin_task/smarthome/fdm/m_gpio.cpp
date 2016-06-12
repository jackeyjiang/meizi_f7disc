//===============================================
#include "m_include.h"
#include "stm32f7xx_hal_gpio.h"
#include "m_gpio.h"
#include "m_pins.h"
//===============================================
gpio_dev gpioa = {.regs = (GPIO_TypeDef  *)GPIOA_BASE};
gpio_dev gpiob = {.regs = (GPIO_TypeDef  *)GPIOB_BASE};
gpio_dev gpioc = {.regs = (GPIO_TypeDef  *)GPIOC_BASE};
gpio_dev gpiod = {.regs = (GPIO_TypeDef  *)GPIOD_BASE};
gpio_dev gpioe = {.regs = (GPIO_TypeDef  *)GPIOE_BASE};
gpio_dev gpiof = {.regs = (GPIO_TypeDef  *)GPIOF_BASE};
gpio_dev gpiog = {.regs = (GPIO_TypeDef  *)GPIOG_BASE};
gpio_dev gpioh = {.regs = (GPIO_TypeDef  *)GPIOH_BASE};
gpio_dev gpioi = {.regs = (GPIO_TypeDef  *)GPIOI_BASE};
c_gpio gpio(&gpioa);
//=======================================
//== 
//=======================================
c_gpio::c_gpio(gpio_dev *) {
    // 新建class无意义
}

//=======================================
//== 读取数据 =
//=======================================
inline uint32 c_gpio::gpio_read_bit(gpio_dev *dev, uint8 pin) {
    return dev->regs->IDR & 1<<pin;
}

//=======================================
//== 写入数据 =
//=======================================
inline void     c_gpio::gpio_write_bit(gpio_dev *dev, uint8 pin, uint8 val) {
    //(val != LOW) ? (dev->regs->BSRR = 1<<pin) : (dev->regs->BRR = 1<<pin);
}

//=======================================
//== 翻转数据 =
//=======================================
inline void     c_gpio::gpio_toggle_bit(gpio_dev *dev, uint8 pin) {
    //dev->regs->ODR = dev->regs->ODR ^ (1U << pin);
}

//=======================================
//== 根据map表操作 读
//=======================================
boolean c_gpio::digitalRead(uint8 pin) {
    //return gpio_read_bit(PIN_MAP[pin].gpio_device, PIN_MAP[pin].gpio_bit) ?
    //    HIGH : LOW;
}

//=======================================
//== 根据map 表操作 写
//=======================================
void c_gpio::digitalWrite(uint8 pin, uint8 val) {
    //gpio_write_bit(PIN_MAP[pin].gpio_device, PIN_MAP[pin].gpio_bit, val);
}

//=======================================
//== 根据map 表操作 翻转
//=======================================
void c_gpio::toggle(uint8 pin) {
    //gpio_toggle_bit(PIN_MAP[pin].gpio_device, PIN_MAP[pin].gpio_bit);
}
//=======================================
//== 设定引脚
//=======================================
void c_gpio::gpio_set_mode(gpio_dev *dev, uint8 pin, gpio_pin_mode mode) {
//    GPIO_TypeDef *regs = dev->regs;
//    __io uint32 *cr = &regs->CRL + (pin >> 3);
//    uint32 shift = (pin & 0x7) * 4;
//    uint32 tmp = *cr;

//    tmp &= ~(0xF << shift);
//    tmp |= (mode == GPIO_INPUT_PU ? GPIO_INPUT_PD : mode) << shift;
//    *cr = tmp;

//    if (mode == GPIO_INPUT_PD) {
//        regs->ODR &= ~(1U << pin);
//    } else if (mode == GPIO_INPUT_PU) {
//        regs->ODR |= (1U << pin);
//    }
}
//=======================================
//== pwm 引脚初始化
//=======================================
void c_gpio::setPwmFormat (uint8 pin, uint16 Period, uint8 active) {
//    Timer.setPeriod  (PIN_MAP[pin].timer_device, Period);
//    Timer.setOcActive(PIN_MAP[pin].timer_device, PIN_MAP[pin].timer_channel, active);
}

//=======================================
//== pwm 读取周期值
//=======================================
uint16 c_gpio::getPwmPeriod (uint8 pin) {
    //return Timer.getOverflow (PIN_MAP[pin].timer_device);
}

//=======================================
//== pwm 设定定时值
//=======================================
void c_gpio::setPwmDuty (uint8 pin, uint16 duty  ) {
    //Timer.setCompare(PIN_MAP[pin].timer_device, PIN_MAP[pin].timer_channel, duty); 
}

//=======================================
//== 根据map 表操作 引脚模式
//=======================================
void c_gpio::setPinMode(uint8 pin) {
    BOOL pwm = false;
    gpio_pin_mode    outputMode;
    GPIO_InitTypeDef gpio_init_structure;
    
    if (pin >= BOARD_NR_GPIO_PINS)
        return;
     
    gpio_init_structure.Pin       = PIN_MAP[pin].gpio_pin;    
    gpio_init_structure.Mode      = PIN_MAP[pin].gpio_mode;
    gpio_init_structure.Pull      = PIN_MAP[pin].gpio_pull;
    gpio_init_structure.Speed     = PIN_MAP[pin].gpio_speed;
    gpio_init_structure.Alternate = PIN_MAP[pin].gpio_alternate;
    
    HAL_GPIO_Init(PIN_MAP[pin].gpio_device->regs,&gpio_init_structure);
    
    
//    if (PIN_MAP[pin].timer_device != NULL) {
//        Timer.setPinMode(PIN_MAP[pin].timer_device,  PIN_MAP[pin].timer_channel,
//                         pwm ? TIMER_PWM : TIMER_DISABLED);
//    }
}
//=======================================
#define BUTTON_DEBOUNCE_DELAY 1
uint8 c_gpio::isButtonPressed(uint8 pin, uint32 pressedLevel) {
    if (digitalRead(pin) == pressedLevel) {
        osDelay(BUTTON_DEBOUNCE_DELAY);
        while (digitalRead(pin) == pressedLevel)
            ;
        return true;
    }
    return false;
}

//=======================================
uint8 c_gpio::waitForButtonPress(uint8 pin, uint32 pressedLevel, uint32 timeout) {
    uint32 start = osKernelSysTick();
    uint32 time;
    if (timeout == 0) {
        while (!isButtonPressed(pin, pressedLevel))
            ;
        return true;
    }
    do {
        time = osKernelSysTick();
        if ((osKernelSysTick()-time)>timeout) {
            return false;
        }
    } while (!isButtonPressed(pin, pressedLevel));
    return true;
}

//=======================================
