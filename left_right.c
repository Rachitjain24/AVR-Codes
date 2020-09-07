#undef F_CPU
#define F_CPU 1000000UL

#include<avr/io.h>
#include<util/delay.h>

int shift_left();
int shift_right();

int shift_left()
{
    while(1){
        _delay_ms(50);
        PORTD = (PORTD << 1);
        if(PORTD == 128){
           _delay_ms(50);
           return 0; 
        }
    }
}    

int shift_right()
{
    while(1){
        _delay_ms(50);
        PORTD = (PORTD >> 1);
        if(PORTD == 1){
            _delay_ms(50);
            return 0;
        }
    }
}
    

int main()
{
    DDRD = 0b11111111;                   //all port D pins have been set as output
    PORTD = 0x01;
    while(1){                        //create an infinite loop
        shift_left();
        shift_right();
    }
    return 0;
}