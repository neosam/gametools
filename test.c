#include <SDL.h>
#include "gt_time.h"

int main(int argc, char **argv)
{
	SDL_Surface *screen;
	SDL_Event event;
	int done = 0;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetVideoMode(640, 480, 32, 0);

	atexit(SDL_Quit);

	GT_time_InitTime(GT_TIME_USEDELAY);
	while (!done) {
		GT_time_WaitForFrame();
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				done = 1;
				break;
			}
		}
	}

	return 0;
}
