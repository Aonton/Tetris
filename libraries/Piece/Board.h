// Header file for the pixel class
// Amy Feng
// 8.27.2017

#ifndef BOARD_H
#define BOARD_H

#include "Board_Preferences.h"
#include "Piece.h"
#include <Microview.h>

#include "Types.h"

class Board
{
   public:
      Board();

      // prints to serial
      void display_board_state() const;
      point_state getPoint_Status(uint8_t,uint8_t) const;

      uint8_t getBOARD_MAX_WIDTH() const;
      uint8_t getBOARD_MAX_LENGTH() const;

      void setCurr_Piece(type_of_piece,orientation,uint8_t,uint8_t);

      void update();

   private:
     static const uint8_t BOARD_MAX_WIDTH =64;
     static const uint8_t BOARD_MAX_LENGTH =48;

     // Need Link List --- To Do
     point_state point_status[BOARD_MAX_WIDTH][BOARD_MAX_LENGTH];

     Piece curr_piece;


};

#endif
