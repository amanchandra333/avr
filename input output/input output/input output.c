/*
 * led_blink_variable_input.c
 *
 * Created: 09/12/2015 17:32:02
 *  Author: USER
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{
	DDRB=255;
	DDRD=0;
    while(1)
    {
     if(PIND&(1<<PD3))
	 PORTB=(1<<PB2);
	 else
	 PORTB=(1<<PB3);  
    }
}