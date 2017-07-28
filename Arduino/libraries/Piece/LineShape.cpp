// Source file for line pieces
// Amy Feng
// 7/25/2017

#include "LineShape.h"

LineShape::LineShape(){
  Serial.print("LineShape Constructor");
  Serial.println();
};

void LineShape::draw(){
  uView.line(0,0,4,0);
  uView.line(0,1,4,1);
  Serial.println("Draw line");
};
