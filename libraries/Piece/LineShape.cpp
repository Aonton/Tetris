// Source file for line pieces
// Amy Feng
// 7/25/2017

#include "LineShape.h"

LineShape::LineShape(): Tetrominoes(){
   setBorders();
};

LineShape::LineShape(int c,int x, int y, int s):
                     Tetrominoes(c,x,y,s){
   setBorders();
};

bool LineShape::draw() const{

bool is_true=false;
const int width=1*scale;
const int height=4*scale;

  switch(getCurrentOrient())
  {
     case DEGREE0:
     case DEGREE180:
     {   // Line piece will look like this [][][][]

         if(drawDegree())
         {   uView.rectFill(getPieceLoc(1),getPieceLoc(2),height,width);
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

         if(drawDegree())
         {   uView.rectFill(getPieceLoc(1),getPieceLoc(2),width,height);
             is_true=true;
         }
     }
     break;
     default:
     {   Serial.println("LineShape::draw() - Incorrect Orientation");
     }
  }; // end of switch statement

  return is_true;
};

void LineShape::setBorders(){
  switch(getCurrentOrient())
  {   case DEGREE0:
      case DEGREE180:
      {
         MAX_WIDTH=display_size_len-3-((scale-1)*4);
         MAX_HEIGHT=display_size_wid-(scale-1);
      }
      break;
      case DEGREE90:
      case DEGREE270:
      {
         MAX_WIDTH=display_size_len-(scale-1);
         MAX_HEIGHT=display_size_wid-3-((scale-1)*4);
      }
      break;
      default:
      {
         Serial.println("LineShape::setBorders() - Incorrect Orientation");
      }
  }; // end of switch function
};
