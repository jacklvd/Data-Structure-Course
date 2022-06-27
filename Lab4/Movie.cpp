#include <cstring>
#include <iostream>
#include "Movie.h"

/*
Initialize and overidde the Show class with derived Movie class
*/

// Default constructor
Movie::Movie() {
  credits = " ";
}

// Default constructor with 4 parameters
Movie::Movie(string utitle, string udescription, string ucredits) {
  this->credits = ucredits;
  this->title = utitle;
  this->description = udescription;
}

/*
Getter and Setter functions of Movie
*/
string Movie::getCredits() {
  return credits;
}

void Movie::setCredits(string ucredits) {
  credits = ucredits;
}

// override Play() function in class Show
void Movie::Play() {

  cout << "Opening Credits:" << endl;

  cout << this->credits << endl << endl;

  Show::details();
}