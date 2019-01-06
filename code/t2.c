void queueSend( void *args ) {

  xQueueHandle pbq = (xQueueHandle) args;
  int sig = 1;

  while (1) {
    // Detect Button Press
    if(gpio_get(GPIOA, GPIO0)>0) {
      while(gpio_get(GPIOA, GPIO0)>0)
        vTaskDelay(pdMS_TO_TICKS(100)); // Button Debounce Delay
      while(gpio_get(GPIOA, GPIO0)==0)
        vTaskDelay(pdMS_TO_TICKS(100));
      xQueueSend(pbq, &sig, portMAX_DELAY); // Send Message
    }
  }
}

void queueRecieve( void *args ) {

  xQueueHandle pbq = (xQueueHandle) args;
  int sig;

  while (1) {
    // portMAX_DELAY blocks task indefinitely if queue is empty
    if(xQueueReceive(pbq, &sig, portMAX_DELAY) == pdPASS) {
      gpio_toggle(LEDS, LED2);
    }
  }
}
