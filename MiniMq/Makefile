CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Iinclude
TARGET = minimq
SRC = src/main.c src/message.c src/queue.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
