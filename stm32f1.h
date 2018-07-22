#ifndef STM32F1_H
#define STM32F1_H

/*
 * General purpose IO registers
 */
struct reg_gpio {
	volatile unsigned long crl;
	volatile unsigned long crh;
	volatile unsigned long idr;
	volatile unsigned long odr;
	volatile unsigned long bssr;
	volatile unsigned long brr;
	volatile unsigned long lckr;
};

/*
 * Memory mapped general purpose IO registers struct
 */
#define GPIOA	(*(struct reg_gpio *) 0x40010800)
#define GPIOB	(*(struct reg_gpio *) 0x40010C00)
#define GPIOC	(*(struct reg_gpio *) 0x40011000)
#define GPIOD	(*(struct reg_gpio *) 0x40011400)
#define GPIOE	(*(struct reg_gpio *) 0x40011800)
#define GPIOF	(*(struct reg_gpio *) 0x40011C00)
#define GPIOG	(*(struct reg_gpio *) 0x40012000)

/*
 * Alternate function IO registers
 */
struct reg_afio {
	volatile unsigned long evcr;
	volatile unsigned long mapr;
	volatile unsigned long exticr1;
	volatile unsigned long exticr2;
	volatile unsigned long exticr3;
	volatile unsigned long exticr4;
	volatile unsigned long mapr2;
};

/*
 * Memory mapped alternate function IO registers struct
 */
#define AFIO	(*(struct reg_afio *) 0x40010000)

/*
 * Reset and clock control registers
 */
struct reg_reset_clock_control {
	volatile unsigned long cr;
	volatile unsigned long cfgr;
	volatile unsigned long cir;
	volatile unsigned long apb2rstr;
	volatile unsigned long apb1rstr;
	volatile unsigned long ahbenr;
	volatile unsigned long apb2enr;
	volatile unsigned long apb1enr;
	volatile unsigned long bdcr;
	volatile unsigned long csr;
	volatile unsigned long ahbstr;
	volatile unsigned long cfgr2;
};

/*
 * Memory mapped reset and clock control registers struct
 */
#define RCC	(*(struct reg_reset_clock_control *) 0x40021000)

#endif
