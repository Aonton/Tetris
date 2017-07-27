// Source file for line pieces
// Amy Feng
// 7/25/2017

#include "LineShape.h"

LineShape::LineShape(){
  Serial.print("LineShape Constructor");
  Serial.println();
};

void LineShape::draw(){
  uView.line(0,0,10,10);
  Serial.println("Drew line");
};
