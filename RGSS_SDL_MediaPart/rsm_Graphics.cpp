#include "pch.h"
#include "rsm_Graphics.h"

void RSM_Graphics::add_viewport(RSM_Viewport *viewport)
{
	g_viewport_list.push_back(viewport);
}

void RSM_Graphics::del_viewport(RSM_Viewport *viewport)
{
	for (auto i = g_viewport_list.begin(); i != g_viewport_list.end(); i++)
	{
		if (*i == viewport)
		{
			g_viewport_list.erase(i);
			i = g_viewport_list.begin();
		}
	}
}

int RSM_Graphics::update()
{
	SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 255);
	SDL_RenderClear(g_renderer);
	std::sort(g_viewport_list.begin(), g_viewport_list.end(), [](RSM_Viewport* a, RSM_Viewport* b) { return a->z > b->z; }); // < = ÉıĞò | > = ½µĞò
	for (auto iter = g_viewport_list.begin(); iter != g_viewport_list.end(); iter++)
		(*iter)->update();
	SDL_RenderPresent(g_renderer);
	return true;
}