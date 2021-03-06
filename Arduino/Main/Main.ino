#include <Board.h>
#include <Draw_Game.h>

#include <SoftwareSerial.h>
#include <MicroView.h>

Board board;

// global space (Remember: Does it really need to be here?!)
enum buttons { UNUSED1= 0, UNUSED2= 1, UP = 2, DOWN = 3, LEFT = 5, RIGHT =6 };

// CHECK DRAW LIMIT

void setup() {
  const int numOfPins=6;
  buttons pins[numOfPins]={UNUSED1,UNUSED2,UP,DOWN,LEFT,RIGHT};

  uView.begin();
  uView.clear(PAGE);
  uView.display();
  Serial.begin(9600);
  randomSeed(analogRead(0));

  for (int i=2; i<numOfPins; i++)
  {
     pinMode(pins[i], INPUT);
  };

}

void loop() {

  uView.clear(PAGE);

  //test1.moveDown();
  //test1.draw();

  delay(1000);

  /*if(digitalRead(UP) == LOW)
  {   test.setPieceLoc(0,0);
      test.setCurrentOrient(0);
      test.draw(3);
  }

  if(digitalRead(DOWN) == LOW)
  {   test2.setPieceLoc(0,30);
      test2.setCurrentOrient(90);
      test2.draw(3);
  }

  if(digitalRead(LEFT) == LOW)
  {   test3.setPieceLoc(30,0);
      test3.setCurrentOrient(180);
      test3.draw(3);
  }

  if(digitalRead(RIGHT) == LOW)
  {   test4.setPieceLoc(30,30);
      test4.setCurrentOrient(270);
      test4.draw(3);
  }*/

  uView.display();
}
