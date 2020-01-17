#pragma once
#include "SDL.h"
class RSM_Tone
{
private:
    void limit();
public:
    int red,green,blue,gray;
    RSM_Tone();
    RSM_Tone(RSM_Tone &tone);
    RSM_Tone(int red,int green,int blue,int gray);
    void set(RSM_Tone &tone);
    void set(int red,int green,int blue,int gray);
    ~RSM_Tone();
};
