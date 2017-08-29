// Source file for Piece Class
// Amy Feng
// 8/27/2017

#include "Piece.h"

Piece::Piece()
{
  // Default piece is .... []
  // ..................... []
  // ..................... []
  // ..................... []
  setType(LINE);
  setOrientation(DEGREE0);
  setPixel(0,0);
};

Piece::Piece(uint8_t x,uint8_t y,type_of_piece t,orientation o)
{
   setPixel(x,y);
   setType(t);
   setOrientation(o);
   buildPiece();
};

// Mutator Methods

void Piece::setType(type_of_piece t)
{
  if(t>=0 && t<7)
  {
    type=t;
  }
  else
  {
    uView.println(F("Piece::setType(): Incorrect Type: Type set to line"));
    type=LINE;
  }
};

void Piece::setOrientation(orientation o)
{
  if(o==DEGREE0 || o==DEGREE90 || o==DEGREE180 || o==DEGREE270)
  {
    orient=o;
  }
  else
  {
    uView.println(F("Piece::setOrientation(): Incorrect orientation: Orientation set to DEGREE0"));
  }
};

void Piece::setPixel(uint8_t x, uint8_t y)
{
  pixel.setPieceLoc(x,y);
};

// Acessor Methods

uint8_t Piece::get_points(uint8_t index) const
{
   return(points.get(index));
};

uint8_t Piece::get_size() const
{
  return(points.size());
};

// Building Pieces

void Piece::buildPiece()
{
   switch(type)
   {
     case LINE:
        buildLine();
     break;
     case L:
        buildL();
     break;
     case MIRROREDL:
        buildMirroredL();
     break;
     case SQUARE:
        buildSquare();
     break;
     case S:
        buildS();
     break;
     case T:
        buildT();
     break;
     case Z:
        buildZ();
     break;
     default:
        uView.println(F("Piece::buildPiece(): Incorrect Type"));
   }

   rotate(orient);
};

void Piece::buildLine()
{
   linePts(pixel.getPieceLoc(1),pixel.getPieceLoc(2),Board_Preferences::SCALE,4*Board_Preferences::SCALE);
};

void Piece::buildL()
{
   if(linePts(pixel.getPieceLoc(1),pixel.getPieceLoc(2),Board_Preferences::SCALE,3*Board_Preferences::SCALE))
      linePts(pixel.getPieceLoc(1)+1,pixel.getPieceLoc(2)+2,Board_Preferences::SCALE,Board_Preferences::SCALE);
};

void Piece::buildMirroredL()
{
   if(linePts(pixel.getPieceLoc(1)+1,pixel.getPieceLoc(2),Board_Preferences::SCALE,3*Board_Preferences::SCALE))
      linePts(pixel.getPieceLoc(1),pixel.getPieceLoc(2)+2,Board_Preferences::SCALE,Board_Preferences::SCALE);
};

void Piece::buildSquare()
{
   linePts(pixel.getPieceLoc(1),pixel.getPieceLoc(2),2*Board_Preferences::SCALE,2*Board_Preferences::SCALE);
};

void Piece::buildS()
{
   if(linePts(pixel.getPieceLoc(1)+1,pixel.getPieceLoc(2),2*Board_Preferences::SCALE,Board_Preferences::SCALE))
      linePts(pixel.getPieceLoc(1),pixel.getPieceLoc(2)+1,2*Board_Preferences::SCALE,Board_Preferences::SCALE);
};

void Piece::buildT()
{
   if(linePts(pixel.getPieceLoc(1)+1,pixel.getPieceLoc(2),Board_Preferences::SCALE,Board_Preferences::SCALE))
      linePts(pixel.getPieceLoc(1),pixel.getPieceLoc(2)+1,3*Board_Preferences::SCALE,Board_Preferences::SCALE);
};

void Piece::buildZ()
{
   if(linePts(pixel.getPieceLoc(1),pixel.getPieceLoc(2),2*Board_Preferences::SCALE,Board_Preferences::SCALE))
     linePts(pixel.getPieceLoc(1)+1,pixel.getPieceLoc(2)+1,2*Board_Preferences::SCALE,Board_Preferences::SCALE);
};

bool Piece::linePts(uint8_t a, uint8_t b,uint8_t x,uint8_t y)
{
  for(uint8_t j=0; j<=y; j++)
  {  for(uint8_t i=0; i<=x; i++)
     {
         if(a+i> Board_Preferences::BOARD_WID || a+i<0 || b+j<0 || b+j>Board_Preferences::BOARD_LEN)
         {  points.add(a+i);
            points.add(b+j);
         }
         else
         {
           uView.println(F("Piece::linePts(): Point out of range"));
           points.clear();
           return false;
         }
      }
  }

  return true;
}

bool Piece::rotate(uint8_t times)
{
  for(uint8_t i=0; i<times; i++)
  {  uint8_t temp=points.size()/2;

     for(uint8_t j=0; j<temp/2; j++)
     {  uint8_t x_rot=pixel.getPieceLoc(1)-pixel.getPieceLoc(2)+points.get(2);
        uint8_t y_rot=pixel.getPieceLoc(1)+pixel.getPieceLoc(2)-points.get(1);
        if(x_rot> Board_Preferences::BOARD_WID || x_rot<0 || y_rot<0 || y_rot>Board_Preferences::BOARD_LEN)
        {  points.add(x_rot);
           points.add(y_rot);
           points.remove(1);
           points.remove(1);
        }
        else
        {
           uView.println(F("Piece::rotate(): Unable to rotate due to bounds"));
        }
     }
  }
}
