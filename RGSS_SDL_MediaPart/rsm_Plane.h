#include "SDL.h"
#include "pch.h"
#include "rsm_bitmap.h"
#include "rsm_Viewport.h"
#include "rsm_Tone.h"

class RSM_Plane
{
private:
    RSM_Bitmap *bitmap;
    RSM_Viewport *viewport;
    SDL_Color color;
    RSM_Tone tone;
public:
    bool visible;
    int ox,oy;
    int z;
    double zoom_x,zoom_y;
    int opacity;
    int blend_type;
    RSM_Plane();
    RSM_Plane(RSM_Viewport *viewport);
    ~RSM_Plane();
    void setBitmap(RSM_Bitmap *bitmap);
    void setViewport(RSM_Viewport *viewport);
    void setColor(SDL_Color color);
    void setTune(RSM_Tone tone);
};
