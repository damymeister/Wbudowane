/*
 * GccApplication2.c
 *
 * Created: 14.11.2022 18:07:23
 * Author : Student_PL
 */ 


#define F_CPU 1000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define PORT PORTC
#define DDR DDRC
#define PIN PINC

volatile int count = 0;
volatile int koef = 10;

void zad1(){
	TCCR0 |= _BV(CS00) | _BV(CS02);
	for(int i = 0; i < 10; i++){
		TCNT0 = 157;
		while((TIFR & 0x01)==0);
		TIFR = 0x1;
	}
	TCCR0 = 0;
	PORTA ^= _BV(0);
}

ISR(TIMER0_OVF_vect){
	count++;
	if(count >=koef){
		count =0;
		PORTA ^= _BV(0);
		
	}
	TCNT0 = 157;
}


int sw(){
	int i;
	unsigned char odcyt;
	DDR = 0xf0;
	PORT = 0x0f;
	for(i = 4; i < 8; i++){
		PORT = ~_BV(i);
		_delay_ms(1);
		odcyt =  ~PIN & 0x0f;
		if(odcyt){
			return (i-3) + (odcyt-1)*4;
		}
	} 
	return 0;
}


ISR(INT1_vect){

	koef = sw();
}

int main(void)
{
    /* Replace with your application code */
	//zad2
	/*

	TCNT0 = 157;
	TCCR0 = _BV(CS00) | _BV(CS02);
	TIMSK=(1<<TOIE0);
	sei();
	*/
	//zad2
	//zad3
	
	TCNT0 = 157;
	TCCR0 = _BV(CS00) | _BV(CS02);
	TIMSK=(1<<TOIE0);
	GICR = _BV(INT1);
	MCUCR = _BV(ISC11) | _BV(ISC10);	
	sei();
	
	//zad3	

	DDRA = 0xff;
	
	
    while (1) {
		//zad1();
	}
}

