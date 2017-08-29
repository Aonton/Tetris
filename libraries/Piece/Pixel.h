// Header file for the pixel class
// Amy Feng
// 8.2.2017

#ifndef PIXEL_H
#define PIXEL_H

#include <MicroView.h>

class Pixel{
   public:
     Pixel();
     Pixel(uint8_t,uint8_t);

     void setPieceLoc(uint8_t,uint8_t);
     uint8_t getPieceLoc(uint8_t) const;

   private:
     static const uint8_t dim=2;
     // This is the upper left pixel
     // of the piece
     uint8_t piece_loc[dim];

};

#endif
