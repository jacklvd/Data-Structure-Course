#ifndef ENTERTAINMENTCOLLECTION_H
#define ENTERTAINMENTCOLLECTION_H
#include "EmptyShelf.h"
#include "FullShelf.h"
#include "VideoGame.h"
const static int SIZE_OF_SHELF = 10;

using namespace std;
template <class T>

class EntertainmentCollection {
  protected:
    T games[SIZE_OF_SHELF];
    int numGames;
    int arrow;
    T empty;
  public:
    //Default Constructor
    EntertainmentCollection(){
        empty = games[0];
        for (int i = 0; i < SIZE_OF_SHELF; ++i){
          games[i] = empty;
        }
        arrow = 0;
        numGames = 0;
    }
    //Add and Remove function for the array of games
    void addGame(T input){
      FullShelfException e;
      if (numGames == SIZE_OF_SHELF){
        throw e;
        return;
      }
      games[numGames] = input;
      numGames++;
      cout << "Game has been added to the collection." << endl;
      cout << endl;
    }

    T removeGame(){
      EmptyShelfException e;
      T temp;
      if (numGames == 0) {
        throw e;
        return empty;
      };
      numGames--;
      temp = games[numGames];
      games[numGames] = empty;
      cout << "The following game with these attributes has been removed:" << endl << endl;
      return temp;
    }

    int getNumGames(){ return numGames; };

    T display(){
      int iinput = 0;
      while ((iinput <= 0) || (iinput >= 11)){
        cout << "What Game would you like to view? (1-10): "<< endl;
        cin >> iinput;
        if ((iinput <= 0) || (iinput >= 11)){
          cout << "Invalid input, please try again.";
        }
      }
      return games[iinput - 1];
    }

    int length() {
      return numGames;
    }
};


#endif