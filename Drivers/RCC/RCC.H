#ifndef RCC_H
#define RCC_H
#include "stm32f1xx.h"
#ifdef __cplusplus
extern "C"
{
#endif
#define BIT(x) (1UL << (x))

    typedef enum
    {

        RCC_PERIPH_AFIOEN = (0 << 8) | 0,
        RCC_PERIPH_IOPAEN = (0 << 8) | 2,
        RCC_PERIPH_IOPBEN = (0 << 8) | 3,
        RCC_PERIPH_IOPCEN = (0 << 8) | 4,
        RCC_PERIPH_IOPDEN = (0 << 8) | 5,

        RCC_PERIPH_TIM2EN = (1 << 8) | 0,
        RCC_PERIPH_USART2EN = (1 << 8) | 17,

        RCC_PERIPH_DMA1EN = (2 << 8) | 0

    } RCC_Periph_t;
    
    static inline void RCC_EnablePeriph(RCC_Periph_t periph)
    {
        uint8_t bus = (periph >> 8) & 0xFF;
        uint32_t bit = (1UL << (periph & 0xFF));
        switch (bus)
        {
        case 0:
            RCC->APB2ENR |= bit;
            break;
        case 1:
            RCC->APB1ENR |= bit;
            break;
        case 2:
            RCC->AHBENR |= bit;
            break;
        }
    }
    static inline void RCC_DisablePeriph(RCC_Periph_t periph)
    {
        uint8_t bus = (periph >> 8) & 0xFF;
        uint32_t bit = ~(1UL << (periph & 0xFF));
        switch (bus)
        {
        case 0:
            RCC->APB2ENR &= bit;
            break;
        case 1:
            RCC->APB1ENR &= bit;
            break;
        case 2:
            RCC->AHBENR &= bit;
            break;
        }
    }

#ifdef __cplusplus
}
#endif /*end of RCC_H*/
#endif