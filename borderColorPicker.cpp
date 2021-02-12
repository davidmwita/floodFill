#include "borderColorPicker.h"

borderColorPicker::borderColorPicker(unsigned int borderSize, HSLAPixel fillColor, PNG &img, double tolerance)
{
    this->borderSize = borderSize;
    this->fillColor = fillColor;
    this->img = img;
    this->tolerance = tolerance;
}

HSLAPixel borderColorPicker::operator()(point p)
{
    unsigned int width = img.width();
    unsigned int height = img.height();


    if (p.x < borderSize || p.x > width-1-borderSize)
      return fillColor;

    if (p.y < borderSize || p.y > height-1-borderSize)
      return fillColor;


      for (unsigned int x = 0; x < width; x++) {
        for (unsigned int y = 0; y < height; y++) {

          bool isNear = false;

          unsigned int distSq = (p.x-x)*(p.x-x) + (p.y-y)*(p.y-y);

              if (p.x+x >= 0 && p.x+x <= width-1 && p.y >= 0 && p.y <= height-1)
                if(!isNear && distSq <= borderSize*borderSize)
                  isNear = img.getPixel(p.c.x, p.c.y)->dist(*img.getPixel(x, y)) > tolerance;

              if (p.x >= 0 && p.x <= width-1 && p.y+y >= 0 && p.y+y <= height-1) {
                 if(!isNear && distSq <= borderSize*borderSize)
                  isNear = img.getPixel(p.c.x, p.c.y)->dist(*img.getPixel(x, y)) > tolerance;
              }

              if (p.x-x >= 0 && p.x-x <= width-1 && p.y >= 0 && p.y <= height-1) {
                if(!isNear && distSq <= borderSize*borderSize)
                  isNear = img.getPixel(p.c.x, p.c.y)->dist(*img.getPixel(x, y)) > tolerance;
              }

              if (p.x >= 0 && p.x <= width-1 && p.y-y >= 0 && p.y-y <= height-1) {
                if(!isNear && distSq <= borderSize*borderSize)
                  isNear = img.getPixel(p.c.x, p.c.y)->dist(*img.getPixel(x, y)) > tolerance;
              }

             if (p.x+x >= 0 && p.x+x <= width-1 && p.y+y >= 0 && p.y+y <= height-1) {
               if(!isNear && distSq <= borderSize*borderSize)
                 isNear = img.getPixel(p.c.x, p.c.y)->dist(*img.getPixel(x, y)) > tolerance;
             }

             if (p.x-x >= 0 && p.x-x <= width-1 && p.y-y >= 0 && p.y-y <= height-1) {
               if(!isNear && distSq <= borderSize*borderSize)
                 isNear = img.getPixel(p.c.x, p.c.y)->dist(*img.getPixel(x, y)) > tolerance;
             }

             if(isNear)
              return fillColor;
        }
      }







    HSLAPixel ret = *img.getPixel(p.x, p.y);
    return ret;
}















// for (unsigned int x = 0; x < borderSize; x++) {
//   for (unsigned int y = 0; y < borderSize; y++) {
//
//     bool isNear = false;
//
//     if (p.x+x >= 0 && p.x+x <= width-1 && p.y >= 0 && p.y <= height-1)
//       isNear = img.getPixel(p.c.x, p.c.y)->dist(*img.getPixel(p.x+x, p.y)) >= tolerance;
//
//     if (p.x >= 0 && p.x <= width-1 && p.y+y >= 0 && p.y+y <= height-1) {
//        if(!isNear)
//         isNear = img.getPixel(p.c.x, p.c.y)->dist(*img.getPixel(p.x, p.y+y)) >= tolerance;
//     }
//
//     if (p.x-x >= 0 && p.x-x <= width-1 && p.y >= 0 && p.y <= height-1) {
//       if(!isNear)
//         isNear = img.getPixel(p.c.x, p.c.y)->dist(*img.getPixel(p.x-x, p.y)) >= tolerance;
//     }
//
//     if (p.x >= 0 && p.x <= width-1 && p.y-y >= 0 && p.y-y <= height-1) {
//       if(!isNear)
//         isNear = img.getPixel(p.c.x, p.c.y)->dist(*img.getPixel(p.x, p.y-y)) >= tolerance;
//     }
//
//    unsigned int distSq = x*x + y*y;
//
//    if (p.x+x >= 0 && p.x+x <= width-1 && p.y+y >= 0 && p.y+y <= height-1) {
//      if(!isNear && distSq <= borderSize*borderSize)
//        isNear = img.getPixel(p.c.x, p.c.y)->dist(*img.getPixel(p.x+x, p.y+y)) >= tolerance;
//    }
//
//    if (p.x-x >= 0 && p.x-x <= width-1 && p.y-y >= 0 && p.y-y <= height-1) {
//      if(!isNear && distSq <= borderSize*borderSize)
//        isNear = img.getPixel(p.c.x, p.c.y)->dist(*img.getPixel(p.x-x, p.y-y)) >= tolerance;
//    }
//
//
//     if (isNear)
//       return fillColor;
//
//   }
// }
