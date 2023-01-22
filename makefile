CC = gcc
FLAGS = -Wall -g
OBJECTS_MAIN = main.o
AR = ar

all: graph 

graph: $(OBJECTS_MAIN) graph_methods.o
	$(CC) $(FLAGS) -o graph $(OBJECTS_MAIN) graph_methods.o

main.o: main.c graph_methods.h
	$(CC) $(FLAGS) -c main.c

graph_methods.o: graph_methods.c graph_methods.h
	$(CC) $(FLAGS) -c graph_methods.c

.PHONY: clean all

clean:
	rm -f *.o graph
	