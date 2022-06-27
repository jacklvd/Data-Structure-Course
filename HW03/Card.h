#ifndef CARD_H
#define CARD_H

class Card{

  public:

    int value;
    char suit;

		// constructor and initialize variable
    Card(){
      value = 0;
      suit = ' ';
    }

		// another constructor
    Card(int uval, char usuit){
      value = uval;
      suit = usuit;
    }
};

#endif