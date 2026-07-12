#ifndef RCC_H
#define RCC_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

    /* Public types */

    typedef enum
    {
        RCC_PERIPHERAL_AFIO = 0,
        RCC_PERIPHERAL_GPIOA,
        RCC_PERIPHERAL_GPIOB,
        RCC_PERIPHERAL_GPIOC,
        RCC_PERIPHERAL_GPIOD,
        RCC_PERIPHERAL_GPIOE

    } RCC_Peripheral_t;

    /* Enable peripheral clock */
    void RCC_EnablePeripheralClock(RCC_Peripheral_t peripheral);

    /* Disable peripheral clock */
    void RCC_DisablePeripheralClock(RCC_Peripheral_t peripheral);

#ifdef __cplusplus
}
#endif

#endif /* RCC_H */