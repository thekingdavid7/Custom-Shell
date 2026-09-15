CC = g++
CFLAGS = -Wall -Wextra -g
TARGET = myshell
TEST_TARGET = unittest
OBJS = myshell.o parse.o process.o param.o
TEST_OBJS = unittest.o parse.o param.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(TEST_TARGET): $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJS)

myshell.o: myshell.cpp parse.hpp param.hpp
	$(CC) $(CFLAGS) -c myshell.cpp

parse.o: parse.cpp parse.hpp
	$(CC) $(CFLAGS) -c parse.cpp

param.o: param.cpp param.hpp
	$(CC) $(CFLAGS) -c param.cpp

unittest.o: unittest.cpp parse.hpp param.hpp
	$(CC) $(CFLAGS) -c unittest.cpp

run: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) *.o
	rm -f $(TEST_TARGET) *.o

.PHONY: all run clean
