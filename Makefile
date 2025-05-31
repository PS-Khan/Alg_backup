# Makefile for compiling file.cpp

# Compiler and flags
CC = g++
CFLAGS = -Wall -Wextra -std=c++2a -lm

# Target and source
TARGET = Practice
SOURCE = practice.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)