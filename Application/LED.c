#include "gpio.h"

static void Delay(uint32_t count)
{
    while (count--)
    {
        __NOP();
    }
}

int main(void)
{
    GPIO_Config_t led =
        {
            .pin = GPIO_PIN_13,
            .mode = GPIO_MODE_OUTPUT_PP,
            .speed = GPIO_SPEED_2MHZ,
            .pull = GPIO_PULL_DOWN
        };

    GPIO_Init(GPIOC, &led);

    while (1)
    {
        /* PC13 LED is active-low. */
        GPIO_WritePin(
            GPIOC,
            GPIO_PIN_13,
            GPIO_PIN_RESET);

        Delay(800000);

        GPIO_WritePin(
            GPIOC,
            GPIO_PIN_13,
            GPIO_PIN_SET);

        Delay(800000);
    }
}