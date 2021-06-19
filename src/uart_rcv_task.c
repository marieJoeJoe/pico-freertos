#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/bootrom.h"

#include "uart_rcv_task.h"

#define LED_PIN 25

#define GPIO_ON     1
#define GPIO_OFF    0

void uart_rcv_polling(void *param)
{
  stdio_init_all();

  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);



  char buffer[1024];
  printf("<<rpi pico>>\n");
  for(;;){
    scanf("%1024s", buffer);
    printf("%s\n", buffer);
    if (strcmp(buffer, "ON") == 0)
    {
      gpio_put(LED_PIN, 1);
    }
    else if (strcmp(buffer, "OFF") == 0)
    {
      gpio_put(LED_PIN, 0);
    }
    else if (strcmp(buffer, "REBOOT") == 0)
    {
      reset_usb_boot(0,0);
    } 
  }
}
