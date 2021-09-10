#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/gpio.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

#include "uart_rcv_task.h"
#include "pico/bootrom.h"

#define LED_PIN 25

#define GPIO_ON     1
#define GPIO_OFF    0

void GreenLEDTask(void *param);

int main() 
{
    //printf("rpi pico\n");

    TaskHandle_t gLEDtask = NULL;
    TaskHandle_t AtTask = NULL;
    TaskHandle_t UartRcvTask = NULL;
    TaskHandle_t MqttTask = NULL;

    uint32_t status = xTaskCreate(
                    uart_rcv_polling,
                    "uart_rcv_polling",
                    1024*2,
                    NULL,
                    tskIDLE_PRIORITY+3,
                    &UartRcvTask);
/*
    status = xTaskCreate(
                    at_dispatching,
                    "at_task",
                    1024,
                    NULL,
                    tskIDLE_PRIORITY+2,
                    &AtTask);

    status = xTaskCreate(
                    mqtt_polling,
                    "mqtt_task",
                    1024,
                    NULL,
                    tskIDLE_PRIORITY+1,
                    &MqttTask);
*/
    vTaskStartScheduler();

}

void GreenLEDTask(void *param)
{
  for(;;){
    gpio_put(LED_PIN, GPIO_ON);
    vTaskDelay(500);
    gpio_put(LED_PIN, GPIO_OFF);
    vTaskDelay(500);

  }
}

