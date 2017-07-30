// Source file for mirrored Square pieces
// Amy Feng
// 7/25/2017

#include "SquareShape.h"

SquareShape::SquareShape(): Tetrominoes(){};

SquareShape::SquareShape(int c,int x, int y):
                     Tetrominoes(c,x,y){};

bool SquareShape::draw(int scale) const{
  bool is_true=false;
  const int width=2*scale;
  const int height=2*scale;

  switch(getCurrentOrient())
  {
     case DEGREE0:
     case DEGREE180:
     case DEGREE90:
     case DEGREE270:
     {   // Square piece will look like this [][]
         // .................................[][]

         if(drawDegree(display_size_len-(1*scale),display_size_wid-(1*scale)))
         {   uView.rectFill(getPieceLoc(1),getPieceLoc(2),width,height);
             is_true=true;
         }
     }
     break;
     default:
     {   Serial.println("Incorrect Orientation");
     }
  }; // end of switch statement

  return is_true;
};
