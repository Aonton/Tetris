// Source file for Mirrored L pieces
// Amy Feng
// 7/25/2017

#include "MirroredLShape.h"

MirroredLShape::MirroredLShape(): Tetrominoes(){
   setBorders();
};

MirroredLShape::MirroredLShape(int c, int x, int y, int s):
                     Tetrominoes(c,x,y,s){
  setBorders();
};

bool MirroredLShape::draw() const{
  bool is_true=false;
  const int width_rec=1*scale;
  const int height_rec=3*scale;
  const int width_sq=1*scale;
  const int height_sq=1*scale;
  int repos[2]={0,0};

  switch(getCurrentOrient())
  {
     case DEGREE0:
     {   // Mirrored L piece will look like this []..
         // .....................................[]..
         // ...................................[][]..

         if(drawDegree())
         {   repos[0]=1*scale;
             repos[1]=2*scale;

             uView.rectFill(getPieceLoc(1)+repos[0],getPieceLoc(2),width_rec,height_rec);
             uView.rectFill(getPieceLoc(1),getPieceLoc(2)+repos[1],width_sq,height_sq);
             is_true=true;
         }
     }
     break;
     case DEGREE90:
     {   // Mirrored L piece will look like this []....
         // ............................[][][]

         if(drawDegree())
         {   repos[1]=1*scale;

             uView.rectFill(getPieceLoc(1),getPieceLoc(2)+repos[1],height_rec,width_rec);
             uView.rectFill(getPieceLoc(1),getPieceLoc(2),width_sq,height_sq);
             is_true=true;
         }

     }
     break;
     case DEGREE180:
     {   // Mirrored L piece will look like this [][]
         // ............................[]..
         // ............................[]..

         if(drawDegree())
         {   repos[0]=1*scale;

             uView.rectFill(getPieceLoc(1),getPieceLoc(2),width_rec,height_rec);
             uView.rectFill(getPieceLoc(1)+repos[0],getPieceLoc(2),width_sq,height_sq);
             is_true=true;
         }

     }
     break;
     case DEGREE270:
     {   // Mirrored L piece will look like this [][][]
         // ................................[]

         if(drawDegree())
         {   repos[0]=2*scale;
             repos[1]=1*scale;

             uView.rectFill(getPieceLoc(1),getPieceLoc(2),height_rec,width_rec);
             uView.rectFill(getPieceLoc(1)+repos[0],getPieceLoc(2)+repos[1],width_sq,height_sq);
             is_true=true;
         }
      }
      break;
      default:
      {   Serial.println("MirroredLShape::setBorders() - Incorrect Orientation");
      }
   }; // end of switch statement

   return is_true;
};

void MirroredLShape::setBorders(){
  switch(getCurrentOrient())
  {   case DEGREE0:
      case DEGREE180:
      {
         MAX_WIDTH=display_size_len-1-((scale-1)*2);
         MAX_HEIGHT=display_size_wid-2-((scale-1)*3);
      }
      break;
      case DEGREE90:
      case DEGREE270:
      {
         MAX_WIDTH=display_size_len-2-((scale-1)*3);
         MAX_HEIGHT=display_size_wid-1-((scale-1)*2);
      }
      break;
      default:
      {
         Serial.println("MirroredLShape::setBorders() - Incorrect Orientation");
      }
  }; // end of switch function
};
