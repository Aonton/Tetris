// Source file for Generate Piece Class
// Amy Feng
// 8/27/2017

#include "Generate_Piece.h"

Generate_Piece::Generate_Piece()
{

};

uint8_t Generate_Piece::numPicker(){
  static uint8_t prevNumber=7;
  static uint8_t randNumber=7;

  do{
     randNumber=random(0,7); // generate random number between 0 & 6
                             // (minimum is inclusive, maximum is exclusive)
  }while(prevNumber==randNumber);

  prevNumber=randNumber;

  return randNumber;
};
