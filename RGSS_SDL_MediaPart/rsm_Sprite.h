#pragma once
#include "SDL.h"
#include "rsm_bitmap.h"
#include "rsm_Viewport.h"
#include "rsm_Tone.h"

class RSM_Viewport;

class RSM_Sprite
{
public:
	RSM_Sprite();
	RSM_Sprite(RSM_Viewport *viewport);
	~RSM_Sprite();

	void set_bitmap(RSM_Bitmap *bitmap);
	RSM_Bitmap *get_bitmap();

	void set_viewport(RSM_Viewport *viewport);
	RSM_Viewport *get_viewport();

	void update();

private:
	RSM_Bitmap *m_bitmap;
	RSM_Viewport *m_viewport;

public:
	int x;
	int y;
	int z;
	RSM_Tone tone;
};
