// Source file for tetrominoes pieces
// Amy Feng
// 7/25/2017

#include "Tetrominoes.h"

Tetrominoes::Tetrominoes(){
  currentOrient=DEGREE0;
  setPieceLoc(0,0);
};

Tetrominoes::Tetrominoes(int c,int x, int y):Tetrominoes(){
  setCurrentOrient(c);
  setPieceLoc(x,y);
};

// To do:
// fill in derived

// Mutator methods
void Tetrominoes::setPieceLoc(int x,int y){
  if(x>=0 && x<=display_size_wid &&
     y>=0 && y<=display_size_len)
  { piece_loc[0]=x;
    piece_loc[1]=y;
  }
  else
    Serial.println("piece_loc exceeds display size");

};

// is there anything I need to check?
void Tetrominoes::setCurrentOrient(int c){
  for(int i=0; i<=270; i=i+90)
  { if(c==i)
    { currentOrient=c;
      break;
      Serial.println("currentOrient set");
    }
  }
};

// Accessor methods
int Tetrominoes::getPieceLoc(int coord) const{
  if(coord==1 || coord==2)
    return(piece_loc[coord-1]);
  else
  { Serial.println("invalid parameter: coord is either 1 or 2");
    Serial.println("0 was returned instead");
    return 0;
  }
};

int Tetrominoes::getCurrentOrient() const{
  return currentOrient;
}

bool Tetrominoes::drawDegree(int x_edge, int y_edge, int points[],int numOfCoord) const{
  if(piece_loc[0]<x_edge && piece_loc[1]<y_edge)
  {
    for(int i=0; i<numOfCoord; i=i+4)
    { uView.line(points[i],points[i+1],points[i+2],points[i+3]);
      Serial.print("Set of points ");
      Serial.println(i);
      Serial.println(points[i]);
      Serial.println(points[i+1]);
      Serial.println(points[i+2]);
      Serial.println(points[i+3]);
    }


    return true;
  }
  else
  {
    Serial.println("Piece is at the edge");
    return false;
  }
};
