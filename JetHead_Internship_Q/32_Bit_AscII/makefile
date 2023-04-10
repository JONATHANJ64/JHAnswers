CC = gcc
CFLAGS = -std=c99 -Wall
TARGET = ascii_converter

$(TARGET): ascii_converter.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f $(TARGET)
