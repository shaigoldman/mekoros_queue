CC = gcc
INCLUDES = 
CFLAGS = -g -Wall $(INCLUDES)
LDFLAGS = -g
LDLIBS = 

all: __enqueue __dequeue

__enqueue: __enqueue.o

__dequeue: __dequeue.o