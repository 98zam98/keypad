#include "config.h"
#include "led.h"

#define zDelay 100



void led_init()
{
    setbit(led_dir,led_digit);
}

void led_on()
{
    setbit(led_PORT,led_digit);
}

void led_off()
{
    clearbit(led_PORT,led_digit);
}

void led_toggle()
{
    togglebit(led_PORT,led_digit);
    _delay_ms(zDelay);
}

// on 1 to off 9
void led_ontooff(char on,char off)
{
    led_on();
    _delay_ms(on*zDelay);
    led_off();
    _delay_ms(off*zDelay);
}
