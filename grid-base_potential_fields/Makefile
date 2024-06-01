CC = gcc
CFLAGS = -Wall -std=c99
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
INCLUDE_PATHS = -I/usr/local/include
LIBRARY_PATHS = -L/usr/local/lib

SRC = grid-base_potential_fields.c
EXEC = potential_field

all: $(EXEC)

$(EXEC):
	$(CC) $(CFLAGS) $(INCLUDE_PATHS) $(SRC) $(LIBRARY_PATHS) $(LDFLAGS) -o $(EXEC)

clean:
	rm -f $(EXEC)

.PHONY: all clean

