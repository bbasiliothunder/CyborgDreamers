#include "Vec2.h"
#include <math.h>
#include <algorithm>

Vec2::Vec2()
{
    x = 0;
    y = 0;
}

Vec2::Vec2(float a, float b)
{
    x = a;
    y = b;
}

float Vec2::getX()
{
    return x;
}

float Vec2::getY()
{
    return y;
}

Vec2 Vec2::operator+(Vec2 that)
{
    Vec2 ret(x+that.getX(), y+that.getY());
    return ret;
}

Vec2 Vec2::operator-(Vec2 that)
{
    Vec2 ret(x-that.getX(), y-that.getY());
    return ret;
}

Vec2 Vec2::operator*(float i)
{
    Vec2 ret(x*i, y*i);
    return ret;
}

float Vec2::operator*(Vec2 that)
{
    return (x*that.getX()) + (y*that.getY());
}

float Vec2::operator%(Vec2 that)
{
    return (x*that.getY())-(y*that.getX());
}


