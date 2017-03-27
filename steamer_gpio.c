
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#define LEDPORT GPIOE
#define LED GPIO15
static void gpio_setup(void)
{
	/* Enable GPIOE clock. */
	rcc_periph_clock_enable(RCC_GPIOE);
	rcc_clock_setup_in_hse_25mhz_out_72mhz();
	/* Set GPIO12 (in GPIO port C) to 'output push-pull'. */
	gpio_set_mode(LEDPORT, GPIO_MODE_OUTPUT_2_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, LED);
}

int main(void)
{
	int i;

	gpio_setup();

	/* Blink the LED (PC12) on the board. */
	while (1) {
		gpio_toggle(LEDPORT, LED);	/* LED on/off */
		for (i = 0; i < 800000; i++)	/* Wait a bit. */
			__asm__("nop");
	}

	return 0;
}
