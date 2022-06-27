#ifndef BOARDGAME_H
#define BOARDGAME_H

#include <cstring>
#include <iostream>
using namespace std;

// Main/Base class
class BoardGame {
  protected:
  string title, description;

  public:
  BoardGame();
  BoardGame(string, string);
  /////////////////////
  void setTitle(string);
  void setDescription(string);
  string getTitle();
  string getDescription();
  /////////////////////
  virtual void Play(){};
  virtual void showdetails(){};
  void details();
};

#endif
