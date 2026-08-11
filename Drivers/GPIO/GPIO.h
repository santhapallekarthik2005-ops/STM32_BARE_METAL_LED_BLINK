#ifndef GPIO_H
#define GPIO_H

#include "stm32f1xx.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /* GPIO pin number */
    typedef enum
    {
        GPIO_PIN_0 = 0,
        GPIO_PIN_1,
        GPIO_PIN_2,
        GPIO_PIN_3,
        GPIO_PIN_4,
        GPIO_PIN_5,
        GPIO_PIN_6,
        GPIO_PIN_7,
        GPIO_PIN_8,
        GPIO_PIN_9,
        GPIO_PIN_10,
        GPIO_PIN_11,
        GPIO_PIN_12,
        GPIO_PIN_13,
        GPIO_PIN_14,
        GPIO_PIN_15

    } GPIO_Pin_t;

    /* GPIO operating mode */
    typedef enum
    {
        GPIO_MODE_INPUT_ANALOG,
        GPIO_MODE_INPUT_FLOAT,
        GPIO_MODE_INPUT_PULL,

        GPIO_MODE_OUTPUT_PP,
        GPIO_MODE_OUTPUT_OD,

        GPIO_MODE_AF_PUSH_PULL,
        GPIO_MODE_AF_OD

    } GPIO_Mode_t;

    /* GPIO output speed */
    typedef enum
    {
        GPIO_SPEED_2MHZ,
        GPIO_SPEED_10MHZ,
        GPIO_SPEED_50MHZ

    } GPIO_Speed_t;

    /* Input pull direction */
    typedef enum
    {
        GPIO_PULL_DOWN = 0,
        GPIO_PULL_UP = 1

    } GPIO_Pull_t;

    /* GPIO logic state */
    typedef enum
    {
        GPIO_PIN_RESET = 0,
        GPIO_PIN_SET = 1

    } GPIO_PinState_t;

    /* GPIO configuration */
    typedef struct
    {
        GPIO_Pin_t pin;
        GPIO_Mode_t mode;
        GPIO_Speed_t speed;
        GPIO_Pull_t pull;

    } GPIO_Config_t;

    /* Configure one GPIO pin */
    void GPIO_Init(
        GPIO_TypeDef *port,
        const GPIO_Config_t *config);

    /* Set or reset a GPIO output */
    void GPIO_WritePin(
        GPIO_TypeDef *port,
        GPIO_Pin_t pin,
        GPIO_PinState_t state);

    /* Toggle a GPIO output */
    void GPIO_TogglePin(
        GPIO_TypeDef *port,
        GPIO_Pin_t pin);

    /* Read GPIO input state */
    GPIO_PinState_t GPIO_ReadPin(
        GPIO_TypeDef *port,
        GPIO_Pin_t pin);

#ifdef __cplusplus
}
#endif

#endif /* GPIO_H */