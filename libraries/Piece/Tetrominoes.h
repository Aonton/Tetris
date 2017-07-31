// Tetrominoes (a tetris piece)
// class header file
// 7/20/2017
// Amy Feng

#ifndef TETROMINOES_H
#define TETROMINOES_H

#include <MicroView.h>

class Tetrominoes{
  public:

    Tetrominoes();
    Tetrominoes(int,int,int,int);

    bool setPieceLoc(int,int);
    int getPieceLoc(int) const;
    int getCurrentOrient() const;
    int getScale() const;

    int getMaxWidth() const;
    int getMaxHeight() const;

    virtual bool draw() const=0;

    virtual bool moveDown();
  protected:
    bool drawDegree() const;
    // For MAX_WIDTH and MAX_HEIGHT
    virtual void setBorders()=0;
    void setCurrentOrient(int);

   // should be rid of this enum-> useless
    enum orientation { DEGREE0=0, DEGREE90=90, DEGREE180=180, DEGREE270=270 };

    // this will go somewhere else later
    static const int display_size_len=64;
    static const int display_size_wid=48;

    int scale;
    int MAX_WIDTH;
    int MAX_HEIGHT;

  private:
    void setScale(int);

    // This value must be always checked to make
    // it fits the mircoview 48x64 screen when scaled
    int piece_loc[2];
    orientation currentOrient;
};

#endif
