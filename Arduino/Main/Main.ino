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

LineShape test(90,40,32);
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
  {   test.setPieceLoc(40,32);
      test.setCurrentOrient(90);
      test.draw();
  }

  if(digitalRead(DOWN) == LOW)
  {   test.setPieceLoc(10,0);
      test.setCurrentOrient(0);
      test.draw();
  }

  if(digitalRead(LEFT) == LOW)
  {   test.setPieceLoc(90,0);
      test.setCurrentOrient(0);
      test.draw();
  }

  if(digitalRead(RIGHT) == LOW)
  {   test.setPieceLoc(0,-1);
      test.setCurrentOrient(90);
      test.draw();
  }

  uView.display();
}
