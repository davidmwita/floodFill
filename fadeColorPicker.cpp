#include "fadeColorPicker.h"

fadeColorPicker::fadeColorPicker(double fade)
{
    fadeFactor = fade;
}

HSLAPixel fadeColorPicker::operator()(point p)
{
    int dist = sqrt(pow((int)p.x - (int)p.c.x, 2) + pow((int)p.y - (int)p.c.y, 2));
    double newL = p.c.color.l * pow(fadeFactor, dist);

    HSLAPixel pixel(p.c.color.h, p.c.color.s, newL);
    return pixel;
}
