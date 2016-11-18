#include <avr/io.h>
#define F_CPU 16000000UL
int main()
{
	long int counter=0;
	TCCR1A=0; 
	TCCR1B=(1<<CS11)|(1<<CS10);
	TCNT1=0; //initial condition
	DDRB=65535;
	while(1){
		while(counter<4)
		{
			while(TCNT1<65400);
			
				counter++;
				TCNT1=0;
		}
		PORTB ^= 255; 
		counter = 0; 
		//_delay_ms(1000);
	}				
	return 0;
}  ]]]]]]]]





