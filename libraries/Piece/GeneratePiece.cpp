// Source file for the class that
// generates random tetris pieces
// 7/29/2017
// Amy Feng

#include "GeneratePiece.h"

GeneratePiece::GeneratePiece(){
   setList();
};

GeneratePiece::~GeneratePiece(){
  bool is_NULL=false;

  for(int i=0; i<size_of_list; i++)
  {
    if(list[i]!=NULL)
    {
       delete list[i];
    }
    else
    {
       Serial.print("List ");
       Serial.print(i+1);
       Serial.println(" is empty");
    }
  }
};

int GeneratePiece::numPicker(){
  //static int prevNumber=7;
  static int randNumber=7;

  //do{
     randNumber=random(0,7); // generate random number between 0 & 6
                             // (minimum is inclusive, maximum is exclusive)
     //Serial.println("numPicker");
     //Serial.println(randNumber);
  //}while(prevNumber==randNumber);

  //prevNumber=randNumber;

  Serial.println("numPicker");
  Serial.println(randNumber);

  return randNumber;
};

// Overloaded Operators
Tetrominoes* GeneratePiece::operator[](int num) const{
  return (getList(num));
}

// Mutator Methods
void GeneratePiece::setList(){
   for(int i=0; i<size_of_list; i++)
   {
     //currentPiece=numPicker();
     //Serial.println("RandomNumber");
     //Serial.println(currentPiece);

     currentPiece=i;

     //Order: Line,L,MirroredL,Square,S,T,Z
     switch(currentPiece)
     {   case Line:
         {
            list[i]=new LineShape();
            Serial.println("LineShape");
         }
         break;
         case L:
         {
            list[i]=new LShape();
            Serial.println("LShape");
         }
         break;
         case MirroredL:
         {
            list[i]=new MirroredLShape();
            Serial.println("MirroredLShape");
         }
         break;
         case Square:
         {
            list[i]=new SquareShape();
            Serial.println("SquareShape");
         }
         break;
         case S:
         {
            list[i]=new SShape();
            Serial.println("SShape");
         }
         break;
         case T:
         {
            list[i]=new TShape();
            Serial.println("TShape");
         }
         break;
         case Z:
         {
            list[i]=new ZShape();
            Serial.println("ZShape");
         }
         break;
         default:
         {
            Serial.println("Incorrect Piece Type");
         }
     }; // end of switch statement
  } // end of for loop
}

// Accessor Methods
Tetrominoes* GeneratePiece::getList(int num) const{
   if(num<=size_of_list && num>=0)
   {   // List should never be able to be NULL
       if(list[num-1]!=NULL)
       {
          return(list[num-1]);
       }
       else
       {
          Serial.println("ERROR: This piece pointer is NULL");
          return NULL;
       }
    }
    else
    {
       Serial.println("Getting piece out of range of the list");
       return NULL;
    }
};

int GeneratePiece::getSizeOfList() const{
   return size_of_list;
}
