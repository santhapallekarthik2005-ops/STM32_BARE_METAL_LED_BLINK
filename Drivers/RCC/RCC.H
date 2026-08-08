#ifndef RCC_H
#define RCC_H
#include "stm32f1xx.h"
/*defining bus and bit */

#define RCC_PERIPH_DEF (bus, bit)(((bus) << 8 ) | (bit) )

    typedef enum
    {
        /**/
        RCC_PERIPH_AFIOEN       = (0 << 0 ),
        RCC_PERIPH_IOPAEN       = (0 << 2 ),
        RCC_PERIPH_IOPBEN       = (0 << 3 ),
        RCC_PERIPH_IOPCEN       = (0 << 4 ),
        RCC_PERIPH_IOPDEN       = (0 << 5 ),


        RCC_PERIPH_TIM2EN       = (1 << 0 ),
        RCC_PERIPH_USART2EN     = (1 << 17),

        RCC_PERIPH_DMA1EN       = (2 << 0 )

    } RCC_Periph_t;

  


#endif