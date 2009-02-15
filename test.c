#include <SDL.h>

int main(int argc, char **argv)
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetVideoMode(640, 480, 32, 0);
	SDL_Delay(2000);
	SDL_Quit();

	return 0;
}
