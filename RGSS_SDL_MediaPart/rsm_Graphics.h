#pragma once
#include "SDL.h"
#include "rsm_Viewport.h"

namespace RSM_Graphics
{
	void add_viewport(RSM_Viewport *viewport);
	void del_viewport(RSM_Viewport *viewport);

	int update();
}