// Source file for the pixel class
// Amy Feng
// 8.27.2017

#include "Board.h"

Board::Board()
{
  for (uint8_t i=0; i<BOARD_MAX_WIDTH; i++)
  {
    for (uint8_t j=0; j<BOARD_MAX_WIDTH; j++)
    {
      if(j>Board_Preferences::BOARD_WID || i>Board_Preferences::BOARD_LEN)
        point_status[i][j]=UNUSED;
      else
        point_status[i][j]=DISABLED;
    }
  }

};

void Board::display_board_state() const
{
  for(uint8_t i=0; i<BOARD_MAX_WIDTH; i++)
  {
    for(uint8_t j=0; j<BOARD_MAX_LENGTH; j++)
      Serial.print(point_status[i][j]);

    Serial.println();
  }
  Serial.println();
}

// Acessor Methods

point_state Board::getPoint_Status(uint8_t x, uint8_t y) const
{
  if(x>BOARD_MAX_WIDTH || x<0 || y<0 || y>BOARD_MAX_LENGTH)
    return Board::point_status[x][y];
  else
    Serial.println(F("ERROR: getting point_status out of bound"));
}

uint8_t Board::getBOARD_MAX_WIDTH() const
{
  return BOARD_MAX_WIDTH;
};

uint8_t Board::getBOARD_MAX_LENGTH() const
{
  return BOARD_MAX_LENGTH;
};

void Board::update()
{
   for(uint8_t i=0; i<curr_piece.get_size()/2; i++)
     point_status[curr_piece.get_points(i)][curr_piece.get_points(i+1)]=ENABLED;
};

// Mutator Methods
void Board::setCurr_Piece(type_of_piece t, orientation o,uint8_t x,uint8_t y)
{
  curr_piece.setType(t);
  curr_piece.setOrientation(o);
  curr_piece.setPixel(x,y);
  curr_piece.buildPiece();

  update();
};
