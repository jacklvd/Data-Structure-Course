  #include "Game.h"
  
  Game::Game(){
    numPlayer = 0;
    score = 0;
  };
  Game::Game(int a, int b){
    numPlayer = a;
    score = b;
  };
  /////////////////////
  void Game::setPlayer(int x){
    numPlayer = x;
  };
  void Game::setscore(int x){
    score = x;
  };
  int Game::getPlayer(){
    return numPlayer;
  };
  int Game::getScore(){
    return score;
  };
  /////////////////////
  void Game::Play(){
    cout << "The game is about to start ..." << endl << endl;
  };

  void Game::result(){
    cout << "We have a winner!" << endl;
  };

