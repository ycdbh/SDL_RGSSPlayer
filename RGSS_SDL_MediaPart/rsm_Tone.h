#include "SDL.h"
class rsm_Tone
{
private:
    int red,green,blue,gray;
    void limit();
public:
    rsm_Tone(int red,int green,int blue,int gray);
    rsm_Tone(rsm_Tone *tone);
    void set(int red,int green,int blue,int gray);
    void set(rsm_Tone *tone);
    ~rsm_Tone();
};
