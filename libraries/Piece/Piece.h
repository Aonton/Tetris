// Header file for the Piece class
// Amy Feng
// 8.27.2017

#ifndef PIECE_H
#define PIECE_H

#include "Types.h"
#include "Pixel.h"
#include <Microview.h>
#include "../LinkedList-1.2.3/LinkedList.h"
#include "Board_Preferences.h"

class Piece
{
   public:
     Piece();
     Piece(uint8_t,uint8_t,type_of_piece,orientation);

     void setType(type_of_piece);
     void setOrientation(orientation);
     void setPixel(uint8_t,uint8_t);

     uint8_t get_points(uint8_t) const;
     uint8_t get_size() const;

     void buildPiece();

     // all builds below set the piece to DEGREE0
     // the orientation is corrected in buildPiece()

   private:
     void buildLine();
     void buildL();
     void buildMirroredL();
     void buildSquare();
     void buildS();
     void buildT();
     void buildZ();

     bool linePts(uint8_t,uint8_t,uint8_t,uint8_t);
     bool rotate(uint8_t);

     Pixel pixel;
     type_of_piece type;
     orientation orient;

     // set these points
     LinkedList<int> points;

};

#endif
