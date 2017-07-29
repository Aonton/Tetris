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
    Tetrominoes(int,int,int);

    void setPieceLoc(int,int);
    int getPieceLoc(int) const;

    void setCurrentOrient(int);
    int getCurrentOrient() const;
  protected:
    virtual bool draw() const=0;
    bool drawDegree(int,int,int[],int) const;

   // should be rid of this enum-> useless
    enum orientation { DEGREE0=0, DEGREE90=90, DEGREE180=180, DEGREE270=270 };

    // this will go somewhere else later
    static const int display_size_len=64;
    static const int display_size_wid=48;

  private:
    // This value must be always checked to make
    // it fits the mircoview 48x64 screen
    int piece_loc[2];
    orientation currentOrient;
};

#endif
