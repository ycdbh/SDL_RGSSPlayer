#include "pch.h"
#include "rsm_Sprite.h"

///------------------------------------------------------------
//  ��ʼ�����飨û��ָ���ӿڣ� 
//    ����δָ���ӿڣ������½�һ���ӿ�
///------------------------------------------------------------
RSM_Sprite::RSM_Sprite()
{
	m_viewport = new RSM_Viewport(0, 0, g_screen_width, g_screen_height);
	m_viewport->add_sprite(this);
}

///------------------------------------------------------------
//  ��ʼ�����飨ָ���ӿڣ� 
//    ָ���ӿڣ�����Ѿ�����䵽��Ӧ�ӿ�
///------------------------------------------------------------
RSM_Sprite::RSM_Sprite(RSM_Viewport *viewport)
{
	m_viewport = viewport;
	m_viewport->add_sprite(this);
}

///------------------------------------------------------------
//  �ͷž��� 
//    �����ӿ���ɾ������
///------------------------------------------------------------
RSM_Sprite::~RSM_Sprite()
{
	m_viewport->del_sprite(this);
}

///------------------------------------------------------------
//  ����λͼ
//    ���ľ�����ʾ��λͼ
///------------------------------------------------------------
void RSM_Sprite::set_bitmap(RSM_Bitmap *bitmap)
{
	m_bitmap = bitmap;
}

///------------------------------------------------------------
//  ����λͼ
//    ���ľ�����ʾ��λͼ
///------------------------------------------------------------
RSM_Bitmap *RSM_Sprite::get_bitmap()
{
	return m_bitmap;
}

///------------------------------------------------------------
//  �����ӿ�
//    ���ľ�����ʾ���ӿ�
///------------------------------------------------------------
void RSM_Sprite::set_viewport(RSM_Viewport *viewport)
{
	m_viewport->del_sprite(this);
	m_viewport = viewport;
	m_viewport->add_sprite(this);
}

///------------------------------------------------------------
//  �����ӿ�
//    ���ľ�����ʾ���ӿ�
///------------------------------------------------------------
RSM_Viewport* RSM_Sprite::get_viewport()
{
	return m_viewport;
}

///------------------------------------------------------------
//  ������ʾ
//    ���ӿ��л���λͼ
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
