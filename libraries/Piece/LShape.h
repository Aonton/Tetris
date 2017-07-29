// Tetris Piece Derived class header file:
// L piece
// 7/21/2017
// Amy Feng

#ifndef L_SHAPE_H
#define L_SHAPE_H

#include <MicroView.h>
#include "Tetrominoes.h"

class LShape: public Tetrominoes{
  public:
    LShape();
    LShape(int,int,int);

    virtual bool draw() const;
    // TO DO: MOVE THIS COMMENT TO A MORE APP. PLACE
    // Note piece_loc is the top left most pixel
    // when the L shape is in orientation DEGREE0
    // []...........................................
    // []...........................................
    // [][].........................................
  private:

};

#endif
