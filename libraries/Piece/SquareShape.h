// Tetris Piece Derived class header file:
// square piece
// 7/21/2017
// Amy Feng

#ifndef SQUARE_SHAPE_H
#define SQUARE_SHAPE_H

#include <MicroView.h>
#include "Tetrominoes.h"

class SquareShape: public Tetrominoes{
  public:
    SquareShape();
    SquareShape(int,int,int);

    virtual bool draw(int) const;
    // TO DO: MOVE THIS COMMENT TO A MORE APP. PLACE
    // Note piece_loc is the top left most pixel
    // when line [][] is in orientation 0
    // ..........[][] ..............................

  private:

};

#endif
