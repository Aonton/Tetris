#include <SoftwareSerial.h>
#include <MicroView.h>

#include <LineShape.h>
#include <LShape.h>
#include <MirroredLShape.h>
#include <SquareShape.h>
#include <SShape.h>
#include <Tetrominoes.h>
#include <TShape.h>
#include <ZShape.h>

// global space (Remember: Does it really need to be here?!)
enum buttons { UNUSED1= 0, UNUSED2= 1, UP = 2, DOWN = 3, LEFT = 5, RIGHT =6 };

LineShape test;
//LShape test;

void setup() {
  const int numOfPins=6;
  buttons pins[numOfPins]={UNUSED1,UNUSED2,UP,DOWN,LEFT,RIGHT};

  uView.begin();
  uView.clear(PAGE);
  uView.display();
  Serial.begin(9600);

  for (int i=2; i<numOfPins; i++)
  {
     pinMode(pins[i], INPUT);
  };

}

void loop() {

  uView.clear(PAGE);

  if(digitalRead(UP) == LOW)
  {   test.draw();
  }

  if(digitalRead(DOWN) == LOW)
  {   uView.line(0,0,20,20);
  }

  if(digitalRead(LEFT) == LOW)
  {   uView.line(0,0,30,30);
  }

  if(digitalRead(RIGHT) == LOW)
  {   uView.line(0,0,40,40);
  }

  uView.display();
}
