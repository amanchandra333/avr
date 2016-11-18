/*
 * communication2.c
 *
 * Created: 13/12/2015 01:35:39
 *  Author: USER
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#define BAUD 9600
#define UBBR 103
int a=1;
char b='y';
char temp='y';


int main(void)
{
        DDRB=255;
        UCSRA|=0;
        UCSRB|=(1<<TXEN)|(1<<RXEN);
        UCSRC|=(1<<UCSZ0)|(1<<UCSZ1)|(1<<URSEL)|(1<<UPM1);
		while(UCSRA&(1<<UDRE)==0);
		UDR=a;
		while(1)
	       {
			    if(UDR==temp)
			{
				PORTB^=(1<<PB7);
			while(UCSRA&(1<<UDRE)==0);
	        UDR=a;
			temp='n';
			}
		    while(UCSRA&(1<<RXC)==0);
	        temp=UDR;
	       
    }
}