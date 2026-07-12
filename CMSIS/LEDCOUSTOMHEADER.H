#ifndef STM32_H
#define STM32_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#define __IO volatile      /* read / write */
#define __I volatile const /*read only*/
#define __O volatile       /*write only*/
/*peripheral base + offset */
/*Bus base - peripheral base */
#define PERIPH_BASE (0x40000000UL)
#define APB1PERIPH_BASE (PERIPH_BASE + 0x00000000UL) /*APB1 - PERIPHERAL BASE*/
#define APB2PERIPH_BASE (PERIPH_BASE + 0x00010000UL) /*APB2 - PERIPHERAL BASE*/
#define AHBPERIPH_BASE (PERIPH_BASE + 0x00018000UL)

/*PERIPHERAL BASE ADDRESSES*/
#define AFIO_BASE (APB2PERIPH_BASE + 0x00000000UL)
#define EXTI_BASE (APB2PERIPH_BASE + 0x00000400UL)
#define GPIOA_BASE (APB2PERIPH_BASE + 0x00000800UL)
#define GPIOB_BASE (APB2PERIPH_BASE + 0x00000C00UL)
#define GPIOC_BASE (APB2PERIPH_BASE + 0x00001000UL)

/*RCC BASE ADDRESS*/
#define RCC_BASE (AHBPERIPH_BASE + 0x00009000UL)

    typedef struct
    {
        __IO uint32_t CRL;
        __IO uint32_t CRH;
        __I uint32_t IDR;
        __IO uint32_t ODR;
        __O uint32_t BSRR;
        __O uint32_t BRR;
        __IO uint32_t LCKR;

    } GPIO_TypeDef;

    typedef struct
    {
        __IO uint32_t CR;
        __IO uint32_t CFGR;
        __IO uint32_t CIR;
        __IO uint32_t APB2RSTR;
        __IO uint32_t APB1RSTR;
        __IO uint32_t AHBENR;
        __IO uint32_t APB2ENR;
        __IO uint32_t APB1ENR;
        __IO uint32_t BDCR;
        __IO uint32_t CSR;
        uint32_t RESERVED0; /*reserved (0x28)*/
        __IO uint32_t CFGR2;
    } RCC_TypeDef;
#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *)GPIOC_BASE)
#define RCC ((RCC_TypeDef *)RCC_BASE)

#ifdef __cplusplus
}
#endif
#endif /*stm32 end*/