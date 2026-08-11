#include "rcc.h"

void RCC_EnableClock(RCC_Periph_t periph)
{
    uint32_t bus = ((uint32_t)periph >> 8U) & 0xFFU;
    uint32_t bit = (uint32_t)periph & 0xFFU;

    uint32_t mask = 1UL << bit;

    switch (bus)
    {
    case RCC_BUS_AHB:
        RCC->AHBENR |= mask;
        break;

    case RCC_BUS_APB1:
        RCC->APB1ENR |= mask;
        break;

    case RCC_BUS_APB2:
        RCC->APB2ENR |= mask;
        break;

    default:
        /* Invalid peripheral encoding */
        break;
    }
}

void RCC_DisableClock(RCC_Periph_t periph)
{
    uint32_t bus = ((uint32_t)periph >> 8U) & 0xFFU;
    uint32_t bit = (uint32_t)periph & 0xFFU;

    uint32_t mask = 1UL << bit;

    switch (bus)
    {
    case RCC_BUS_AHB:
        RCC->AHBENR &= ~mask;
        break;

    case RCC_BUS_APB1:
        RCC->APB1ENR &= ~mask;
        break;

    case RCC_BUS_APB2:
        RCC->APB2ENR &= ~mask;
        break;

    default:
        /* Invalid peripheral encoding */
        break;
    }
}