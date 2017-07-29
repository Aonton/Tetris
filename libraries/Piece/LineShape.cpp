// Source file for line pieces
// Amy Feng
// 7/25/2017

#include "LineShape.h"

LineShape::LineShape(): Tetrominoes(){};

LineShape::LineShape(int c,int x, int y):
                     Tetrominoes(c,x,y){};

bool LineShape::draw(int scale) const{

bool is_true=false;
const int width=1*scale;
const int height=4*scale;

  switch(getCurrentOrient())
  {
     case DEGREE0:
     case DEGREE180:
     {   // Line piece will look like this [][][][]

         if(drawDegree(display_size_len-3-((scale-1)*4),display_size_wid))
         { uView.rectFill(getPieceLoc(1),getPieceLoc(2),height,width);
           is_true=true;
         }
     }
     break;
     case DEGREE90:
     case DEGREE270:
     {   // Line piece will look like this []..
         // ...............................[]..
         // ...............................[]..
         // ...............................[]..

         if(drawDegree(display_size_len,display_size_wid-3-((scale-1)*4)))
         { uView.rectFill(getPieceLoc(1),getPieceLoc(2),width,height);
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
