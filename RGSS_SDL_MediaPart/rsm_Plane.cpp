#include "rsm_Plane.h"

RSM_Plane::RSM_Plane()
{
    this->bitmap=NULL;
    this->viewport=NULL;
    this->color.r=255;
    this->color.g=255;
    this->color.b=255;
    this->color.a=255;
    this->tone=RSM_Tone();
    this->visible=true;
    this->ox=0;
    this->oy=0;
    this->z=1;//?
    this->zoom_x=1.0;
    this->zoom_y=1.0;
    this->opacity=255;
    this->blend_type=0;
}

RSM_Plane::RSM_Plane(RSM_Viewport *viewport)
{
    this->bitmap=NULL;
    this->viewport=viewport;
    this->color.r=255;
    this->color.g=255;
    this->color.b=255;
    this->color.a=255;
    this->tone=RSM_Tone();
    this->visible=true;
    this->ox=0;
    this->oy=0;
    this->z=1;//?
    this->zoom_x=1.0;
    this->zoom_y=1.0;
    this->opacity=255;
    this->blend_type=0;
}

void RSM_Plane::setBitmap(RSM_Bitmap *bitmap){
    this->bitmap=bitmap;
}

void RSM_Plane::setViewport(RSM_Viewport *viewport){
    this->viewport=viewport;
}

void RSM_Plane::setColor(SDL_Color color){
    this->color=color;
}

void RSM_Plane::setTune(RSM_Tone tone){
    this->tone=tone;
}

RSM_Plane::~RSM_Plane()
{
}
