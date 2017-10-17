TARGET=bpsk_encode
CFLAGS=-g -Wall
OBJS=bpsk_encode.o encoding.o 
LIBS=
CC=gcc

.PHONY: all clean

all: ${TARGET}

${TARGET}: ${OBJS}
	${CC} -o ${TARGET} ${OBJS} ${LIBS}

clean: 
	rm -f ${TARGET} ${OBJS} 
