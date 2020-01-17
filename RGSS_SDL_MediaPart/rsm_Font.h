#pragma once
#include "SDL.h"
#include "SDL_ttf.h"

class RSM_Font
{
public:
	RSM_Font(const char *filename, int size);
	~RSM_Font();

	const char *name(const char *filename);
	int size(int size);

private:
	const char *_filename;
	int _size;

public:
	TTF_Font *_font;
	SDL_Color _color;
};