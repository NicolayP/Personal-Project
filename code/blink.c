#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>

static void clock_setup(void){
  rcc_clock_setup_hse_3v3(&rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_168MHZ]);
}

static void gpio_setup(void){

  rcc_periph_clock_enable(RCC_GPIOG);
  gpio_mode_setup(GPIOG, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13 | GPIO14);
}

int main( void ) {
  clock_setup();
  gpio_setup();
  for(;;) {
    gpio_toggle(GPIOG, GPIO14);
    for (int i=0; i < 15000000; i++) {
      __asm__("nop");
    }

    gpio_toggle(GPIOG, GPIO14);
    for (int i=0; i < 30000000; i++) {
      __asm__("nop");
    }
  }
  
  return 0;

}
