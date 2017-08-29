// Header file for the Draw_Game class
// Amy Feng
// 8.27.2017

#ifndef DRAW_GAME_H
#define DRAW_GAME_H

#include "Board.h"
#include "Types.h"

class Draw_Game{
   public:
     Draw_Game();

     void Draw_Board(Board) const;
     void Draw_Title() const;
     void Draw_Next_Piece_Board() const;
     void Draw_Score() const;

   private:

};

#endif
