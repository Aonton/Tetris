// Source file for S pieces
// Amy Feng
// 7/25/2017

#include "SShape.h"

SShape::SShape(): Tetrominoes(){
   setBorders();
};

SShape::SShape(int c, int x, int y, int s):
                     Tetrominoes(c,x,y,s){
  setBorders();
};

bool SShape::draw() const{
  bool is_true=false;
  const int width=2*scale;
  const int height=1*scale;
  int repos[2]={0,0};

  switch(getCurrentOrient())
  {
     case DEGREE0:
     case DEGREE180:
     {   // Z piece will look like this ..[][]
         // ............................[][]..

         if(drawDegree())
         {   repos[0]=1*scale;
             repos[1]=1*scale;

             uView.rectFill(getPieceLoc(1)+repos[0],getPieceLoc(2),width,height);
             uView.rectFill(getPieceLoc(1),getPieceLoc(2)+repos[1],width,height);
             is_true=true;
         }
     }
     break;
     case DEGREE90:
     case DEGREE270:
     {   // L piece will look like this []..
         // ............................[][]
         // ..............................[]

         if(drawDegree())
         {   repos[0]=1*scale;
             repos[1]=1*scale;

             uView.rectFill(getPieceLoc(1),getPieceLoc(2),height,width);
             uView.rectFill(getPieceLoc(1)+repos[0],getPieceLoc(2)+repos[1],height,width);
             is_true=true;
         }

     }
     break;
     default:
     {   Serial.println("SShape::draw() - Incorrect Orientation");
     }
   }; // end of switch statement

   return is_true;
};

void SShape::setBorders(){
  switch(getCurrentOrient())
  {   case DEGREE0:
      case DEGREE180:
      {
         MAX_WIDTH=display_size_len-2-((scale-1)*3);
         MAX_HEIGHT=display_size_wid-1-((scale-1)*2);
      }
      break;
      case DEGREE90:
      case DEGREE270:
      {
         MAX_WIDTH=display_size_len-1-((scale-1)*2);
         MAX_HEIGHT=display_size_wid-2-((scale-1)*3);
      }
      break;
      default:
      {
         Serial.println("SShape::setBorders() - Incorrect Orientation");
      }
  }; // end of switch function
};
