// Header file fot the board
// that displays the upcoming pieces
// 7/30/2017
// Amy Feng

#include "PieceBoard.h"
#include <MicroView.h>

PieceBoard::PieceBoard(){
   start_board[0]=0;
   start_board[1]=0;
   start_piece[0]=1;
   start_piece[1]=1;
};

void PieceBoard::display(){
   // Draw the PieceBoard border
   uView.rect(start_board[0],start_board[1],width,height);

   // Draw the pieces
   // REORGANIZE
   for(int i=0; i<list.getSizeOfList();i++)
   {   Serial.println(list.getSizeOfList());

       if(list[i]==NULL)
       {  list[i]->setPieceLoc(start_piece[0],start_piece[1]+(dis_btw_pieces*i));
          /*Serial.println("start");
          Serial.println(start_piece[0]);
          Serial.println(dis_btw_pieces*i);*/
          //list[i]->draw(scale);
       }
       else
       {
         Serial.println("PieceBoard::display() - ERROR: List pointer is NULL");
       }
   }
};
