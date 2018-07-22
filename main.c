#include "stm32f1.h"

#define DELAY 200000

void SystemInit(void) {
	// Enable clock for IOPC
	RCC.apb2enr |= 1 << 4;

	// Configure GPIOC_13 as output:
	//   - MODE = 11 (output, 50Mhz)
	//   - CNF  = 01 (open-drain)
	unsigned long gpioc_config = GPIOC.crh;
	gpioc_config &= ~(0xff << 20);
	gpioc_config |= 0x07 << 20;
	GPIOC.crh = gpioc_config;
}

void main(void) {
	volatile unsigned long i;
	while(1) {
		GPIOC.odr ^= 1 << 13;
		for(i=0; i<DELAY; i++);
	}
}
