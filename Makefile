CC = gcc -g
DEBUG_FLAGS = -ggdb -Wall -DDEBUG_OUTPUT
OPT_FLAGS = -Wall -O4 -DNDEBUG
EVENT_FLAGS = $(OPT_FLAGS) -DEVENT_OUTPUT
CFLAGS = -std=gnu99 $(EVENT_FLAGS)

all: mst

mst: readGraph.o   
	$(CC) $(CFLAGS) -o mst primsAlgorithm.c readGraph.o -lm

readGraph.o:
	$(CC) $(CFLAGS) -c readGraph.c

clean:
	rm -f mst *.o

# Path: MSTs/mst.c
