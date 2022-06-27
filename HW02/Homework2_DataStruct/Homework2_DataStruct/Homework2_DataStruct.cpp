// Homework2_DataStruct:
// Jack Vo, Nicholas Krouse, Haru Chu
//

#include <math.h>
#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Wheel.h"
#include "Player.h"
using namespace std;

// prototype functions
int takeNum();
void instruction();
void play();
bool exit();

// terminate the program
int main() {

    play();

    return 0;
}

// print out the betting chance instruction
void instruction() {

    cout << "*****************************************" << endl << endl;
    cout << "Please choose modes for your betting chance:" << endl;
    cout << "(1) Double (2) Halve (3) None" << endl;
}

// ask if the player want to continue playing the game or leave
bool exit() {

    string ans;

    cout << "Do you wanna cast out?" << endl;
    cout << "yes(y) - no(n) -> ";
    cin >> ans;
    cout << endl;

    if (ans.compare("yes") == 0 || ans.compare("y") == 0) {
        cout << endl;
        cout << "\t\t=====See Yah!<3=====" << endl;
        return false;
    }
    return true;
}

/*
* ********************************************************************************* *
* Take the number for add to the spinning wheel                                     *
*                                                                                   *
* Check if number fit the condition >=6 and <= 20                                   *
* return int                                                                        *
* ********************************************************************************* *
*/
int takeNum() {

    int num;
    while (true) {
        cout << "Please enter a number from 6 to 20 for the values on the wheel: ";
        cin >> num;
        cout << endl;
        if (num >=6 && num <= 20) {
            break;
        }
        else {
            cout << "Invalid Input!" << endl;
        }
    }
    return num;
}

