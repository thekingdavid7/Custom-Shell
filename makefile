CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = myshell
OBJS = myshell.o parse.o process.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

myshell.o: myshell.c parse.h process.h
	$(CC) $(CFLAGS) -c myshell.c

parse.o: parse.c parse.h
	$(CC) $(CFLAGS) -c parse.c

process.o: process.c process.h
	$(CC) $(CFLAGS) -c process.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o

.PHONY: all run clean
