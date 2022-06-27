#ifndef GAME_H
#define GAME_H
#include <iostream>
using namespace std;

// Main/Base class
class Game {
  protected:
  int numPlayer, score;

  public:
  Game();
  Game(int a, int b);
  /////////////////////
  void setPlayer(int x);
  void setscore(int x);
  int getPlayer();
  int getScore();
  /////////////////////
  virtual void Play();
  void result();

};

#endif