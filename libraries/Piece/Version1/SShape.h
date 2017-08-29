// Tetris Piece Derived class header file:
// S piece
// 7/21/2017
// Amy Feng

#ifndef S_SHAPE_H
#define S_SHAPE_H

#include <MicroView.h>
#include "Tetrominoes.h"

class SShape: public Tetrominoes{
  public:
    SShape();
    SShape(int,int,int,int);
    // For MAX_WIDTH and MAX_HEIGHT
    virtual void setBorders();

    virtual bool draw() const;
    // TO DO: MOVE THIS COMMENT TO A MORE APP. PLACE
    // Note piece_loc is the top left most pixel
    // when the S shape is in orientation DEGREE0
    // ..[][].........................................
    // [][]...........................................
  private:

};

#endif
