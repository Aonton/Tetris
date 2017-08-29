// Tetris Piece Derived class header file:
// Mirrored L piece
// 7/21/2017
// Amy Feng

#ifndef MIRRORED_L_SHAPE_H
#define MIRRORED_L_SHAPE_H

#include <MicroView.h>
#include "Tetrominoes.h"

class MirroredLShape: public Tetrominoes{
  public:
    MirroredLShape();
    MirroredLShape(int,int,int,int);
    // For MAX_WIDTH and MAX_HEIGHT
    virtual void setBorders();

    virtual bool draw() const;
    // TO DO: MOVE THIS COMMENT TO A MORE APP. PLACE
    // Note piece_loc is the top left most pixel
    // when the Mirrored L shape is in orientation DEGREE0
    // if the Mirrored L shape had an extra square to the
    // top left ....................................
    // ..[].........................................
    // ..[].........................................
    // [][].........................................
  private:

};

#endif
