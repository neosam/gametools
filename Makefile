HOST=
SDL_PREFIX_BIN=
BIN_SUFFIX=

OBJ=test.o

SDL_CONFIG_BIN=$(SDL_BIN_PREFIX)sdl-config
LIBS=`$(SDL_CONFIG_BIN) --libs`
CFLAGS=`$(SDL_CONFIG_BIN) --cflags`

CC=$(HOST)gcc

BINARY=test$(BIN_SUFFIX)

all: $(BINARY)

$(BINARY): $(OBJ)
	$(CC) $(OBJ) -o $(BINARY) $(LIBS)

test.o: test.c

clean:
	rm -f $(OBJ) $(BINARY) $(BINARY)
