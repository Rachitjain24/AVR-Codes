set projectName=hello
set microName=atmega8

avr-gcc -g -Os -mmcu=%microName% -c %projectName%.c 

avr-gcc -g -mmcu=%microName% -o %projectName%.elf %projectName%.o

avr-objcopy -j .text -j .data -O ihex %projectName%.elf %projectName%.hex

avrdude -c arduino  -p %microName% -P COM3 -v -v -v -b19200 -U flash:w:%projectName%.hex:i

