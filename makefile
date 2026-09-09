CC = g++
CFLAGS = -Wall -Wextra -g
TARGET = myshell
OBJS = myshell.o parse.o process.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

myshell.o: myshell.cpp parse.hpp process.hpp
	$(CC) $(CFLAGS) -c myshell.cpp

parse.o: parse.cpp parse.hpp
	$(CC) $(CFLAGS) -c parse.cpp

process.o: process.cpp process.hpp
	$(CC) $(CFLAGS) -c process.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o

.PHONY: all run clean
