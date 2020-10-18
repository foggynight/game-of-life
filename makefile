CC=g++
CFLAGS=-lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

SRCS=$(wildcard src/*.cpp)
PROG=game-of-life

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(SRCS) -o $(PROG) $(CFLAGS)

.PHONY: uninstall
uninstall:
	rm -rf $(PROG)
