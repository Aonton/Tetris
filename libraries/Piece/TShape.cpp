// Source file for T pieces
// Amy Feng
// 7/25/2017

#include "TShape.h"

TShape::TShape(): Tetrominoes(){
   setBorders();
};

TShape::TShape(int c,int x, int y, int s):
                     Tetrominoes(c,x,y,s){
  setBorders();
};

bool TShape::draw() const{

bool is_true=false;
const int width_rec=1*scale;
const int height_rec=3*scale;
const int width_sq=1*scale;
const int height_sq=1*scale;
int repos[2]={0,0};

  switch(getCurrentOrient())
  {
     case DEGREE0:
     {   // T piece will look like this []
         // ..........................[][][]

         if(drawDegree())
         {   repos[0]=1*scale;
             repos[1]=1*scale;

             uView.rectFill(getPieceLoc(1),getPieceLoc(2)+repos[1],height_rec,width_rec);
             uView.rectFill(getPieceLoc(1)+repos[0],getPieceLoc(2),height_sq,width_sq);
             is_true=true;
         }
     }
     break;
     case DEGREE90:
     {   // T piece will look like this []..
         // ............................[][]
         // ............................[]..

         if(drawDegree())
         {   repos[0]=1*scale;
             repos[1]=1*scale;

             uView.rectFill(getPieceLoc(1),getPieceLoc(2),width_rec,height_rec);
             uView.rectFill(getPieceLoc(1)+repos[0],getPieceLoc(2)+repos[1],height_sq,width_sq);
             is_true=true;
         }

     }
     break;
     case DEGREE180:
     {   // T piece will look like this [][][]
         // ..............................[]..

         if(drawDegree())
         {   repos[0]=1*scale;
             repos[1]=1*scale;

             uView.rectFill(getPieceLoc(1),getPieceLoc(2),height_rec,width_rec);
             uView.rectFill(getPieceLoc(1)+repos[0],getPieceLoc(2)+repos[1],height_sq,width_sq);
             is_true=true;
         }

     }
     break;
     case DEGREE270:
     {   // T piece will look like this ..[]
         // ............................[][]
         // ..............................[]

         if(drawDegree())
         {   repos[0]=1*scale;
             repos[1]=1*scale;

             uView.rectFill(getPieceLoc(1)+repos[0],getPieceLoc(2),width_rec,height_rec);
             uView.rectFill(getPieceLoc(1),getPieceLoc(2)+repos[1],height_sq,width_sq);
             is_true=true;
         }

     }
     break;
     default:
     {   Serial.println("TShape::draw() - Incorrect Orientation");
     }
  }; // end of switch statement

  return is_true;
};

void TShape::setBorders(){
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
         Serial.println("TShape::setBorders() - Incorrect Orientation");
      }
  }; // end of switch function
};
