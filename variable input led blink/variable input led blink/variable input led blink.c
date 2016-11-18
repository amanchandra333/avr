/*
 * variable_input_led_blink.c
 *
 * Created: 09/12/2015 17:49:08
 *  Author: USER
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{
	DDRB=255;
	DDRD=0:
	
    while(1)
    {
    if(PIND&(1<<PD0))
	PORTB=255;
	else if()    
    }
}