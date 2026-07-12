#include "rcclock.h"
void RCC_EnablePeripheralClock(RCC_Peripheral_t peripheral)
{
    switch (peripheral)
    {
    case RCC_PERIPHERAL_AFIO:
        RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
        break;

    case RCC_PERIPHERAL_GPIOA:
        RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
        break;

    case RCC_PERIPHERAL_GPIOB:
        RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
        break;

    case RCC_PERIPHERAL_GPIOC:
        RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
        break;

    case RCC_PERIPHERAL_GPIOD:
        RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;
        break;

    case RCC_PERIPHERAL_GPIOE:
        RCC->APB2ENR |= RCC_APB2ENR_IOPEEN;
        break;

    default:
        /* Invalid peripheral.
            version 1: ignore values.
            */

        break;
    }
}
