#pragma once
#include "SDL.h"
#include "rsm_Sprite.h"
#include "rsm_Graphics.h"
#include <vector>
#include <algorithm>

class RSM_Viewport
{
public:
	RSM_Viewport(int _x, int _y, int _w, int _h);
	~RSM_Viewport();

	void add_sprite(RSM_Sprite *sprite);
	void del_sprite(RSM_Sprite *sprite);

	void update();
	void refresh();

private:
	unsigned char *m_buffer;

public:
	SDL_Surface *m_surface;
	std::vector<RSM_Sprite*> _spr_list;
	int x;
	int y;
	int z;
	int width;
	int height;

};