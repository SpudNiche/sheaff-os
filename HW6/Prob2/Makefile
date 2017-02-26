TARGET=SDgeo
CFLAGS=-g -Wall
OBJS=SDgeo.o 
LIBS=
CC=gcc

.PHONY: all clean

all: ${TARGET}

${TARGET}: ${OBJS}
	${CC} -o ${TARGET} ${OBJS} ${LIBS}

clean: 
	rm -f ${TARGET} ${OBJS} 
