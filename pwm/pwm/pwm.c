/*
 * pwm.c
 *
 * Created: 24-02-2016 21:41:22
 *  Author: USER
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	DDRD=255;
	int a=0;
	TCCR0A|=(1<<COM0A1)|(1<<WGM00)|(1<<WGM01);
	TCCR0B|=(1<<CS00)|(1<<WGM02);
	while(1)
	{
		for(a=0;a<255;a+=51)
		{
			OCR0A=a;
			_delay_ms(50);
		}
		for(a=255;a>0;a-=51)
		{
			OCR0A=a;
			_delay_ms(50);
		}
		
	}
}