# Test makefile

CC = gcc
CFLAGS = -Wall -pedantic -ansi
TARGET = sqrt

$(TARGET): $(TARGET).c
	gcc $(TARGET).c -o $(TARGET).out
	./$(TARGET).out

clean:
	@echo "Cleaning up..."
	rm *.out