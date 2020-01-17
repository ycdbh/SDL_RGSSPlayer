#include "pch.h"
#include "rsm_bitmap.h"

RSM_Bitmap::RSM_Bitmap(const char* filename)
{
	m_surface = IMG_Load(filename);
}

RSM_Bitmap::RSM_Bitmap(int width, int height)
{
	m_buffer = new unsigned char[width * height * 4];
	m_surface = SDL_CreateRGBSurfaceWithFormatFrom((void*)m_buffer, width, height, 32, 4 * width, SDL_PIXELFORMAT_RGBA32);
}

RSM_Bitmap::~RSM_Bitmap()
{
	SDL_FreeSurface(m_surface);
	delete[]m_buffer;
	m_surface = NULL;
}

int RSM_Bitmap::width()
{
	return m_surface->w;
}

int RSM_Bitmap::height()
{
	return m_surface->h;
}

SDL_Rect *RSM_Bitmap::rect()
{
    return new SDL_Rect { 0, 0, m_surface->w, m_surface->h };
}

void RSM_Bitmap::stretch_blt(SDL_Rect *dest_rect, SDL_Surface *src_surface, SDL_Rect *src_rect, Uint8 opacity)
{
	SDL_SetSurfaceAlphaMod(src_surface, opacity);
	SDL_BlitSurface(src_surface, src_rect, m_surface, dest_rect);
	SDL_SetSurfaceAlphaMod(src_surface, 255);
}

void RSM_Bitmap::gradient_fill_rect(int x, int y, int width, int height, SDL_Color color1, SDL_Color color2, int vertical)
{
    unsigned char *pixels = (unsigned char*)m_surface->pixels;
    if (vertical) {
        for (int yi = 0; yi < height; yi++) {
            unsigned char r, g, b, a;
            r = (color1.r * (height - yi) + color2.r * yi) / height;
            g = (color1.g * (height - yi) + color2.g * yi) / height;
            b = (color1.b * (height - yi) + color2.b * yi) / height;
            a = (color1.a * (height - yi) + color2.a * yi) / height;
            for (int xi = 0; xi < width; xi++) {
                int index = ((yi + y) * width + xi + x) << 2;
                pixels[index] = r;
                pixels[index + 1] = g;
                pixels[index + 2] = b;
                pixels[index + 3] = a;
            }
        }
    }
    else {
        for (int xi = 0; xi < width; xi++) {
            unsigned char r, g, b, a;
            r = (color1.r * (width - xi) + color2.r * xi) / width;
            g = (color1.g * (width - xi) + color2.g * xi) / width;
            b = (color1.b * (width - xi) + color2.b * xi) / width;
            a = (color1.a * (width - xi) + color2.a * xi) / width;
            for (int yi = 0; yi < height; yi++) {
                int index = ((yi + y) * width + xi + x) << 2;
                pixels[index] = r;
                pixels[index + 1] = g;
                pixels[index + 2] = b;
                pixels[index + 3] = a;
            }
        }
    }
}

void RSM_Bitmap::fill_rect(SDL_Rect *rect, Uint32 color)
{
    SDL_FillRect(m_surface, rect, color);
}

void RSM_Bitmap::draw_text(SDL_Rect *rect, char* str)
{
	SDL_Surface* text_surface;
	text_surface = TTF_RenderUTF8_Solid(m_font->_font, str, m_font->_color);
	TTF_RenderUTF8_Blended(m_font->_font, str, m_font->_color);
	SDL_BlitSurface(text_surface, NULL, m_surface, rect);
	SDL_FreeSurface(text_surface);
}
