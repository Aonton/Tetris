// Tetrominoes (a tetris piece)
// class header file
// 7/20/2017
// Amy Feng

#ifndef TETROMINOES_H
#define TETROMINOES_H

#include <SoftwareSerial.h>

class Tetrominoes{
  public:
    Tetrominoes();
  protected:
    // Used for writing to the console
    virtual void draw()=0;
  private:
};

#endif
