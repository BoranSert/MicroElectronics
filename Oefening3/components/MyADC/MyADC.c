#include <stdio.h>
#include "MyADC.h"
#include "esp_adc/adc_oneshot.h"


adc_oneshot_unit_handle_t adc1_handle;

adc_oneshot_unit_init_cfg_t adc_config = {
    .unit_id = ADC_UNIT_1,
    .ulp_mode = ADC_ULP_MODE_DISABLE,
};

adc_oneshot_chan_cfg_t default_channel_config = {
    .bitwidth = ADC_BITWIDTH_DEFAULT,          
    .atten = ADC_ATTEN_DB_12,
};

void myADC_setup(int channel)
{
    adc_oneshot_new_unit(&adc_config, &adc1_handle);
    adc_oneshot_config_channel(adc1_handle, channel, &default_channel_config);
}
int myADC_getValue(int channel)
{
    int getal;
    adc_oneshot_read(adc1_handle, channel, &getal);
    return getal;

}