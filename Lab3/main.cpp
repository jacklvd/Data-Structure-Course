#include <iostream>
#include <random>
#include "Complex.h"
using namespace std;

/*

This program is writing to overload the math basic operation and apply them to calculate the complex number.

*/


// the list of operations for user
void list()
{ 
  cout << "--------------------------------------------------------------" << endl;
  cout << endl;
  cout << "List of operations: " << endl;
  cout << "1. Addition" << endl;
  cout << "2. Substraction" << endl;
  cout << "3. Multiplication" << endl;
  cout << "4. Division" << endl;
  cout << "5. Equivalent" << endl;
  cout << "6. Display" << endl << endl;
  cout << "Which operation would you like to do?" << endl;
}

//this is where the whole program execute
int main() {

  // declare all needed variables
  double x, y;
  bool runagain = true;
  bool validinput = false;
  int iinput;
  double dinput;

  cout << "Welcome to the Complex Number Program!" << endl;
  cout << "This program will do basic complex numbers operation." << endl << endl;

  // take first complex number
  cout << "Please enter the x and y values for the complex number respectively:" << endl;
  cin >> x >> y;
  Complex tester1(x, y);
  Complex tester2(x, y);
  
  while (runagain) {

    validinput = false;
    list();
    cout << "Your choice: ";
    cin >> iinput;
    cout << endl;

    // check if the player enter invalid input, even if they entered input as non-integer
    // references: https://stackoverflow.com/questions/16698670/switch-statement-inside-a-while-loop-which-loop-infinitely      
    if (!cin) {
        iinput = 0;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n' );
    }

    switch (iinput) {
      case 1: // addition operation
        cout << "Please enter the x and y values for the other complex number respectively:" << endl;
        cout << "You entered: ";
        cin >> x >> y;
        cout << endl;
        tester2.setA(x);
        tester2.setB(y);
        tester1 + tester2;
        cout << "Result: ";
        tester1.display();
        break;

      case 2: // subtraction operation
        cout << "Please enter the x and y values for the other complex number respectively:" << endl;
        cout << "You entered: ";
        cin >> x >> y;
        cout << endl;        
        tester2.setA(x);
        tester2.setB(y);        
        tester1 - tester2;
        cout << "Result: ";
        tester1.display();
        break;

      case 3: // multiplication operation
        cout << "Please Enter the number you want to multiply by: \n";
        cout << "You entered: ";
        cin >> dinput;
        cout << endl;
        tester1 * dinput;
        cout << "Result: ";
        tester1.display();
        break;

      case 4: // division operation
        cout << "Please Enter the number you want to divide by: \n";
        cout << "You entered: ";
        cin >> dinput;
        cout << endl;
        tester1 / dinput;
        cout << "Result: ";
        tester1.display();
        break;

      case 5: // equivalent
        cout << "Please enter the x and y values for the other complex number respectively:" << endl;
        cout << "You entered: ";
        cin >> x >> y;
        cout << endl;
        tester2.setA(x);
        tester2.setB(y);   
        if (tester1 == tester2){
          cout << "Result: Equivalent." << endl << endl;
        }else {
          cout << "Result: Non-equivalent." << endl <<endl;
        }
        break;

      case 6: // display
        cout << "Result: ";
        tester1.display();
        break;
      default:
        cout << "Invalid Input!" << endl << endl;
        break;
    }

    // ask the user if they attempt to make another operation
    while (validinput == false){

      cout << "Would you like to run again? No(0), Yes(1)" << endl;
      cout << "Your choice: ";
      cin >> iinput;

      if (iinput == 0){
        cout << endl;
        cout << "Program end!" << endl;
        runagain = false;
        validinput = true;
      } else if(iinput == 1) {
        runagain = true;
        validinput = true;
      } else {
        cout << "Invalid input, please try again" << endl << endl;
      }     
    }
  }

  return 0;
}