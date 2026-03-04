#include <stdio.h>
#include "driver/gpio.h"
#include "myGPIO.h"

void setup(void)
{
// BUTTON
gpio_reset_pin(BUTTON_PIN);
gpio_set_direction(BUTTON_PIN,GPIO_MODE_INPUT);
gpio_pullup_en(BUTTON_PIN);

// LED
gpio_reset_pin(LED_PIN);
gpio_set_direction(LED_PIN, GPIO_MODE_INPUT_OUTPUT);
}


// -- BUTTON LOGIC --
void loop(void)
{   
    static int counter = 0;
    static int last_button_state = 1;

    int button_state = gpio_get_level(BUTTON_PIN);

    if (last_button_state == 1 && button_state == 0) {
        counter++;
        printf("Button Pressed, counter = %d\n", counter);
    
        if (counter % 5 == 0) {
            gpio_set_level(LED_PIN, 1);
            printf("(LED ON, %d)\n", counter);
    } else {
            gpio_set_level(LED_PIN, 0);
            printf("(LED OFF, %d)\n", counter);
        }
        printf("Button Released, counter = %d\n", counter);
    }
    last_button_state = button_state;
}


