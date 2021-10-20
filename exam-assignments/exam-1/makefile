# Test makefile

CC = gcc
CFLAGS = -Wall -pedantic -ansi
TARGET = exam-1
.PHONY = clean

$(TARGET): $(TARGET).c
	gcc $(CFLAGS) $(TARGET).c -o $(TARGET).out
	./$(TARGET).out

clean:
	@echo "Cleaning up..."
	rm *.out