// Tetris Piece Derived class header file:
// Z piece
// 7/21/2017
// Amy Feng

#ifndef Z_SHAPE_H
#define Z_SHAPE_H

#include <MicroView.h>
#include "Tetrominoes.h"

class ZShape: public Tetrominoes{
  public:
    ZShape();
    ZShape(int,int,int);

    virtual bool draw(int) const;
    // TO DO: MOVE THIS COMMENT TO A MORE APP. PLACE
    // Note piece_loc is the top left most pixel
    // when the Z shape is in orientation DEGREE0
    // [][].........................................
    // ..[][].......................................
  private:

};

#endif
