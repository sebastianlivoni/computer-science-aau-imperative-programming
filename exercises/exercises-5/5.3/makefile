# Test makefile

CC = gcc
CFLAGS = -Wall -pedantic -ansi
TARGET = goldbach
.PHONY = clean

$(TARGET): $(TARGET).c
	gcc $(TARGET).c primes.c -o $(TARGET).out
	./$(TARGET).out

clean:
	@echo "Cleaning up..."
	rm *.out