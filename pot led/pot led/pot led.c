#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <math.h>
int a,b,c;
int main()
{
	ADCSRA|=(1<<ADEN)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
	DDRB=255;
	ADMUX|=(1<<REFS0);
	
	while(1)
	{
		ADCSRA|=(1<<ADSC);
	while(ADCSRA&(1<<ADSC));

	a=ADC;
	
	if (a<=128)
		PORTB=255;
		else if (a<=256)
		PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3)|(1<<PB4)|(1<<PB5)|(1<<PB6);
		else if (a<=384)
		PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3)|(1<<PB4)|(1<<PB5);
		else if (a<=512)
		PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3)|(1<<PB4);
		else if (a<=640)
		PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3);
		else if (a<=768)
		PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2);
		else if (a<=896)
		PORTB=(1<<PB0)|(1<<PB1);
		else if (a<=1024)
		PORTB=(1<<PB0);
		
	}		
		
	/*PORTB=0;
	
	int i,value;
	value = 0;
	for (i=0;i<=a;i+128)
	{
	value|=(1<<i/128);	
	
	}
	PORTB|=value;
		_delay_ms(2000);
	
	}
	*/
	return 0;
}