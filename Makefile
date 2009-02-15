HOST=
SDL_PREFIX_BIN=
BIN_SUFFIX=

OBJ=test.o gt_time.o

SDL_CONFIG_BIN=$(SDL_BIN_PREFIX)sdl-config
LIBS=`$(SDL_CONFIG_BIN) --libs`
CFLAGS=`$(SDL_CONFIG_BIN) --cflags`

CC=$(HOST)gcc

BINARY=test$(BIN_SUFFIX)

all: $(BINARY)

$(BINARY): $(OBJ)
	$(CC) $(OBJ) -o $(BINARY) $(LIBS)

test.o: test.c gt_time.h

gt_time.o: gt_time.c gt_time.h

clean:
	rm -f $(OBJ) $(BINARY) $(BINARY)
