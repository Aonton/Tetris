// Source file for the pixel class
// Amy Feng
// 8.27.2017

#include "Pixel.h"

Pixel::Pixel()
{
  setPieceLoc(0,0);
}

Pixel::Pixel(uint8_t x, uint8_t y)
{
  setPieceLoc(x,y);
};

// Mutator Methods

// Check is done in .... (TO DO)
void Pixel::setPieceLoc(uint8_t x, uint8_t y)
{
  piece_loc[0]=x;
  piece_loc[1]=y;
};

// Accessor Methods

uint8_t Pixel::getPieceLoc(uint8_t coord) const
{
  if(coord==1 || coord==2)
    return(piece_loc[coord-1]);
  else
  { Serial.println(F("invalid parameter: coord is either 1 or 2"));
    Serial.println(F("0 was returned instead"));
    return 0;
  }
};
