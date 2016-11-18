/*
 * accelerometer.c
 *
 * Created: 10-12-2015 22:41:41
 *  Author: d e l l
 */ 
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <math.h>
#define p 3.14
#define X_ref 345
#define Y_ref 353
#define Z_ref 351
int a;
float b;
float c;
int x;
int y;
int z;



int main()
    
    {   
        DDRB=255;
        ADMUX|=(1<<REFS0);
        ADCSRA|=(1<<ADEN)|(1<<ADPS0)|(1<<ADPS1)|(ADPS2);
    
    while(1)
    {
        
        ADCSRA|=(1<<ADSC);
        while(ADCSRA&(1<<ADSC));
        x=ADC-X_ref;
        
        ADMUX=(1<<MUX0);
        while(ADCSRA&(1<<ADSC));
         y=ADC-Y_ref;
        
         ADMUX=(1<<MUX1);
        while(ADCSRA&(1<<ADSC));
         z=ADC-Z_ref;
        
         a=atan(sqrt(x*x+y*y)/z)*(57.32);
         
         if (a<=-22)
        PORTB=(1<<PB0);
         if (a<=0 && a>-22)
        PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3);
         if (a<=22 && a>0)
        PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3)|(1<<PB4);
         if(a<=60 && a>22)
        PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3)|(1<<PB4)|(1<<PB5);
         if (a<=90 && a>60)
        PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3)|(1<<PB4)|(1<<PB5)|(1<<PB6)|(1<<PB7);
        
        /*
         if (a<=0 && a>=-p/2 )
         PORTB=(1<<PB0);
         if(a<=p/2 && a>=0)
         PORTB=(1<<PB0)|(1<<PB1);
         //if(a<=-p/4)
         //PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2);
         
    
    /*if( c<=128)
    
    PORTB=(1<<PB0);
    else if(c<=256)
    PORTB=(1<<PB0)|(1<<PB1);
    else if(c<=384)
    PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2);
    else if (c<=512)
    PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3);
    else if (c<=640)
    PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3)|(1<<PB4);
    else if(c<=768)
    PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3)|(1<<PB4)|(1<<PB5);
    else if (c<=896)
    PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3)|(1<<PB4)|(1<<PB5)|(1<<PB6);
    else if (c<=1024)
    PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3)|(1<<PB4)|(1<<PB5)|(1<<PB6)|(1<<PB7);*/
    
    
    

        _delay_ms(500);
    PORTB = 0;
    }
    
    
}