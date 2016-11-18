/*
 * accelerometer1.c
 *
 * Created: 10/12/2015 23:41:28
 *  Author: USER
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <math.h>
#define p 3.14
#define x_ref 345
#define y_ref 353
#define z_ref 351
float a;
int x,y,z;
int main(void)
{
	ADCSRA=(1<<ADEN)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
	DDRB=255;
	ADMUX=(1<<REFS0);
	
	while(1)
	{
		ADCSRA|=(1<<ADSC);
	while(ADCSRA&(1<<ADSC));
	x=ADC-x_ref;
	
		ADCSRA|=(1<<ADSC); 	 
		ADMUX|=(1<<MUX0);
		while(ADCSRA&(1<<ADSC));
		y=ADC-y_ref;
		
		ADCSRA|=(1<<ADSC);
		ADMUX|=(1<<MUX1);
	while(ADCSRA&(1<<ADSC));
		z=ADC-z_ref;
		
		a = (atan(sqrt(y*y+x*x) / z))*(57.32);
		if (a<0)
		{
			a=a*(-1);
		}
		
			if (a<(0))
			{PORTB=255;
			} 
			else if (a>0,a<20)
			{PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3)|(1<<PB4)|(1<<PB5)|(1<<PB6);
			}
			/*else if (a<=(-22))
			{PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3)|(1<<PB4)|(1<<PB5);
			_delay_ms(500);}
			*/
		else if (a>20,a<40)
			{PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3)|(1<<PB4);
			}
			/*else if (a<=22)
			{PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3);
			_delay_ms(500);}*/
			else if (a>40,a<60)
			{PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2);
			}
			
			/*/else if (a<=45,a>0)
			{PORTB=(1<<PB0)|(1<<PB1);
			_delay_ms(500);}*/
			else if (a>60,a<80)
			{PORTB=(1<<PB0);
			}
			else
			{PORTB=0;
			
			}
			_delay_ms(500);
			PORTB=0;
	}		
		
}