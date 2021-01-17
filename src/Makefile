CPU 		= msp430g2553
CFLAGS		= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include

CC		= msp430-elf-gcc
AS		= msp430-elf-gcc -mmcu=${CPU} -c

all: project3.elf

project3.elf: ${COMMON_OBJECTS} led.o buzz.o stateMachine.o song_advance.o main.o wdt_handler.o shapeStates.o draw.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd -lp2sw

load: project3.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf
