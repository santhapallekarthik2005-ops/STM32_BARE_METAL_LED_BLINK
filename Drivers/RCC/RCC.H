#ifndef RCC_H
#define RCC_H

#include "stm32f1xx.h"

/*
 * Peripheral encoding:
 *
 * [15:8] = RCC bus
 * [7:0]  = enable bit
 */
#define RCC_PERIPH_DEF(bus, bit) \
    (((uint32_t)(bus) << 8U) | (uint32_t)(bit))

/* RCC bus IDs */
#define RCC_BUS_AHB 0U
#define RCC_BUS_APB1 1U
#define RCC_BUS_APB2 2U

typedef enum
{
    RCC_PERIPH_AFIOEN = RCC_PERIPH_DEF(RCC_BUS_APB2, 0U),

    RCC_PERIPH_IOPAEN = RCC_PERIPH_DEF(RCC_BUS_APB2, 2U),
    RCC_PERIPH_IOPBEN = RCC_PERIPH_DEF(RCC_BUS_APB2, 3U),
    RCC_PERIPH_IOPCEN = RCC_PERIPH_DEF(RCC_BUS_APB2, 4U),
    RCC_PERIPH_IOPDEN = RCC_PERIPH_DEF(RCC_BUS_APB2, 5U),

    RCC_PERIPH_TIM2EN = RCC_PERIPH_DEF(RCC_BUS_APB1, 0U),
    RCC_PERIPH_USART2EN = RCC_PERIPH_DEF(RCC_BUS_APB1, 17U),

    RCC_PERIPH_DMA1EN = RCC_PERIPH_DEF(RCC_BUS_AHB, 0U)

} RCC_Periph_t;

/* Enable peripheral clock */
void RCC_EnableClock(RCC_Periph_t periph);

/* Disable peripheral clock */
void RCC_DisableClock(RCC_Periph_t periph);

#endif /* RCC_H */