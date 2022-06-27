#ifndef MOVIE_H
#define MOVIE_H

#include "Show.h"
#include <cstring>
using namespace std;


// Initialized the Movie class inheritance from Show
class Movie: public Show{
  protected:
    string credits;
  
  public:
    Movie();
    Movie(string, string, string);
    //getter and setter function
    string getCredits();
    void setCredits(string);
    ////////////////////////////
    void Play();
};

#endif
