#include "EntertainmentCollection.h"
#include <random>

// print out the instruction for user
void instruction() {

  cout << "------------------------------------------" << endl << endl;
  cout << "Press 1 to add a video game to the collection." << endl;
  cout << "Press 2 to remove a video game from the collection." << endl;
  cout << "Press 3 to see how many video games are currently on the collection." << endl;
  cout << "Press 4 to quit." << endl << endl;
}

// main execute of the program
int main() {
  Game game;
  EntertainmentCollection<Video> a;
  int input;
  int diff;
  Video display;
  Video newGame;
  
  cout << "Welcome to the Video Game Collection!" << endl << endl;

  while (true) {

    instruction();
    cout << "Your input: ";
    cin >> input;
    cout << endl;

    // to prevent running to infinite loop when getting invalid input
    if (!cin) {
      input = 0;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n' );
    }    

    switch(input) {
      
      case 1:
        cout << "Enter the difficulty: ";
        cin >> diff;
        cout << endl;
        newGame.setDiff(diff);
        cout << "Enter the Number of Players: ";
        cin >> diff;
        cout << endl;
        newGame.setPlayer(diff);
        cout << "Enter the Score: ";
        cin >> diff;
        cout << endl;
        newGame.setscore(diff);
        try {
          a.addGame(newGame);
        }
        catch(const FullShelfException& e){
          cout << e.what() << endl << endl;
        }
        break;

      case 2:
        try{
          // cout << "Which game would you like to delete from 1 to 10?" << endl;
          // cin >> input;
          // cout << endl;
          a.removeGame().print();
          cout << "\nCurrent games on the board: " << a.length() << endl << endl;
        }catch (const EmptyShelfException& e){
          cout << e.what() << endl << endl;
        }    
        break;

      case 3:
        display = a.display();
        cout << endl;
        display.print();
        cout << "\nCurrent games on the board: " << a.length() << endl << endl;
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