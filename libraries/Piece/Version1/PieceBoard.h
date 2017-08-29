// Header file fot the board
// that displays the upcoming pieces
// 7/30/2017
// Amy Feng

#ifndef PIECE_BOARD_H
#define PIECE_BOARD_H

#include "GeneratePiece.h"

// This class will be inherit by the base class: DisplayGame
class PieceBoard{
   public:
     PieceBoard();
     void display();

   private:
     GeneratePiece list;

     static const int dimensions=2;
     int start_board[dimensions];
     int start_piece[dimensions];
     static const int dis_btw_pieces=4;
     static const int width=6;
     static const int height=13;

     // This will go in the base class
     static const int scale=1;
};

#endif
