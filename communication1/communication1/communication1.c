/*
 * communication1.c
 *
 * Created: 13/12/2015 00:47:10
 *  Author: USER
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#define BAUD 9600
#define UBBR 103
int a=1;
int temp=1;
char b='y';

int main(void)
{
	DDRB=255;
	UCSRA|=0;
	UCSRB|=(1<<TXEN)|(1<<RXEN);
	UCSRC|=(1<<UCSZ0)|(1<<UCSZ1)|(1<<URSEL)|(1<<UPM1);
    while(1)
    {
		while(UCSRA&(1<<RXC)==0);
		temp=UDR;
		if(UDR==a)
		{
			PORTB^=(1<<PB0);
			while(UCSRA&(1<<UDRE)==0);
		UDR=b;
		}		
		
		
    }
}