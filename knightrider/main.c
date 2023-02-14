/*
 * knightrider.c
 *
 * Created: 8. 2. 2023 21:26:09
 * Author : Vojtech Piroch
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "macros.h"

void delay_ms(uint16_t time);
uint16_t adc_read();

int main(void)
{
    uint16_t delay_val = 0;
	
	DDRD = 0xFF;
	
	ADMUX = (1<<REFS0) | (1<<MUX2) | (1<<MUX0);
	ADCSRA |= (1<<ADEN);
	
    while (1) 
    {
		for(uint8_t i = 0; i < 7; ++i)
		{
			delay_val = (0.47 * adc_read() + 20);
						
			HighBit(PORTD, i);
			delay_ms(delay_val);
			LowBit(PORTD, i);
		}
		for(uint8_t i = 7; i > 0; --i)
		{
			delay_val = (0.47 * adc_read() + 20);
							
			HighBit(PORTD, i);
			delay_ms(delay_val);
			LowBit(PORTD, i);
		}

    }
}

void delay_ms(uint16_t time_ms)
{
	while(time_ms>0)
	{
		_delay_ms(1);
		--time_ms;
	}
}

uint16_t adc_read()
{
	ADCSRA |= (1<<ADSC);
	
	while(ADCSRA & (1<<ADSC));
	
	return ADC;	
}
