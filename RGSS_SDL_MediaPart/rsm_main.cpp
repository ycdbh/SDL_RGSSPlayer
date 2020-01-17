#include "pch.h"
#include "rsm_main.h"

int RSM_Init(const char *title, int width, int height, Uint32 style)
{
	g_screen_width = width;
	g_screen_height = height;

	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	TTF_Init();

	SDL_Window *window = SDL_CreateWindow(title,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, style);
	g_renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 255);
	SDL_RenderClear(g_renderer);

	return true;
}

int RSM_Quit()
{
	SDL_DestroyRenderer(g_renderer);
	g_viewport_list.clear();
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
	return true;
}