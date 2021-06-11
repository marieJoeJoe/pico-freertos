#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/gpio.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

#define LED_PIN 25

#define GPIO_ON     1
#define GPIO_OFF    0

void GreenLEDTask(void *param)
{
  for(;;){
    gpio_put(LED_PIN, GPIO_ON);
    vTaskDelay(500);
    gpio_put(LED_PIN, GPIO_OFF);
    vTaskDelay(500);

  }
}
int main() 
{
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);


    TaskHandle_t gLEDtask = NULL;

    uint32_t status = xTaskCreate(
                    GreenLEDTask,
                    "Green LED",
                    512,
                    NULL,
                    tskIDLE_PRIORITY,
                    &gLEDtask);

    vTaskStartScheduler();
}
