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
  int temp;
  int rate;
  
	rcc_periph_clock_enable(RCC_GPIOB);
	
	/* PB1 (LED) output */
	gpio_set_mode(GPIOB,GPIO_MODE_OUTPUT_2_MHZ,GPIO_CNF_OUTPUT_PUSHPULL,GPIO1);
	
	/* PB8 (button) input */
	gpio_set_mode(GPIOB,GPIO_MODE_INPUT,GPIO_CNF_INPUT_FLOAT,GPIO8);
	
	/* start with LED off */
	gpio_clear(GPIOB,GPIO1);
	
	/* loop forever */
	while (1) {
	  if (gpio_get(GPIOB,GPIO8)) {
	    rate=30000;
	  }
	  else {
	    rate=100000;
	  }
	  for (temp=0;temp<rate;temp++);
	  gpio_toggle(GPIOB,GPIO1);
	}
}
