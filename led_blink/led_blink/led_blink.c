/*
 * led_blink.c
 *
 * Created: 09/12/2015 15:06:00
 *  Author: USER
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL    //XTAL 16MHz
#include <util/delay.h>


int main(void)
{
	DDRB=255;
    while(1)  //or while(1>0)  infinite loop
    {
		PORTB=(1<<PB7);
		_delay_ms(100); 
		PORTB=(1<<PB6);
		_delay_ms(100);
		PORTB=(1<<PB5);
		_delay_ms(100);
		PORTB=(1<<PB4);
		_delay_ms(100);
		PORTB=(1<<PB3);
		_delay_ms(100);
		PORTB=(1<<PB2);
		_delay_ms(100);
		PORTB=(1<<PB1);
		_delay_ms(100);
		PORTB=(1<<PB0);
		_delay_ms(100);   
    }
}