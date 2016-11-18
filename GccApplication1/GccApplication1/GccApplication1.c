

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{
	DDRB=255;

	while(1)
	{
		
		PORTB=(1<<PB0);
		_delay_ms(100);
		PORTB=(1<<PB1);
		_delay_ms(100);
		PORTB=(1<<PB2);
		_delay_ms(100);
		PORTB=(1<<PB3);
		_delay_ms(100);
	}
}