

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	DDRD=255;
	int a=0;
	//PORTB=(1<<PB3);
	TCCR1A=(1<<COM1A1)|(1<<WGM10);
	TCCR1B|=(1<<CS10)|(1<<WGM12);
	   while(1)
    {
		for(a=0;a<255;a++)
		{
			OCR0=a;
			_delay_ms(50);
		}
		for(a=255;a>0;a--)
		{
			OCR0=a;
			_delay_ms(50);
		}					
      
    }
}