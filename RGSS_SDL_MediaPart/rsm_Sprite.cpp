#include "pch.h"
#include "rsm_Sprite.h"

///------------------------------------------------------------
//  初始化精灵（没有指定视口） 
//    由于未指定视口，将会新建一个视口
///------------------------------------------------------------
RSM_Sprite::RSM_Sprite()
{
	m_viewport = new RSM_Viewport(0, 0, g_screen_width, g_screen_height);
	m_viewport->add_sprite(this);
}

///------------------------------------------------------------
//  初始化精灵（指定视口） 
//    指定视口，将会把精灵分配到相应视口
///------------------------------------------------------------
RSM_Sprite::RSM_Sprite(RSM_Viewport *viewport)
{
	m_viewport = viewport;
	m_viewport->add_sprite(this);
}

///------------------------------------------------------------
//  释放精灵 
//    会在视口中删除精灵
///------------------------------------------------------------
RSM_Sprite::~RSM_Sprite()
{
	m_viewport->del_sprite(this);
}

///------------------------------------------------------------
//  更改位图
//    更改精灵显示的位图
///------------------------------------------------------------
void RSM_Sprite::set_bitmap(RSM_Bitmap *bitmap)
{
	m_bitmap = bitmap;
}

///------------------------------------------------------------
//  更改位图
//    更改精灵显示的位图
///------------------------------------------------------------
RSM_Bitmap *RSM_Sprite::get_bitmap()
{
	return m_bitmap;
}

///------------------------------------------------------------
//  关联视口
//    更改精灵显示的视口
///------------------------------------------------------------
void RSM_Sprite::set_viewport(RSM_Viewport *viewport)
{
	m_viewport->del_sprite(this);
	m_viewport = viewport;
	m_viewport->add_sprite(this);
}

///------------------------------------------------------------
//  关联视口
//    更改精灵显示的视口
///------------------------------------------------------------
RSM_Viewport* RSM_Sprite::get_viewport()
{
	return m_viewport;
}

///------------------------------------------------------------
//  更新显示
//    在视口中绘制位图
///------------------------------------------------------------
void RSM_Sprite::update()
{
	if (m_bitmap == NULL) return;
	SDL_Rect rt;
	rt.x = this->x;
	rt.y = this->y;
	rt.w = m_bitmap->m_surface->w;
	rt.h = m_bitmap->m_surface->h;
	SDL_BlitSurface(m_bitmap->m_surface, NULL, m_viewport->m_surface, &rt);
}
