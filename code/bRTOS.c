#include <libopencm3/stm32/gpio.h>

#include "FreeRTOS.h"
#include "task.h"

#include "blink.h"

int main(void){

  clock_setup();
  gpio_setup();

  xTaskCreate(task1,
              "Leds1",
              configMINIMAL_STACK_SIZE,
              NULL,
              tskIDLE_PRIORITY + 2UL,
              NULL);

  xTaskCreate(task2,
              "Leds2",
              configMINIMAL_STACK_SIZE,
              NULL,
              tskIDLE_PRIORITY + 2UL,
              NULL);

  vTaskStartScheduler();

  return 0;
}
