TARGET=zombie
CFLAGS=-g -Wall
OBJS=zombie.o 
LIBS=
CC=gcc

.PHONY: all clean

all: ${TARGET}

${TARGET}: ${OBJS}
	${CC} -o ${TARGET} ${OBJS} ${LIBS}

clean: 
	rm -f ${TARGET} ${OBJS} 
