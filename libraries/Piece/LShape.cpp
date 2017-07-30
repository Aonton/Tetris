// Source file for L pieces
// Amy Feng
// 7/25/2017

#include "LShape.h"

LShape::LShape(): Tetrominoes(){};

LShape::LShape(int c, int x, int y):
                     Tetrominoes(c,x,y){};

bool LShape::draw(int scale) const{
  bool is_true=false;
  const int width_rec=1*scale;
  const int height_rec=3*scale;
  const int width_sq=1*scale;
  const int height_sq=1*scale;
  int repos[2]={0,0};

  switch(getCurrentOrient())
  {
     case DEGREE0:
     {   // L piece will look like this []..
         // ............................[]..
         // ............................[][]

         if(drawDegree(display_size_len-1-((scale-1)*2),display_size_wid-2-((scale-1)*3)))
         {   repos[0]=1*scale;
             repos[1]=2*scale;

             uView.rectFill(getPieceLoc(1),getPieceLoc(2),width_rec,height_rec);
             uView.rectFill(getPieceLoc(1)+repos[0],getPieceLoc(2)+repos[1],width_sq,height_sq);
             is_true=true;
         }
     }
     break;
     case DEGREE90:
     {   // L piece will look like this [][][]
         // ............................[]....

         if(drawDegree(display_size_len-2-((scale-1)*3),display_size_wid-1-((scale-1)*2)))
         {   repos[1]=1*scale;

             uView.rectFill(getPieceLoc(1),getPieceLoc(2),height_rec,width_rec);
             uView.rectFill(getPieceLoc(1),getPieceLoc(2)+repos[1],width_sq,height_sq);
             is_true=true;
         }

     }
     break;
     case DEGREE180:
     {   // L piece will look like this [][]
         // ..............................[]
         // ..............................[]

         if(drawDegree(display_size_len-1-((scale-1)*2),display_size_wid-2-((scale-1)*3)))
         {   repos[0]=1*scale;

             uView.rectFill(getPieceLoc(1)+repos[0],getPieceLoc(2),width_rec,height_rec);
             uView.rectFill(getPieceLoc(1),getPieceLoc(2),width_sq,height_sq);
             is_true=true;
         }

     }
     break;
     case DEGREE270:
     {   // L piece will look like this ....[]
         // ............................[][][]

         if(drawDegree(display_size_len-2-((scale-1)*3),display_size_wid-1-((scale-1)*2)))
         {   repos[0]=2*scale;
             repos[1]=1*scale;

             uView.rectFill(getPieceLoc(1),getPieceLoc(2)+repos[1],height_rec,width_rec);
             uView.rectFill(getPieceLoc(1)+repos[0],getPieceLoc(2),width_sq,height_sq);
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
