CC = gcc
CFLAGS = -Wall -c -g 
OBJS = main.o graph.o dfs.o bfs.o
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

calc.o: graph.c
	$(CC) $(CFLAGS) -c graph.c

stack.o: dfs.c
	$(CC) $(CFLAGS) -c dfs.c

queue.o: bfs.c
	$(CC) $(CFLAGS) -c bfs.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)