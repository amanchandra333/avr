
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{
	DDRB=255;
	DDRD=11000011;
    while(1)
    {
     PORTB=0b00000111;
	 PORTD=0b10000010;   //left
	 _delay_ms(5000);
	 PORTB=0b00111100;
	 PORTD=0b01000010;   //forward
	 _delay_ms(5000);
	 PORTB=0b11100000;
	 PORTD=0b01000001;   //right
	 _delay_ms(5000);
	 PORTB=0b11000011;
	 PORTD=0b10000001;   //backward
	 _delay_ms(5000);
	   
    }
}