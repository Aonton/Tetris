// Tetris Piece Derived class header file:
// line piece
// 7/21/2017
// Amy Feng

#ifndef LINE_SHAPE_H
#define LINE_SHAPE_H

#include <SoftwareSerial.h>
#include <MicroView.h>
#include "Tetrominoes.h"

class LineShape: public Tetrominoes{
  public:
    LineShape();
    virtual void draw();
  private:
};

#endif
