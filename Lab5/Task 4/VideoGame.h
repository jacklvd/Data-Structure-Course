#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include "Game.h"
using namespace std;

class Video : public Game {
private:
    int difficulty;

public:
  //Change functions
  Video(){
    difficulty = 0;
  }
  void Play() {
      cout << "Smash the button!" << endl;
  }
  void Result() {
      cout << "Winner music ..." << endl;
  }

  //Getter and setter for difficulty
  void setDiff(int i) {
      difficulty = i;
  }
  int getDiff() {
      return difficulty;
  }

  bool operator== (Video lhs){
    if ((difficulty == lhs.getDiff() && (numPlayer == lhs.getPlayer())) && (score == lhs.getScore())){
      return true;
    }else{
    return false;
    }
  }
  void print(){
    cout << "Difficuly: " << difficulty << "\n" << "Number of Players: " << numPlayer << "\n";
    cout << "Score: " << score << endl;
  }
};
#endif
