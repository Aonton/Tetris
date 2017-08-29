// File for enum types
// Amy Feng
// 8.27.2017

#ifndef TYPES_H
#define TYPES_H

enum point_state
{
   DISABLED = 0,
   ENABLED  = 1,
   UNUSED   = 2,
};

enum type_of_piece
{
  LINE      = 0,
  L         = 1,
  MIRROREDL = 2,
  SQUARE    = 3,
  S         = 4,
  T         = 5,
  Z         = 6,
};

enum orientation
{
  DEGREE0   = 0,
  DEGREE90  = 1,
  DEGREE180 = 2,
  DEGREE270 = 3,
};

#endif
