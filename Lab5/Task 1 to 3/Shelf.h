#ifndef SHELF_H
#define SHELF_H
#include <cstring>
#include <iostream>
#include "BoardGame.h"
const static int SIZE_OF_SHELF = 10;

using namespace std;

class Shelf{
  protected:
    BoardGame games[SIZE_OF_SHELF];
    int numGames;
  public:
    //Default Constructor
    Shelf();
    //Add and Remove function for the array of games
    void addGame(BoardGame);
    BoardGame removeGame(int);
    //Getters and Setters for numGames and games
    int getNumGames(){return numGames;};
    //void setNumGames(int num){numGames = num;};
    //BoardGame getGamesElement(int i){return games[i];};
    //void setGamesElement(int i, BoardGame game){games[i] = game;};
    void display();
};

#endif