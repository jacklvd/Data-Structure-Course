#include "Shelf.h"
#include "FullShelf.h"
#include "EmptyShelf.h"

Shelf::Shelf(){
  numGames = 0;
  //We don't need to set anything in array games to blank because that's done implicitly when we create an array of type boardgames, by calling it's default constructor
}

void Shelf::addGame(BoardGame board) {
  int i = 0;
  while (games[i].getTitle() != "" && i < SIZE_OF_SHELF){
    i++;
  }
  if (i >= SIZE_OF_SHELF){
    FullShelfException e;
    throw e;
  }else{
    games[i].setTitle(board.getTitle());
    games[i].setDescription(board.getDescription());
    numGames++;
  }
}

BoardGame Shelf::removeGame(int pos){
  EmptyShelfException e;
  if (games[pos-1].getTitle() == "") {
    throw e;
  };
  BoardGame temp = games[pos-1];
  games[pos-1].setTitle("");
  games[pos-1].setDescription("");
  numGames--;
  return temp;  
}

void Shelf::display(){
  cout << "Number of Games currently on shelf: " << numGames << endl;
  for (int i = 0; i < SIZE_OF_SHELF; i++){
    cout << i + 1 << ". " << games[i].getTitle() << endl;
    cout << "\tDescription: " << games[i].getDescription() << endl;
  }
}
