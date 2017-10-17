CFLAGS=-g -Wall
OBJS=many.o user.o
CC=gcc

.PHONY: all clean

all: many user

${TARGET}: ${OBJS}
	${CC} -o ${TARGET} ${OBJS} ${LIBS}

clean:
	rm -f many user ${OBJS}
