#include "pch.h"
#include "rsm_Viewport.h"

RSM_Viewport::RSM_Viewport(int _x, int _y, int _w, int _h)
{
	this->x = _x;
	this->y = _y;
	this->width = _w;
	this->height = _h;
	RSM_Graphics::add_viewport(this);
	m_buffer = new unsigned char[this->width * this->height * 4];
	m_surface = SDL_CreateRGBSurfaceWithFormatFrom((void*)m_buffer, this->width, this->height, 32, 4 * this->width, SDL_PIXELFORMAT_RGBA32);
}

RSM_Viewport::~RSM_Viewport()
{
	_spr_list.clear();
	SDL_FreeSurface(m_surface);
	delete[]m_buffer;
	m_surface = NULL;
	RSM_Graphics::del_viewport(this);
}

void RSM_Viewport::add_sprite(RSM_Sprite* sprite)
{
	_spr_list.push_back(sprite);
}

void RSM_Viewport::del_sprite(RSM_Sprite* sprite)
{
	for (auto iter = _spr_list.begin(); iter != _spr_list.end(); iter++)
	{
		if (*iter == sprite)
		{
			_spr_list.erase(iter);
			iter = _spr_list.begin();
		}
	}
}

void RSM_Viewport::update()
{
	delete[]m_buffer;
	m_buffer = new unsigned char[this->width * this->height * 4];
	std::sort(_spr_list.begin(), _spr_list.end(), [](RSM_Sprite *a, RSM_Sprite *b) { return a->z > b->z; }); // < = ÉýÐò | > = ½µÐò
	for (auto iter = _spr_list.begin(); iter != _spr_list.end(); iter++)
		(*iter)->update();
	SDL_Rect rt;
	rt.x = this->x;
	rt.y = this->y;
	rt.w = this->width;
	rt.h = this->height;
	SDL_Texture *pTexture = SDL_CreateTextureFromSurface(g_renderer, m_surface);
	SDL_RenderCopy(g_renderer, pTexture, NULL, &rt);
	SDL_DestroyTexture(pTexture);
}

void RSM_Viewport::refresh()
{
	SDL_FreeSurface(m_surface);
	delete[]m_buffer;
	m_buffer = new unsigned char[this->width * this->height * 4];
	m_surface = SDL_CreateRGBSurfaceWithFormatFrom((void*)m_buffer, this->width, this->height, 32, 4 * this->width, SDL_PIXELFORMAT_RGBA32);
}
