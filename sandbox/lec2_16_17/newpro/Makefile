TARGET=santos
CFLAGS=-g -Wall
OBJS=snowden.o trump.o devos.o
LIBS=-Lcampus -lm -lfogler
CC=gcc

.PHONY: all clean

all: ${TARGET}

${TARGET}: ${OBJS}
	${CC} -o ${TARGET} ${OBJS} ${LIBS}

clean: 
	rm -f ${TARGET} ${OBJS}
