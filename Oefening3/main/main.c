#include <stdio.h>
#include "esp_adc/adc_oneshot.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "MyADC.h"

#define ADC_CHANNEL ADC_CHANNEL_0 // GPIO34 if ADC1, GPIO14 if ADC2



void app_main(void)
{
    myADC_setup(ADC_CHANNEL_0);
    while (1) {
        int adc_value = myADC_getValue(ADC_CHANNEL_0);
        printf("ADC Value: %d\n", adc_value);
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1 second
    }
}
