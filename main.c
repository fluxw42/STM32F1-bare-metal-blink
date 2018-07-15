#include "stm32f1.h"

#define DELAY 200000

void SystemInit(void) {
	// Enable clock for IOPC
	RCC_APB2ENR |= 1 << 4;

	// Configure GPIOC_13 as output:
	//   - MODE = 11 (output, 50Mhz)
	//   - CNF  = 01 (open-drain)
	unsigned long gpioc_config = GPIOC_CRH;
	gpioc_config &= ~(0xff << 20);
	gpioc_config |= 0x07 << 20;
	GPIOC_CRH = gpioc_config;
}

void main(void) {
	volatile unsigned long i;
	while(1) {
		GPIOC_ODR ^= 1 << 13;
		for(i=0; i<DELAY; i++);
	}
}
