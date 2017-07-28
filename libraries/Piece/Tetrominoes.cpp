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
