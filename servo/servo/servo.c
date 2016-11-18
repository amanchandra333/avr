/*
 * servo.c
 *
 * Created: 13/12/2015 03:06:04
 *  Author: USER
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main()
{
	ICR1=1250;
	int a;
	DDRD=255;
	TCCR1A=(1<<WGM11)|(1<<COM1A1);
	TCCR1B=(1<<CS12)|(1<<WGM12)|(1<<WGM13);
    while(1)
    {
       for(a=0;a<250;a++)
       {
	       OCR1A=a;
	       _delay_ms(10);
       }
       for(a=250;a>0;a--)
       {
	       OCR1A=a;
	       _delay_ms(10);
	   }		   
		   
    }
	return 0;
}