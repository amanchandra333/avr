/*
 * adc_conversion_1.c
 *
 * Created: 10/12/2015 01:01:21
 *  Author: USER
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>

int main(void)
{
	ADMUX=(1<<REFS0);
	ADCSRA=(1<<ADEN)|(1<<ADSC)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
    while(ADCSRA&(1<<ADSC))
    {
     int a=ADC;    
    }
}