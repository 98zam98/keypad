
#ifndef HARDWARE_H_
#define HARDWARE_H_

/*led ports*/
#define led_digit	5
#define led_dir 	DDRB
#define led_PORT  	PORTB
//--------------------------------------	


/* debounce ports*/
// if all in one port - it is
#define debounce_digit	0
#define debounce_dir 	DDRC
#define debounce_PORT  	PORTC
#define debounce_PIN  	PINC
//--------------------------------------	


#define debounce_digit_1	0
#define debounce_dir_1 	    DDRC
#define debounce_PORT_1  	PORTC
#define debounce_PIN_1  	PINC
//--------------------------------------	


#define debounce_digit_2	1
#define debounce_dir_2 	    DDRC
#define debounce_PORT_2  	PORTC
#define debounce_PIN_2  	PINC
//--------------------------------------	


#define debounce_digit_3	2
#define debounce_dir_3 	    DDRC
#define debounce_PORT_3  	PORTC
#define debounce_PIN_3  	PINC
//--------------------------------------	


#define debounce_digit_4	3
#define debounce_dir_4 	    DDRC
#define debounce_PORT_4  	PORTC
#define debounce_PIN_4  	PINC
//--------------------------------------	



/* ouput ports*/
// if all in one port - it is
#define ouput_digit	4
#define ouput_dir 	DDRD
#define ouput_PORT  PORTD
//--------------------------------------	

/*
#define debounce_digit_1	0
#define debounce_dir_1 	    DDRC
#define debounce_PORT_1  	PORTC
#define debounce_PIN_1  	PINC
//--------------------------------------	


#define debounce_digit_2	1
#define debounce_dir_2 	    DDRC
#define debounce_PORT_2  	PORTC
#define debounce_PIN_2  	PINC
//--------------------------------------	


#define debounce_digit_3	2
#define debounce_dir_3 	    DDRC
#define debounce_PORT_3  	PORTC
#define debounce_PIN_3  	PINC
//--------------------------------------	


#define debounce_digit_4	3
#define debounce_dir_4 	    DDRC
#define debounce_PORT_4  	PORTC
#define debounce_PIN_4  	PINC
//--------------------------------------	

*/
// usart_

//usart_data_buffer_register
#define usart_data_buffer_register 	UDR0

// usart_control_status_register_A
#define usart_control_status_register_A 	UCSR0A
#define usart_multi_processor_communication MPCM0 
#define usart_x2                            U2X0
#define usart_Parity_err                    UPE0 
#define usart_data_over_run                 DOR0 
#define usart_Frame_err                     FE0 
#define usart_data_register_empty           UDRE0 
#define usart_transmit_complete             TXC0
#define usart_receive_complete              RXC0

// usart_control_status_register_B
#define usart_control_status_register_B     UCSR0B
#define usart_transmit_BIT_8                TXB80
#define usart_receive_BIT_8                 RXB80
#define usart_CH_size_BIT_2                 UCSZ02
#define usart_transmit_en                   TXEN0
#define usart_receive_en                    RXEN0
#define usart_data_register_empty_int_en    UDRIE0 
#define usart_transmit_complete_int_en      TXCIE0
#define usart_receive_complete_int_en       RXCIE0



// usart_control_status_register_C
#define usart_control_status_register_C     UCSR0C
#define usart_clock_polarity                UCPOL0
#define usart_CH_size_BIT_0                  UCSZ00
//#define usart_ UCPHA0 1
#define usart_CH_size_BIT_1                  UCSZ01
//#define usart_ UDORD0 2
#define usart_stop_bit                      USBS0
#define usart_parity_mode_BIT_0             UPM00
#define usart_parity_mode_BIT_1             UPM01
#define usart_mode_select_BIT_0             UMSEL00
#define usart_mode_select_BIT_1             UMSEL01


// usart_baud_rate_register

#define usart_baud_rate_register            UBRR0
#define usart_baud_rate_register_low        UBRR0L
#define usart_baud_rate_register_high       UBRR0H



// int


#define usart_receive_Interrupt_vect                    USART_RX_vect
#define usart_data_register_empty_Interrupt_vect        USART_UDRE_vect
#define usart_transmit_Interrupt_vect                   USART_TX_vect


#endif