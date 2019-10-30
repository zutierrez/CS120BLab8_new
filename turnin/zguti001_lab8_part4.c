/*	Author: zguti001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #7 Exercise #4
 *	Exercise Description: CHALLENGE - ADC level 0-7 meter
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
    unsigned short thresh6 = 0xF5; //245
    unsigned short thresh5 = 0xEB; //235
    unsigned short thresh4 = 0xE6; //230
    unsigned short thresh3 = 0xE1; //225
    unsigned short thresh2 = 0xDC; //220
    unsigned short thresh1 = 0xD2; //210
    unsigned char MIN = 0xCD; //205
    unsigned short x = ADC;	
    
    ADC_init();

    while (1) {
	x = ADC;
	if( x >= MAX ){
		PORTB = 0xFF;
		PORTD = 0x01;

	}
	if( x >= thresh6){
		PORTB = 0x7F;
		PORTD = 0x00; 	
	    }
	if( x >= thresh5){
		PORTB = 0x3F;
		PORTD = 0x00; 	
	    }
	if( x >= thresh4){
		PORTB = 0x1F;
		PORTD = 0x00; 	
	    }
	if( x >= thresh3){
		PORTB = 0x0F;
		PORTD = 0x00; 	
	    }
	if( x >= thresh2){
		PORTB = 0x07;
		PORTD = 0x00; 	
	    }
	if( x >= thresh1){
		PORTB = 0x03;
		PORTD = 0x00; 	
	    }
	if( x >= MIN){
		PORTB = 0x01;
		PORTD = 0x00; 	
	}
	    }
    return 1;
}

