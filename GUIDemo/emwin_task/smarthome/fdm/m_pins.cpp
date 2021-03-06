//===============================================
#include "stm32f7xx_hal_gpio.h"
#include "m_include.h"
#include "m_pins.h"

//===============================================
extern const stm32_pin_info PIN_MAP[BOARD_NR_GPIO_PINS] = {
    /* AIN */
    {&gpioa, 0,  GPIO_PIN_0 , GPIO_MODE_IT_FALLING,  GPIO_PULLUP, GPIO_SPEED_MEDIUM, NULL}, /* A0/PA0  ->Z_MAX */

    {&gpiof, 10, GPIO_PIN_10, GPIO_MODE_ANALOG,  GPIO_NOPULL, GPIO_SPEED_HIGH    , NULL}, /* A1/PF10 ->ADC3_IN8 */
    {&gpiof, 9,  GPIO_PIN_9,  GPIO_MODE_ANALOG,  GPIO_NOPULL, GPIO_SPEED_HIGH    , NULL}, /* A2/PF9  ->ADC3_IN7 */
    {&gpiof, 8,  GPIO_PIN_8,  GPIO_MODE_ANALOG,  GPIO_NOPULL, GPIO_SPEED_HIGH    , NULL}, /* A3/PF8  ->ADC3_IN6 */

    {&gpiof, 7,  GPIO_PIN_7,   GPIO_MODE_IT_FALLING,  GPIO_PULLUP, GPIO_SPEED_MEDIUM    , NULL}, /* A4/PF7  ->X_MAX*/
    {&gpiof, 6,  GPIO_PIN_6,   GPIO_MODE_IT_FALLING,  GPIO_PULLUP, GPIO_SPEED_MEDIUM    , NULL}, /* A5/PF6  ->Y_MAX*/

    /* ARD_DIO 15~8 */
    {&gpiob, 8,  GPIO_PIN_8,  GPIO_MODE_OUTPUT_PP,  GPIO_PULLUP, GPIO_SPEED_MEDIUM, NULL}, /* ARD_D15/PB8  ->E_DIR*/
    {&gpiob, 9,  GPIO_PIN_9,  GPIO_MODE_OUTPUT_PP,  GPIO_PULLUP, GPIO_SPEED_MEDIUM, NULL}, /* ARD_D14/PB9  ->E_STEP*/

    {&gpioi, 1,  GPIO_PIN_1,  GPIO_MODE_IT_FALLING,   GPIO_PULLUP, GPIO_SPEED_MEDIUM, NULL}, /* ARD_D13/PI1  ->X_MIN*/
    {&gpiob, 14, GPIO_PIN_14, GPIO_MODE_IT_FALLING,   GPIO_PULLUP, GPIO_SPEED_MEDIUM, NULL}, /* ARD_D12/PB14 ->Y_MIN*/
    {&gpiob, 15, GPIO_PIN_15, GPIO_MODE_IT_FALLING,   GPIO_PULLUP, GPIO_SPEED_MEDIUM, NULL}, /* ARD_D11/PB15 ->Z_MIN*/

    {&gpioa, 8 , GPIO_PIN_8,  GPIO_MODE_OUTPUT_PP,  GPIO_PULLUP, GPIO_SPEED_HIGH,     NULL}, /* ARD_D10/PA8  ->EXTRUDER_PWM */
    {&gpioa, 15, GPIO_PIN_15, GPIO_MODE_OUTPUT_PP,  GPIO_PULLUP, GPIO_SPEED_HIGH,     NULL}, /* ARD_D9 /PA15 ->BED_PWN */

    {&gpioi, 2,  GPIO_PIN_2,  GPIO_MODE_OUTPUT_PP,  GPIO_PULLUP, GPIO_SPEED_MEDIUM,   NULL}, /* ARD_D8 /PI2  ->XYZE_EN */

    /* ARD_DIO 7~0 */
    {&gpioi, 3,  GPIO_PIN_3,  GPIO_MODE_OUTPUT_PP,  GPIO_PULLUP, GPIO_SPEED_HIGH,     NULL}, /* ARD_D7 /PI3 ->Z_DIR */
    {&gpioh, 6,  GPIO_PIN_6,  GPIO_MODE_OUTPUT_PP,  GPIO_PULLUP, GPIO_SPEED_HIGH,     NULL}, /* ARD_D6 /PH6 ->Y_DIR */
    {&gpioi, 0,  GPIO_PIN_0,  GPIO_MODE_OUTPUT_PP,  GPIO_PULLUP, GPIO_SPEED_HIGH,     NULL}, /* ARD_D5 /PI0 ->X_DIR */
    {&gpiog, 7,  GPIO_PIN_7,  GPIO_MODE_OUTPUT_PP,  GPIO_PULLUP, GPIO_SPEED_HIGH,     NULL}, /* ARD_D4 /PG7 ->Z_STEP */
    {&gpiob, 4,  GPIO_PIN_4,  GPIO_MODE_OUTPUT_PP,  GPIO_PULLUP, GPIO_SPEED_HIGH,     NULL}, /* ARD_D3 /PB4 ->Y_STEP */
    {&gpiog, 6,  GPIO_PIN_6,  GPIO_MODE_OUTPUT_PP,  GPIO_PULLUP, GPIO_SPEED_HIGH,     NULL}, /* ARD_D2 /PG6 ->X_STEP */

    {&gpioc, 6,  GPIO_PIN_6,  GPIO_MODE_AF_PP,   GPIO_NOPULL, GPIO_SPEED_HIGH, GPIO_AF8_USART6}, /* ARD_D1 /PC6 ->USART6_TX */
    {&gpioc, 7,  GPIO_PIN_7,  GPIO_MODE_AF_PP,   GPIO_NOPULL, GPIO_SPEED_HIGH, GPIO_AF8_USART6}, /* ARD_D0 /PC7 ->USART6_RX */


};
