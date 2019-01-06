/* Kernel includes */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "queue.h"
#include "queue-task.h"

int main(void){

  clock_setup();
  gpio_setup();

  xQueueHandle pbq = xQueueCreate(5, sizeof(int));
  if (pbq == NULL) {
    while(1);
  }

  xTaskCreate(toggle_led,
              "Leds1",
              configMINIMAL_STACK_SIZE,
              NULL,
              tskIDLE_PRIORITY + 2UL,
              NULL);

  xTaskCreate(queueSend,
              "queueSend",
              configMINIMAL_STACK_SIZE,
              (void *) pbq,
              tskIDLE_PRIORITY + 2UL,
              NULL);

  xTaskCreate(queueRecieve, "queueRecieve",
              configMINIMAL_STACK_SIZE,
              (void *) pbq,
              tskIDLE_PRIORITY + 2UL,
              NULL);

  vTaskStartScheduler();
  /* HALT */
  while(1);

  return 0;
}
