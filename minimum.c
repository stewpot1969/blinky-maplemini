#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>


/*
#ifndef __NO_SYSTEM_INIT
void SystemInit()
{}
#endif
*/

int main(void)
{
	rcc_periph_clock_enable(RCC_GPIOA);
	for (;;);
}
