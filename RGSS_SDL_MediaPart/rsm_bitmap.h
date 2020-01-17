#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "rsm_Font.h"

class RSM_Bitmap
{
public:
	RSM_Bitmap(const char *filename);
	RSM_Bitmap(int width, int height);
	~RSM_Bitmap();

	int width();
	int height();
	SDL_Rect *rect();

	void stretch_blt(SDL_Rect *dest_rect, SDL_Surface *src_surface, SDL_Rect *src_rect, Uint8 opacity);
	void gradient_fill_rect(int x, int y, int width, int height, SDL_Color color1, SDL_Color color2, int vertical);
	void fill_rect(SDL_Rect *rect, Uint32 color);
	void draw_text(SDL_Rect *rect, char *str);

private:
	unsigned char *m_buffer;

public:
	SDL_Surface* m_surface;
	RSM_Font *m_font;
};
