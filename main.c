#include "config.h"
#include "led.h"
#include "led.c"
#include "macros.h"
#include "hardware.h"
#include <avr/interrupt.h>
#include "uart.h"
#include "uart.c"
#include "debounce.h"
#include "debounce.c"

char keypad_matrix[4][4] = {
  {'1','2','3','a'},
  {'4','5','6','b'},
  {'7','8','9','c'},
  {'*','0','#','d'}
};


// debounce


//#define SW_on() (PINC & 1)==1
int main()
{
  led_init();
  led_on();

  char j;
  char i;
  for(i = 0;i<4;i++)
    debounce_init(&debounce_dir,&debounce_PORT,debounce_digit+i);

  for(i = 0;i<4;i++)
    setbit(ouput_dir,ouput_digit+i);

  zUART0.zusart_x2_mode = x2_no;
  zUART0.zusart_baud = 9600;
  zUART0.zusart_mode = usart_Asynchronous;
  zUART0.zusart_multi_processor_communication_mode = multi_processor_no;
  zUART0.zusart_int_mode = int_enable_rx_tx;
  zUART0.zusart_transmit_receive_mode = transmit_receive_mode_both;
  zUART0.zusart_CH_size = CH_size_8;
  zUART0.zusart_parity_mode = parity_Disabled;
  zUART0.zusart_stop_bit_mode = stop_1_bit;
  const uint8_t start[] = "ZAM Program Start\n\r";
  uint8_t data = 'A';

  uart_init();
  sei();

  uart_send_string(start);
  while (1)
  {

    if (uart_read_count() > 0)
    {
      data = uart_read();
      uart_send_byte(data);
    }
    if ((data >= '1') && (data <= '9'))
    {
      led_ontooff((data - 48), (58 - data));
    }
    else if (data == 'b')
    {
      led_on();
    }
    else if (data == 'd')
    {
      led_off();
    }
    else if (data == 'a')
    {
      led_toggle();
    }
    for(i = 0;i<4;i++)
    {
      ouput_PORT |= 0xF0;
      clearbit(ouput_PORT,ouput_digit+i);
      for(j=0;j<4;j++)
      {
        if (debounce_pushed(debounce_PIN,debounce_digit+j))
        {
          led_toggle();
          uart_send_byte(keypad_matrix[j][i]);
        }
        //_delay_ms(1);
      }
    }
//    _delay_ms(100);
  }
  return 0;
}
//void led_ontooff(char on,char off);
