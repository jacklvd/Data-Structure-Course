#include <iostream>
#include <cstring>
#include <random>
#include "Shelf.h"
#include "BoardGame.h"
#include "EmptyShelf.h"
#include "FullShelf.h"

void instruction() {

  cout << "------------------------------------------" << endl << endl;
  cout << "Press 1 to add a board game to the shelf." << endl;
  cout << "Press 2 to remove a board game from the shelf." << endl;
  cout << "Press 3 to see how many board games are currently on the shelf." << endl;
  cout << "Press 4 to quit." << endl << endl;
}

int main() {

  Shelf shelf;
  BoardGame boards;
  int input;
  string str;

  cout << "Welcom to the Game Shelves" << endl << endl;

  while (true) {

    instruction();
    cout << "Your input: ";
    cin >> input;
    cout << endl;

    // to prevemt running into infinite loop when getting invalid input
    if (!cin) {
      input = 0;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n' );
    }    

    switch(input) {
      
      case 1:
        try { // adding the game
          cout << "Please enter your game title: ";
          cin >> str;
          boards.setTitle(str);
          cout << endl;
          cout << "Please enter your game description:" << endl << "\t";
          cin >> str;
          boards.setDescription(str);
          cout << endl;
          shelf.addGame(boards);
        } catch (FullShelfException e){
          cout << "Shelf is full, please remove a game before adding a new one." << endl;
        } 
        break;

      case 2: //remove the game as a specific index
        try {
          shelf.display();
          cout << "Which game would you like to delete from 1 to 10?" << endl;
          cin >> input;
          cout << endl;
          shelf.removeGame(input);
          cout << "Your game has been removed!" << endl;    
        } catch (EmptyShelfException e){
          cout << "Shelf is Empty, please add a game before trying to remove one" << endl;
        }    
        break;

      case 3: // display current games on the shelf
        shelf.display();
        break;

      case 4: // terminate the program
        return 0;
        break;

      default:
        cout << "Invalid Input" << endl;
        break;
    }
  }
}