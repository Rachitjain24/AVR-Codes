#undef F_CPU
#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main()
{
   
   DDRD = 0b11111111;
   while(1){
            PORTD = DDRD;
			_delay_ms(8);
			PORTD = 0b00000000;
			_delay_ms(8);
			}
    return 0;
}
	