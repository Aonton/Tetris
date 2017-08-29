// Source file for the Draw_Game class
// Amy Feng
// 8.27.2017

#include "Draw_Game.h"

Draw_Game::Draw_Game()
{
};

void Draw_Game::Draw_Board(Board board) const
{
   for(uint8_t i=0; i<board.getBOARD_MAX_WIDTH(); i++)
   {
     for(uint8_t j=0; j<board.getBOARD_MAX_LENGTH(); j++)
     {
       if(board.getPoint_Status(i,j)==ENABLED)
          uView.pixel(i,j);
     }
   }
};
