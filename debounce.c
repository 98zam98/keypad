#include "config.h"
#include "debounce.h"
#include "macros.h"
#include "hardware.h"

#define debounceDelay   5

char debounce_init(char* d,char* p,char di)
{
  clearbit(*d, di);
  setbit(*p, di);
}



char debounce_pushed(char input_PINC,char d)
{
    

char buttonState = 0;         // the current reading from the input pin
char lastButtonState = 0; // the previous reading from the input pin


    char reading = input_PINC & (1<<d);
    if (reading != lastButtonState)
    {
        // reset the debouncing timer

        _delay_ms(debounceDelay);
        //return 0;

        if (reading != buttonState)
        {
            buttonState = reading;
        }
        lastButtonState = reading;
    }
    // ========================================================================================================

    if ((input_PINC & (1<<d)) == (1<<d)) //bit_is_clear(PINC, 1))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
