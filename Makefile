CC = gcc
CFLAGS = -Wall -I./include
TARGET = bin/flight_system
SRC = src/main.c \
      src/flight_tool.c \
      src/flight_init.c \
      src/flight_display.c \
      src/flight_search.c \
      src/flight_add.c \
      src/flight_delete.c \
      src/flight_modify.c 

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean