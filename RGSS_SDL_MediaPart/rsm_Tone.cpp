#include "pch.h"
#include "rsm_Tone.h"

RSM_Tone::RSM_Tone(int red,int green,int blue,int gray)
{
    this->red=red;
    this->green=green;
    this->blue=blue;
    this->gray=gray;
    limit();
}

RSM_Tone::RSM_Tone()
{
    this->red=0;
    this->green=0;
    this->blue=0;
    this->gray=0;
    limit();
}

RSM_Tone::RSM_Tone(RSM_Tone &tone)
{
    this->red=tone.red;
    this->green=tone.green;
    this->blue=tone.blue;
    this->gray=tone.gray;
    limit();
}

void RSM_Tone::set(int red,int green,int blue,int gray)
{
    this->red=red;
    this->green=green;
    this->blue=blue;
    this->gray=gray;
    limit();
}

void RSM_Tone::set(RSM_Tone &tone)
{
    this->red=tone.red;
    this->green=tone.green;
    this->blue=tone.blue;
    this->gray=tone.gray;
    limit();
}
// limit range
void RSM_Tone::limit()
{
    if(this->red>255) this->red=255; else if(this->red<-255) this->red=-255;
    if(this->green>255) this->green=255; else if(this->green<-255) this->green=-255;
    if(this->blue>255) this->blue=255; else if(this->blue<-255) this->blue=-255;
    if(this->gray>255) this->gray=255; else if(this->gray<0) this->gray=0;
    //convert
    //TODO: gray: too complicated to calculate
    this->red+=255;
    this->green+=255;
    this->gray+=255;
}
