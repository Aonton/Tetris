// Source file for L pieces
// Amy Feng
// 7/25/2017

#include "LShape.h"

LShape::LShape(): Tetrominoes(){};

LShape::LShape(int c, int x, int y):
                     Tetrominoes(c,x,y){};

bool LShape::draw() const{
  const int location[2]={getPieceLoc(1),getPieceLoc(2)};
  const int numOfCoord=16;

// FIND A WAY TO SCALE THE PIECES
  switch(getCurrentOrient())
  {
     case DEGREE0:
     {   // L piece will look like this []..
         // ............................[]..
         // ............................[][]
         const int points[numOfCoord]={location[0],location[1],location[0],location[1]+3,
                                       location[0]+1,location[1]+2,location[0]+2,location[1]+2,
                                       location[0]+1,location[1],location[0]+1,location[1]+2,
                                       location[0]+1,location[1]+3,location[0]+2,location[1]+3};

         return(drawDegree(display_size_len-1,display_size_wid-2,points,numOfCoord));
     }
     break;
     case DEGREE90:
     {   // L piece will look like this [][][]
         // ............................[]....
         const int points[numOfCoord]={location[0],location[1],location[0]+3,location[1],
                                       location[0],location[1]+1,location[0],location[1]+2,
                                       location[0],location[1]+1,location[0]+3,location[1]+1,
                                       location[0]+1,location[1]+1,location[0]+1,location[1]+2};

         return(drawDegree(display_size_len-2,display_size_wid-1,points,numOfCoord));

     }
     break;
     case DEGREE180:
     {   // L piece will look like this [][]
         // ..............................[]
         // ..............................[]

         const int points[numOfCoord]={location[0]+1,location[1],location[0]+1,location[1]+3,
                                       location[0],location[1],location[0]+1,location[1],
                                       location[0]+2,location[1],location[0]+2,location[1]+3,
                                       location[0],location[1]+1,location[0]+1,location[1]+1};

         return(drawDegree(display_size_len-1,display_size_wid-2,points,numOfCoord));
     }
     break;
     case DEGREE270:
     {   // L piece will look like this [][][]
         // ................................[]

         const int points[numOfCoord]={location[0],location[1],location[0]+3,location[1],
                                       location[0]+2,location[1]+1,location[0]+2,location[1]+2,
                                       location[0],location[1]+1,location[0]+3,location[1]+1,
                                       location[0]+3,location[1]+1,location[0]+3,location[1]+2};

         return(drawDegree(display_size_len-2,display_size_wid-1,points,numOfCoord));

      }
      break;
      default:
      {   Serial.println("Incorrect Orientation");
          return false;
      }
   }; // end of switch statement
};
