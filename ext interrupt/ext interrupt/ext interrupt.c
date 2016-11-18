/*
 * ext_interrupt.c
 *
 * Created: 12/12/2015 18:27:52
 *  Author: USER
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
	sei();
	DDRD=0;
	DDRB=255;
	MCUCR|=(1<<ISC01)|(1<<ISC00);
	GICR|=(1<<INT0);
    while(1)
    {
        
    }
}
ISR(INT0_vect)
{
	PORTB=255;
}