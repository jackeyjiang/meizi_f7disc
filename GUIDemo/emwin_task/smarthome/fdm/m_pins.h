//=========================================================================
#ifndef __M_PINS_H__
#define __M_PINS_H__

#include "m_gpio.h"
//=========================================================================
/* 72 MHz -> 72 cycles per microsecond. */
#define CYCLES_PER_MICROSECOND  200000
/* Pin number for the built-in button. */
#define BOARD_BUTTON_PIN        PI11
/* Pin number for the built-in LED. */
#define BOARD_LED_PIN           PI3
/* Number of USARTs/UARTs whose pins are broken out to headers. */
#define BOARD_NR_USARTS         1
/* USART pin numbers. */
#define BOARD_USART6_TX_PIN     PC6
#define BOARD_USART6_RX_PIN     PC7

/* Total number of GPIO pins that are broken out to headers and
 * intended for use. This includes pins like the LED, button, and
 * debug port (JTAG/SWD) pins. */
#define BOARD_NR_GPIO_PINS      PNUM
/* Number of pins capable of PWM output. */
#define BOARD_NR_PWM_PINS       2
/* Number of pins capable of ADC conversion. */
#define BOARD_NR_ADC_PINS       3

/* Pin aliases: these give the GPIO port/bit for each pin as an
 * enum. These are optional, but recommended. They make it easier to
 * write code using low-level GPIO functionality. */
enum {
    PA0, PF10, PF9, PF8, PF7, PF6,  //A0 ~ A5
    PB8, PB9, PI10, PB14, PB15, PA8, PA15, PI2, //ARD_D15 ~ ARD_D8
    PI3, PH6, PI0, PG7, PB4, PG6, PC6, PC7,  //ARD_D7 ~ ARD_D0
    PI11 ,PNUM//B_USER
};
typedef struct stm32_pin_info {
    gpio_dev        *gpio_device;       /**< Maple pin's GPIO device */
    uint16_t        gpio_bit;           /**< Pin's GPIO port bit. */
    uint16_t        gpio_pin;           /**< Pin's GPIO port pin. */
    uint32_t        gpio_mode;          /**< Pin's GPIO port mode. */
    uint32_t        gpio_pull;          /**< Pin's GPIO port pull. */
    uint32_t        gpio_speed;         /**< Pin's GPIO port speed. */
    uint32_t        gpio_alternate;     /**< Pin's GPIO port alternatei. */
} stm32_pin_info;
extern const stm32_pin_info PIN_MAP[BOARD_NR_GPIO_PINS];
/* Makes the PIN_MAP rows more human-readable. */

#endif

