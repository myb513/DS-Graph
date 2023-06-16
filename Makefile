CC = gcc
CFLAGS = -Wall

all: main

main: main.o graph.o dfs.o bfs.o
    $(CC) $(CFLAGS) -o main main.o graph.o dfs.o bfs.o

main.o: main.c
    $(CC) $(CFLAGS) -c main.c

graph.o: graph.c
    $(CC) $(CFLAGS) -c graph.c

dfs.o: dfs.c
    $(CC) $(CFLAGS) -c dfs.c

bfs.o: bfs.c
    $(CC) $(CFLAGS) -c bfs.c

clean:
    rm -f *.o main
