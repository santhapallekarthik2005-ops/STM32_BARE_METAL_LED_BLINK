#include "gpio.h"
#include "rcc.h"

/* Return the RCC clock associated with a GPIO port. */
static RCC_Periph_t GPIO_GetRCCPeriph(GPIO_TypeDef *port)
{
    if (port == GPIOA)
        return RCC_PERIPH_IOPAEN;

    if (port == GPIOB)
        return RCC_PERIPH_IOPBEN;

    if (port == GPIOC)
        return RCC_PERIPH_IOPCEN;

    return RCC_PERIPH_IOPDEN;
}

/*
 * Convert the logical GPIO configuration into the
 * STM32F1 CRL/CRH 4-bit MODE + CNF value.
 */
static uint32_t GPIO_GetConfigBits(
    GPIO_Mode_t mode,
    GPIO_Speed_t speed)
{
    switch (mode)
    {
    case GPIO_MODE_INPUT_ANALOG:
        return 0x0U;

    case GPIO_MODE_INPUT_FLOAT:
        return 0x4U;

    case GPIO_MODE_INPUT_PULL:
        return 0x8U;

    case GPIO_MODE_OUTPUT_PP:

        if (speed == GPIO_SPEED_2MHZ)
            return 0x2U;

        if (speed == GPIO_SPEED_10MHZ)
            return 0x1U;

        return 0x3U; /* 50 MHz */

    case GPIO_MODE_OUTPUT_OD:

        if (speed == GPIO_SPEED_2MHZ)
            return 0x6U;

        if (speed == GPIO_SPEED_10MHZ)
            return 0x5U;

        return 0x7U; /* 50 MHz */

    case GPIO_MODE_AF_PUSH_PULL:

        if (speed == GPIO_SPEED_2MHZ)
            return 0xAU;

        if (speed == GPIO_SPEED_10MHZ)
            return 0x9U;

        return 0xBU; /* 50 MHz */

    case GPIO_MODE_AF_OD:

        if (speed == GPIO_SPEED_2MHZ)
            return 0xEU;

        if (speed == GPIO_SPEED_10MHZ)
            return 0xDU;

        return 0xFU; /* 50 MHz */

    default:
        return 0x0U;
    }
}

/* Configure one GPIO pin. */
void GPIO_Init(
    GPIO_TypeDef *port,
    const GPIO_Config_t *config)
{
    /* Enable the GPIO peripheral clock. */
    RCC_EnableClock(GPIO_GetRCCPeriph(port));

    /*
     * STM32F1:
     *     Pins 0-7  -> CRL
     *     Pins 8-15 -> CRH
     */
    volatile uint32_t *cr =
        (config->pin <= GPIO_PIN_7)
            ? &port->CRL
            : &port->CRH;

    /*
     * Each GPIO pin occupies 4 bits.
     */
    uint32_t shift =
        ((uint32_t)config->pin % 8U) * 4U;

    /* Convert our API configuration to STM32 register encoding. */
    uint32_t config_bits =
        GPIO_GetConfigBits(
            config->mode,
            config->speed);

    /* Clear the old 4-bit configuration. */
    *cr &= ~(0xFU << shift);

    /* Write the new configuration. */
    *cr |= (config_bits << shift);

    /*
     * STM32F1 input pull-up/pull-down:
     *
     * ODR = 1 -> pull-up
     * ODR = 0 -> pull-down
     *
     * BSRR is used here to change the ODR latch without
     * directly performing an ODR read-modify-write.
     */
    if (config->mode == GPIO_MODE_INPUT_PULL)
    {
        if (config->pull == GPIO_PULL_UP)
        {
            port->BSRR = (1UL << config->pin);
        }
        else
        {
            port->BSRR = (1UL << (config->pin + 16U));
        }
    }
}

/* Set or reset a GPIO output using BSRR. */
void GPIO_WritePin(
    GPIO_TypeDef *port,
    GPIO_Pin_t pin,
    GPIO_PinState_t state)
{
    if (state == GPIO_PIN_SET)
    {
        /* BSRR bits 0-15 set the corresponding pin. */
        port->BSRR = (1UL << pin);
    }
    else
    {
        /* BSRR bits 16-31 reset the corresponding pin. */
        port->BSRR = (1UL << (pin + 16U));
    }
}

/* Toggle a GPIO output using IDR + BSRR. */
void GPIO_TogglePin(
    GPIO_TypeDef *port,
    GPIO_Pin_t pin)
{
    if (port->IDR & (1UL << pin))
    {
        /* Pin is HIGH -> reset it. */
        port->BSRR = (1UL << (pin + 16U));
    }
    else
    {
        /* Pin is LOW -> set it. */
        port->BSRR = (1UL << pin);
    }
}

/* Read the current GPIO pin state. */
GPIO_PinState_t GPIO_ReadPin(
    GPIO_TypeDef *port,
    GPIO_Pin_t pin)
{
    if (port->IDR & (1UL << pin))
    {
        return GPIO_PIN_SET;
    }

    return GPIO_PIN_RESET;
}