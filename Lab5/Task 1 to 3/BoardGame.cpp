#include "BoardGame.h"

BoardGame::BoardGame(){
  title = "";
  description = "";
};

BoardGame::BoardGame(string utitle, string udescription){
  title = utitle;
  description = udescription;
};

void BoardGame::setTitle(string utitle){
  title = utitle;
};

void BoardGame::setDescription(string udescription){
  description = udescription;
};

string BoardGame::getTitle(){
  return title;
};

string BoardGame::getDescription(){
  return description;
};

void BoardGame::details(){
  cout << "Title: " << title << endl;
  cout << "Description: " << endl << description << endl << endl;
};