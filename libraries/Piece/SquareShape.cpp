// Source file for mirrored Square pieces
// Amy Feng
// 7/25/2017

#include "SquareShape.h"

SquareShape::SquareShape(): Tetrominoes(){
   setBorders();
};

SquareShape::SquareShape(int c,int x, int y, int s):
                     Tetrominoes(c,x,y,s){
  setBorders();
};

bool SquareShape::draw() const{
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

         if(drawDegree())
         {   uView.rectFill(getPieceLoc(1),getPieceLoc(2),width,height);
             is_true=true;
         }
     }
     break;
     default:
     {   Serial.println("SquareShape::draw() - Incorrect Orientation");
     }
  }; // end of switch statement

  return is_true;
};

void SquareShape::setBorders(){
  switch(getCurrentOrient())
  {   case DEGREE0:
      case DEGREE180:
      case DEGREE90:
      case DEGREE270:
      {
         MAX_WIDTH=display_size_len-(2*scale)+1;
         MAX_HEIGHT=display_size_wid-(2*scale)+1;
      }
      break;
      default:
      {
         Serial.println("SquareShape::setBorders() - Incorrect Orientation");
      }
  }; // end of switch function
};
