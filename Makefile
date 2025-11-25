CC = gcc
CFLAGS = -Wall -Iinclude -Icli-lib/include

SRC = src/main.c \
      src/board.c \
      src/game.c \
      src/player.c \
      src/logic.c \
      src/ranking.c

CLI_SRCS = cli-lib/src/keyboard.c \
           cli-lib/src/screen.c \
           cli-lib/src/timer.c

OBJS = $(SRC:.c=.o) $(CLI_SRCS:.c=.o)

TARGET = build/jogo

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p build
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

cli-lib/src/%.o: cli-lib/src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf src/*.o cli-lib/src/*.o build/*

.PHONY: all clean
