//================================================================
#ifndef __M_GPIO_H__
#define __M_GPIO_H__
//================================================================
#include "stdint.h"
#include "stm32f746xx.h"
#include "stm32f7xx_hal_gpio.h"
#include "typeDefine.h"
//================================================================
typedef enum WiringPinMode {
    OUTPUT, 
    OUTPUT_OPEN_DRAIN,
    OUTPUT_AF_OD,
    OUTPUT_AF_PP,
    INPUT, 
    INPUT_ANALOG, 
    INPUT_PULLUP,
    INPUT_PULLDOWN, 
    INPUT_FLOATING, 
    PWM, 
    PWM_OPEN_DRAIN, 
} WiringPinMode;

typedef enum gpio_pin_mode {
    GPIO_OUTPUT_PP      = GPIO_MODE_OUTPUT_PP | GPIO_SPEED_FAST,        /** Output push-pull. */
    GPIO_OUTPUT_OD      = GPIO_MODE_OUTPUT_OD | GPIO_SPEED_FAST,        /** Output open-drain. */
    GPIO_AF_OUTPUT_PP   = GPIO_MODE_AF_PP | GPIO_SPEED_FAST,     /** Alternate function output push-pull. */
    GPIO_AF_OUTPUT_OD   = GPIO_MODE_AF_OD | GPIO_SPEED_FAST,     /** Alternate function output open drain. */
    GPIO_INPUT_ANALOG   = GPIO_MODE_ANALOG | GPIO_MODE_INPUT,            /** Analog input. */
    GPIO_INPUT_FLOATING = GPIO_MODE_INPUT | GPIO_NOPULL,          /** Input floating. */
    GPIO_INPUT_PD       = GPIO_MODE_INPUT | GPIO_PULLDOWN,             /** Input pull-down. */
    GPIO_INPUT_PU       = GPIO_MODE_INPUT | GPIO_PULLUP,                                              
} gpio_pin_mode;

typedef struct gpio_dev {
    GPIO_TypeDef    *regs;       /**< Register map */
} gpio_dev;
//================================================================
//
//================================================================
class c_gpio {
public:
    c_gpio  (gpio_dev *);
    void    setPinMode          (uint8 pin);
    void    setPwmFormat        (uint8 pin, uint16 Period, uint8 active);
    void    setPwmDuty          (uint8 pin, uint16 duty  );
    uint16  getPwmPeriod        (uint8 pin);
    boolean digitalRead         (uint8 pin);
    void    digitalWrite        (uint8 pin, uint8 val);
    void    toggle              (uint8 pin);
    uint8   isButtonPressed     (uint8 pin, uint32 pressedLevel);
    uint8   waitForButtonPress  (uint8 pin, uint32 pressedLevel, uint32 timeout);
private:
    inline uint32   gpio_read_bit  (gpio_dev *dev, uint8 pin);
    inline void     gpio_write_bit (gpio_dev *dev, uint8 pin, uint8 val);
    inline void     gpio_toggle_bit(gpio_dev *dev, uint8 pin);
    inline void     gpio_set_mode  (gpio_dev *dev, uint8 pin, gpio_pin_mode mode);
};
extern c_gpio gpio;
extern gpio_dev gpioa;
extern gpio_dev gpiob;
extern gpio_dev gpioc;
extern gpio_dev gpiod;
extern gpio_dev gpioe;
extern gpio_dev gpiof;
extern gpio_dev gpiog;
extern gpio_dev gpioh;
extern gpio_dev gpioi;
//================================================================
#endif
//================================================================

