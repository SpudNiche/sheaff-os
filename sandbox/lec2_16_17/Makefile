TARGET=blink
CFLAGS=-g -Wall
OBJS=blink.o flash.o
LIBS=-lm
CC=gcc

.PHONY: all clean

all: ${TARGET}

${TARGET}: ${OBJS}
	${CC} -o ${TARGET} ${OBJS} ${LIBS}

clean: 
	rm -f ${TARGET} ${OBJS}
