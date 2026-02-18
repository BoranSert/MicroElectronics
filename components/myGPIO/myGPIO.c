#include <stdio.h>
#include "myGPIO.h"
#include "driver/gpio.h"

static int led_pin;
static int button_pin;

void myGPIO_LED_Setup(int LED_PIN, int BUTTON_PIN)
{
    led_pin = LED_PIN;
    button_pin = BUTTON_PIN;

    gpio_reset_pin(led_pin);
    gpio_reset_pin(button_pin);

    gpio_set_direction(led_pin, GPIO_MODE_OUTPUT);
    gpio_set_direction(button_pin, GPIO_MODE_INPUT);

    gpio_pullup_en(button_pin);

    gpio_set_level(led_pin, 1); 
}

void myGPIO_loop(void)
{
    static int counter = 0;
    static int last_button_state = 1;
    static int led_state = 1;

    int button_state = gpio_get_level(button_pin);

    if (last_button_state == 1 && button_state == 0)
    {
        counter++;
        printf("Button pressed: %d\n", counter);

        if (counter == 5)
        {
            led_state = !led_state;          
            gpio_set_level(led_pin, led_state);
            counter = 0;                    
            printf("LED toggled\n");
        }
    }

    last_button_state = button_state;
}
