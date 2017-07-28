// Tetris Piece Derived class header file:
// line piece
// 7/21/2017
// Amy Feng

#ifndef LINE_SHAPE_H
#define LINE_SHAPE_H

#include <MicroView.h>
#include "Tetrominoes.h"

class LineShape: public Tetrominoes{
  public:
    LineShape();
    LineShape(int,int,int);

    virtual void draw();
    // TO DO: MOVE THIS COMMENT TO A MORE APP. PLACE
    // Note piece_loc is the top left most pixel
    // when line [][][][] is orientation 0 and 180 degrees
  private:
};

#endif
