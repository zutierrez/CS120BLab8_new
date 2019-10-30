/*	Author: zguti001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1<< ADSC) | (1<< ADATE);
	}

int main(void) {
    DDRB = 0xFF; PORTB = 0x00; //output LEDs
    DDRD = 0xFF; PORTD = 0x00; //output LEDs
    DDRA = 0x00; PORTA = 0xFF; //input POTentiometer
    unsigned short MAX = 0xFF; //254
    //unsigned char MIN = 0xC0; //192
    unsigned char outputA = 0x00;
    unsigned char outputB = 0x00;
    unsigned short x = ADC;	
    
    ADC_init();

    while (1) {
	x = ADC;
	if( x >= MAX / 2 ){
		outputA = (char)x;
		outputB = (char)(x >> 8);
		PORTB = outputA;
		PORTC = outputB;

	}	
	else {
		PORTB = 0x00;
		PORTD = 0x00;
	}
	    }

    return 1;
}
