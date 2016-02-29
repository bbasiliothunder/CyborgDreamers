#ifndef UNIVERSAL_H_INCLUDED
#define UNIVERSAL_H_INCLUDED

static int window_width = 800;
static int window_height = 600;
static float fps = 30.0;
static float spf = 1.0/fps;

static float clamp(float var, float mini, float maxi)
{
    if(var < mini) return mini;
    else if( var > maxi) return maxi;
    return var;
}


#endif // UNIVERSAL_H_INCLUDED
