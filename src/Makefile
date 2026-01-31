CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99 -I./include
LDFLAGS = -L./lib
LIBS    = -lraylib -lm -ldl -lpthread -lrt -lX11

SRC = main.c \
      lib/map.c \
      lib/player.c

OUT = raycaster

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(LDFLAGS) $(LIBS)

clean:
	rm -f $(OUT)

.PHONY: all clean
