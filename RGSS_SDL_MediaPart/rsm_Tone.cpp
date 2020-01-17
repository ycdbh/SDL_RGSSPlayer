#include "pch.h"
#include "rsm_Tone.h"

rsm_Tone::rsm_Tone(int red,int green,int blue,int gray)
{
    this->red=red;
    this->green=green;
    this->blue=blue;
    this->gray=gray;
    limit();
}

rsm_Tone::rsm_Tone(rsm_Tone *tone)
{
    if(tone){
        this->red=tone->red;
        this->green=tone->green;
        this->blue=tone->blue;
        this->gray=tone->gray;
        limit();
    }else{
        this->red=0;
        this->green=0;
        this->blue=0;
        this->gray=0;
    }
}

void rsm_Tone::set(int red,int green,int blue,int gray)
{
    this->red=red;
    this->green=green;
    this->blue=blue;
    this->gray=gray;
    limit();
}

void rsm_Tone::set(rsm_Tone *tone)
{
    if(tone){
        this->red=tone->red;
        this->green=tone->green;
        this->blue=tone->blue;
        this->gray=tone->gray;
        limit();
    }else{
        this->red=0;
        this->green=0;
        this->blue=0;
        this->gray=0;
    }
}
// limit range
void rsm_Tone::limit()
{
    if(this->red>255) this->red=255; else if(this->red<-255) this->red=-255;
    if(this->green>255) this->green=255; else if(this->green<-255) this->green=-255;
    if(this->blue>255) this->blue=255; else if(this->blue<-255) this->blue=-255;
    if(this->gray>255) this->gray=255; else if(this->gray<0) this->gray=0;
}
