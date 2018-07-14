#ifndef STM32F1_H
#define STM32F1_H

#define RCC_BASE	0x40021000
#define RCC_APB2ENR	(*(volatile unsigned long*) (RCC_BASE + 0x18))

#define GPIOC_BASE	0x40011000
#define GPIOC_CRL	(*(volatile unsigned long*) (GPIOC_BASE + 0x00))
#define GPIOC_CRH	(*(volatile unsigned long*) (GPIOC_BASE + 0x04))
#define GPIOC_ODR	(*(volatile unsigned long*) (GPIOC_BASE + 0x0c))
#define GPIOC_BSRR	(*(volatile unsigned long*) (GPIOC_BASE + 0x10))

#endif
