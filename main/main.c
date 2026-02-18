#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "myGPIO.h"


void app_main(void)
{
    setup();
    while(1)
    {
        loop();
        vTaskDelay(10);
    }
}