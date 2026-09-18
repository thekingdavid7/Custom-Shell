CC = g++
CFLAGS = -Wall -Wextra -g

TARGET = myshell
TEST_TARGET = unittest
SLOW_TARGET = slow

OBJS = myshell.o parse.o param.o process.o
TEST_OBJS = unittest.o parse.o param.o process.o
SLOW_OBJS = slow.o

all: $(TARGET) $(SLOW_TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(TEST_TARGET): $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJS)
	
$(SLOW_TARGET): $(SLOW_OBJS)
	$(CC) $(CFLAGS) -o $@ $(SLOW_OBJS)

myshell.o: myshell.cpp parse.hpp param.hpp process.hpp
	$(CC) $(CFLAGS) -c myshell.cpp

parse.o: parse.cpp parse.hpp
	$(CC) $(CFLAGS) -c parse.cpp

param.o: param.cpp param.hpp
	$(CC) $(CFLAGS) -c param.cpp

process.o: process.cpp process.hpp
	$(CC) $(CFLAGS) -c process.cpp

unittest.o: unittest.cpp parse.hpp param.hpp
	$(CC) $(CFLAGS) -c unittest.cpp

run: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) *.o
	rm -f $(TEST_TARGET) *.o
	rm -f $(SLOW_TARGET) *.o

.PHONY: all run test clean
