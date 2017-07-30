// Header file for the class that
// generates random tetris pieces
// 7/29/2017
// Amy Feng

#ifndef GENERATE_PIECE_H
#define GENERATE_PIECE_H

#include "Tetrominoes.h"
#include "LineShape.h"
#include "LShape.h"
#include "MirroredLShape.h"
#include "SquareShape.h"
#include "SShape.h"
#include "TShape.h"
#include "ZShape.h"

class GeneratePiece{
   public:
     GeneratePiece();
     ~GeneratePiece();

     Tetrominoes* operator[](int) const;

     int numPicker();

     void setList();
     int getSizeOfList() const;

   private:
     Tetrominoes* getList(int) const;

     Tetrominoes* list[];
     enum Pieces {Line=0, L=1, MirroredL=2, Square=3, S=4, T=5, Z=6};
     Pieces currentPiece;
     static const int size_of_list=3;
     // Must Store pieces too for the gameplay

};

#endif
