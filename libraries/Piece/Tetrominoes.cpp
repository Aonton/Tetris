// Source file for tetrominoes pieces
// Amy Feng
// 7/25/2017

#include "Tetrominoes.h"

Tetrominoes::Tetrominoes(){
  currentOrient=DEGREE0;
  setPieceLoc(0,0);
  scale=3;
};

// custom constructor not working????
Tetrominoes::Tetrominoes(int c,int x, int y, int s):Tetrominoes(){
  setCurrentOrient(c);
  setPieceLoc(x,y);
  setScale(s);

  // Derived classes must reset this value
  MAX_WIDTH=display_size_wid;
  MAX_HEIGHT=display_size_len;
};

// Mutator methods
bool Tetrominoes::setPieceLoc(int x,int y){
  bool fits=false;

  if(x>=0 && x<MAX_WIDTH &&
     y>=0 && y<MAX_HEIGHT)
  { piece_loc[0]=x;
    piece_loc[1]=y;
    fits=true;
  }
  else
     Serial.println("piece_loc exceeds display size");

  return fits;

};

void Tetrominoes::setCurrentOrient(int c){
  for(int i=0; i<=270; i=i+90)
  { if(c==i)
    { currentOrient=c;
      break;
      Serial.println("currentOrient set");
    }
  }

  setBorders();
};

void Tetrominoes::setScale(int s){
  if(s>0)
  {
    scale=s;
  }
  else
  {
    Serial.println("Error: Scale is 0 or less");
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
};

int Tetrominoes::getScale() const{
  return scale;
};

int Tetrominoes::getMaxWidth() const{
  return MAX_WIDTH;
}

int Tetrominoes::getMaxHeight() const{
  return MAX_HEIGHT;
}

bool Tetrominoes::drawDegree() const{
  if(piece_loc[0]<MAX_WIDTH && piece_loc[1]<MAX_HEIGHT)
  {
    return true;
  }
  else
  {
    Serial.println("Piece is at the edge");
    return false;
  }
};

bool Tetrominoes::moveDown(){
  bool at_edge=false;

  if(setPieceLoc(piece_loc[0],piece_loc[1]+1))
  {
    at_edge=true;
  }
  else
  {
        Serial.println("AT THE BOTTOM");
  }

  Serial.println("Tetrominoes::moveDown() -- ");
  Serial.println(piece_loc[0]);
  Serial.println(piece_loc[1]);

  return at_edge;
};
