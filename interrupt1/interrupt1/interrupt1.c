/*
 * interrupt1.c
 *
 * Created: 12/12/2015 16:33:30
 *  Author: USER
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
volatile long counter=0;

int main(void)
{	sei();//to enable global interrupt
	DDRB=255;
	PORTB=0;
	TCNT0=0;
	TCCR0|=(1<<CS00);
	TIMSK=(1<<TOIE0);         
   while(1){
	  		 if (counter>=62000)
	  		 {
		  		 PORTB^=255;
		  		 counter=0;
	  		 }   
   }	
	}	
ISR(TIMER0_OVF_vect)
	 {
		//f(counter<=975)
			counter++;
	 }
	 