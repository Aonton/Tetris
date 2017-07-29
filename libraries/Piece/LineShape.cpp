// Source file for line pieces
// Amy Feng
// 7/25/2017

#include "LineShape.h"

LineShape::LineShape(): Tetrominoes(){};

LineShape::LineShape(int c,int x, int y):
                     Tetrominoes(c,x,y){};

bool LineShape::draw() const{
  const int location[2]={getPieceLoc(1),getPieceLoc(2)};
  const int numOfCoord=8;

  // FIND A WAY TO SCALE THE PIECES
  switch(getCurrentOrient())
  {
     case DEGREE0:
     case DEGREE180:
     {   // Line piece will look like this [][][][]
         const int points[numOfCoord]={location[0],location[1],location[0]+4,location[1],
                                       location[0],location[1]+1,location[0]+4,location[1]+1};

         return(drawDegree(display_size_len-3,display_size_wid,points,numOfCoord));
     }
     break;
     case DEGREE90:
     case DEGREE270:
     {   // Line piece will look like this []..
         // ...............................[]..
         // ...............................[]..
         // ...............................[]..
         const int points[numOfCoord]={location[0],location[1],location[0],location[1]+4,
                                       location[0]+1,location[1],location[0]+1,location[1]+4};

         return(drawDegree(display_size_len,display_size_wid-3,points,numOfCoord));

     }
     break;
     default:
     {   Serial.println("Incorrect Orientation");
         return false;
     }
  }; // end of switch statement
};