/*
* ********************************************************************************* *
* Main execution, calling out for instruction(), takeNum(), exit()                  *
* Ask the user for hard or normal game                                              *
*                                                                                   *
* Take user input, execute with switch for 3 modes of the game: none, halve, double *
* return void                                                                       *    
* ********************************************************************************* *
*/
void play() {

    // initialize all variables
    int houseWin = 0;
    bool pResult = false;
    int bet;
    int num;
    int balance;
    string ans;
    string mode;
    bool process = true;
    srand(time(NULL));

    // start of main program
    cout << "\t\t====== Welcome to Roullete Wheel Game ======" << endl << endl;

    // ask user to choose betweem normal and hard game mode
    cout << "Do you want to play the hard mode? yes(y) - no(n)" << endl;
    cout << "Your choice: ";
    cin >> mode;
    num = takeNum();

    // initialize the value appear on the wheel when spin
    Wheel house(1, num);
    Wheel player(1, num);

    // take the balance of player
    cout << "Please enter your total balance: ";
    cin >> balance;

    // initialize the balance
    Player person(balance);

    // main execute while-loop
    while (process) {

        // if user run out of cast, terminate the program
        if (person.getBalance() <= 0) {
            cout << "Sorry, you have run out of juice!" << endl;
            process = false;
        }
        else { // play the game normal
            cout << "Please enter your bet amount: ";
            cin >> bet;
            cout << endl;

            // prompt error if the bet is higher than the current balance
            if (bet > person.getBalance()) {
                cout << "You don't have that much of money :(" << endl << endl;
                cout << endl;
            }
            else {
                // print out list of action and take user choice of input
                instruction();
                cout << "Your input: ";
                cin >> num;
                cout << endl;
                // prevent running into infinite-loop when getting an invalid input of num
                if (!cin) {
                    num = 0;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                // if mode == no -> run normal game type
                if (mode == "no" || mode == "n") {
                    switch (num) {

                    case 1: // double betting chance
                        player.spin();
                        cout << "Player generated number: " << player.getBall() << endl;
                        house.spin();
                        cout << "Computer generated number: " << house.getBall() << endl;
                        // if user win the 1st round, spin again for 2nd round
                        if (player.getBall() > house.getBall()) {
                            house.spin();
                            // if player also win 2nd round, double their bet and update their balance
                            if (player.getBall() > house.getBall()) {
                                cout << "Computer generated number: " << house.getBall() << endl << endl;
                                cout << "-------------Loading-Result-------------" << endl << endl;
                                cout << "You win!" << endl;
                                cout << "Your balance was raised by " << bet * 2 << endl;
                                balance = person.getBalance() + bet * 2;
                                cout << "Total current balance: " << balance << endl << endl;
                            }
                            // if player lose 2nd round, decrease their balance by doubling of their bet amount
                            else {
                                cout << "Computer generated number: " << house.getBall() << endl << endl;
                                cout << "-------------Loading-Result-------------" << endl << endl;
                                cout << "You lose!" << endl;
                                cout << "Your balance was decresed by " << bet * 2 << endl;
                                balance = person.getBalance() - bet * 2;
                                cout << "Total current balance: " << balance << endl << endl;
                            }
                        }
                        // if player lose first round, they go straight to lose and lost their money equal to double of their bet amount
                        else {
                            cout << "-------------Loading-Result-------------" << endl << endl;
                            cout << "\nYou lose!" << endl;
                            cout << "Your balance was decresed by " << bet * 2 << endl;
                            balance = person.getBalance() - bet * 2;
                            cout << "Total current balance: " << balance << endl << endl;
                        }
                        // update the current balance
                        person.setBalance(balance);
                        break;
                    case 2: // halve betting chance
                        player.spin();
                        cout << "Player generated number: " << player.getBall() << endl;
                        house.spin();
                        cout << "Computer generated number: " << house.getBall() << endl;
                        // if the player win the first round, their balance increase by half of their bet
                        if (player.getBall() > house.getBall()) {
                            house.spin();
                            cout << "Computer generated number: " << house.getBall() << endl << endl;
                            // if the player win the second round, their balance increase by full of their bet
                            if (player.getBall() > house.getBall()) {
                                cout << "-------------Loading-Result-------------" << endl << endl;
                                cout << "You win!" << endl;
                                cout << "Your balance was raised by " << bet << endl;
                                balance = person.getBalance() + bet;
                                cout << "Total current balance: " << balance << endl << endl;
                            }
                            // if house win the second round, their balance remain unchange
                            else {
                                cout << "-------------Loading-Result-------------" << endl << endl;
                                cout << "It's a draw!" << endl;
                                cout << "Your balance remains unchanged." << endl;
                                cout << "Total current balance: " << balance << endl << endl;
                            }
                        }
                        else { // if house win the second round, their balance remain unchange
                            house.spin();
                            cout << "Computer generated number: " << house.getBall() << endl << endl;
                            if (player.getBall() > house.getBall()) {
                                cout << "-------------Loading-Result-------------" << endl << endl;
                                cout << "It's a draw!" << endl;
                                cout << "Your balance remains unchanged." << endl;
                                cout << "Total current balance: " << balance << endl << endl;
                            } // if player lose both rounds, their balance decrease by their full bet amount
                            else {
                                cout << "-------------Loading-Result-------------" << endl << endl;
                                cout << "You lose!" << endl;
                                cout << "Your balance was decresed by " << bet << endl;
                                balance = person.getBalance() - bet;
                                cout << "Total current balance: " << balance << endl << endl;
                            }
                        }
                        // update the current balance
                        person.setBalance(balance);
                        break;

                    case 3: // None betting percentage
                        // start generating random number
                        house.spin();
                        player.spin();
                        cout << "Player generated number: " << player.getBall() << endl;
                        cout << "Computer generated number: " << house.getBall() << endl << endl;
                        cout << "-------------Loading-Result-------------" << endl << endl;

                        // if the player ball is higher than house ball, the player win
                        if (player.getBall() > house.getBall()) {
                            cout << "You win!" << endl;
                            cout << "Your balance was raised by " << bet << endl;
                            balance = person.getBalance() + bet;
                            cout << "Total current balance: " << balance << endl << endl;
                        }
                        else {
                            cout << "You lose!" << endl;
                            cout << "Your balance was decresed by " << bet << endl;
                            balance = person.getBalance() - bet;
                            cout << "Total current balance: " << balance << endl << endl;
                        }
                        // update current balance
                        person.setBalance(balance);
                        break;
                    default:
                        cout << "Invalid Input." << endl << endl;
                        break;
                    }
                }
                else {
                    /*
                    * ************************************************************************ *
                    * Hard Mode Game                                                           *
                    * Have the same betting chance with the normal game                        *
                    *                                                                          *
                    * However, the house range of wheel will increase every time if they lose  *
                    * While decrease the range if the house win in 2 straight row              *
                    * ************************************************************************ *
                    */
                    cout << "Hard Mode On" << endl;
                    switch (num) {

                    case 1: // double chance
                        player.spin();
                        cout << "Player generated number: " << player.getBall() << endl;
                        house.spin(pResult, houseWin, 1);
                        cout << "Computer generated number: " << house.getHouseBall() << endl;
                        if (player.getBall() > house.getHouseBall()) {

                            house.spin(pResult, houseWin, 2);
                            if (player.getBall() > house.getHouseBall()) {
                                cout << "Computer generated number: " << house.getHouseBall() << endl << endl;
                                cout << "-------------Loading-Result-------------" << endl << endl;
                                cout << "You win!" << endl;
                                cout << "Your balance was raised by " << bet * 2 << endl;
                                balance = person.getBalance() + bet * 2;
                                cout << "Total current balance: " << balance << endl << endl;
                                pResult = true;
                                houseWin = 0;
                            }
                            else {
                                cout << "Computer generated number: " << house.getHouseBall() << endl << endl;
                                cout << "-------------Loading-Result-------------" << endl << endl;
                                cout << "You lose!" << endl;
                                cout << "Your balance was decreased by " << bet * 2 << endl;
                                balance = person.getBalance() - bet * 2;
                                cout << "Total current balance: " << balance << endl << endl;
                                pResult = false;
                                houseWin += 1;
                            }
                        }
                        else { 
                            cout << "-------------Loading-Result-------------" << endl << endl;
                            cout << "\nYou lose!" << endl;
                            cout << "Your balance was decresed by " << bet * 2 << endl;
                            balance = person.getBalance() - bet * 2;
                            cout << "Total current balance: " << balance << endl << endl;
                            pResult = false;
                            houseWin += 1;
                        }
                        person.setBalance(balance);
                        break;
                    case 2: // halve chance
                        player.spin();
                        cout << "Player generated number: " << player.getBall() << endl;
                        house.spin(pResult, houseWin, 1);
                        cout << "Computer generated number: " << house.getHouseBall() << endl;
                        if (player.getBall() > house.getHouseBall()) {

                            house.spin(pResult, houseWin, 2);
                            cout << "Computer generated number: " << house.getHouseBall() << endl << endl;
                            if (player.getBall() > house.getHouseBall()) {
                                cout << "-------------Loading-Result-------------" << endl << endl;
                                cout << "You win!" << endl;
                                cout << "Your balance was raised by " << bet << endl;
                                balance = person.getBalance() + bet;
                                cout << "Total current balance: " << balance << endl << endl;
                                pResult = true;
                                houseWin = 0;
                            }
                            else {
                                cout << "-------------Loading-Result-------------" << endl << endl;
                                cout << "It's a draw!" << endl;
                                cout << "Your balance remains unchanged." << endl;
                                cout << "Total current balance: " << balance << endl << endl;
                                pResult = false;
                                houseWin = 0;
                            }
                        }
                        else {
                            house.spin(pResult, houseWin, 2);
                            cout << "Computer generated number: " << house.getHouseBall() << endl << endl;
                            if (player.getBall() > house.getHouseBall()) {
                                cout << "-------------Loading-Result-------------" << endl << endl;
                                cout << "It's a draw!" << endl;
                                cout << "Your balance remains unchanged." << endl;
                                cout << "Total current balance: " << balance << endl << endl;
                                houseWin = 0;
                                pResult = false;
                            }
                            else {
                                cout << "-------------Loading-Result-------------" << endl << endl;
                                cout << "You lose!" << endl;
                                cout << "Your balance was decresed by " << bet << endl;
                                balance = person.getBalance() - bet;
                                cout << "Total current balance: " << balance << endl << endl;
                                pResult = false;
                                houseWin += 1;
                            }
                        }
                        person.setBalance(balance);
                        break;

                    case 3: // None betting percentage
                      // start generating random number
                        house.spin(pResult, houseWin, 1);
                        player.spin();
                        cout << "Player generated number: " << player.getBall() << endl;
                        cout << "Computer generated number: " << house.getHouseBall() << endl << endl;
                        cout << "-------------Loading-Result-------------" << endl << endl;

                        // condition for winning in case 3
                        if (player.getBall() > house.getHouseBall()) {
                            cout << "You win!" << endl;
                            cout << "Your balance was raised by " << bet << endl;
                            balance = person.getBalance() + bet;
                            cout << "Total current balance: " << balance << endl << endl;
                            pResult = true;
                            houseWin = 0;
                        }
                        else {
                            cout << "You lose!" << endl;
                            cout << "Your balance was decresed by " << bet << endl;
                            balance = person.getBalance() - bet;
                            cout << "Total current balance: " << balance << endl << endl;
                            pResult = false;
                            houseWin += 1;
                        }
                        // update current balance
                        person.setBalance(balance);
                        break;
                    default:
                        cout << "Invalid Input." << endl << endl;
                        break;
                    }
                }
                process = exit();
            }
        }
    }
}