// Source file for line pieces
// Amy Feng
// 7/25/2017

#include "LineShape.h"

LineShape::LineShape(): Tetrominoes(){
  Serial.print("LineShape Constructor");
  Serial.println();
};

LineShape::LineShape(int c,int x, int y):
                     Tetrominoes(c,x,y){};

void LineShape::draw(){

  const int col=8;
  const int row=1;
  // int add_to_loc[numOfCoord]={0,0,0,0};
  // change add_to_loc to determine the line length
  int location[2]={getPieceLoc(1),getPieceLoc(2)};

  // try to remove hard coding later

  // Line piece will look like this [][][][]
  if (currentOrient==DEGREE0 || currentOrient==DEGREE180)
  { Serial.println("horizontal");
    if(location[0]<=display_size_len-col && location[1]!=display_size_wid)
    { uView.line(location[0],location[1],location[0]+col,location[1]);
      uView.line(location[0],location[1]+row,location[0]+col,location[1]+row);
    }
    else
    {
      Serial.println("Piece is at the edge");
    }
  }
  // Line piece will look like this []
  // ...............................[]
  // ...............................[]
  // ...............................[]
  else if (currentOrient==DEGREE90 || currentOrient==DEGREE270)
  { Serial.println("vertical");
    if(location[0]!=0 && location[1]<=display_size_wid-col);
    { uView.line(location[0],location[1],location[0],location[1]+col);
      uView.line(location[0]-row,location[1],location[0],location[1]+col);
    }
  }
  else
  {
    Serial.println("Incorrect Orienation");
  }

  // add for loop for the other sizes
  // Might be a better way to do this
  /*uView.line(piece_loc[0]+add_to_loc[0],piece_loc[1]+add_to_loc[1],
             piece_loc[0]+add_to_loc[2],piece_loc[1]+add_to_loc[3]);*/

  //uView.line(0,0,8,0);
  //uView.line(0,1,8,1);
  Serial.println("Draw line");
};
