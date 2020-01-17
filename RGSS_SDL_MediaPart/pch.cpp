// pch.cpp: 与预编译标头对应的源文件

#include "pch.h"

// 当使用预编译的头时，需要使用此源文件，编译才能成功。

SDL_Renderer* g_renderer;
std::vector<RSM_Viewport*> g_viewport_list;

int g_screen_width;
int g_screen_height;