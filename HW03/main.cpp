#include <iostream>
#include <random>
#include "Side.h"
#include "Card.h"
#include "Deck.h"
using namespace std;

// prototype functions
void playCard(Deck<Card>&, Deck<Card>&, Card&);  //function prototype for playing a card


// both deck declarations are for player and computer
// card declaration is for whether there's a card from pile or not
// program execution
int main() {

	// initiallize the those class variables
  Deck<Card> computer;  //Creates an empty deck of cards for player and computer
  Deck<Card> player; 
  Side<Card> pile;  //Creates an empty side class called pile for player
  

  int uchoice = 0;  //variable to determine intro choice
  int pilechoice = -1;  //variable to determine choice when it comes to switch case 2
  int contchoice = 0;  //variable to check if program will run again
  
  bool ivalid = false;  //Intro valid
  bool pvalid = false;  //Pile choice valid
  
  Card blank;  //declaration of cards. Blank is an empty card used in playCard if it's a normal play
  Card viewer;  //used for case 2 when viewing top of deck
  Card pcard;  //used for taking off the top of pile

  cout << "/////////////////" << endl;
  cout << "/Welcome to War!/" << endl;
  cout << "/////////////////" << endl << endl << endl;

  //Test Case 1:
  
  // Card c1(6, 's');
  // Card c2(9, 's');
  // Card c3(13, 'd');
  // Card c4(2, 'c');
  // Card c5(4, 'c');

  // Card p1(10, 'h');
  // Card p2(4, 'h');
  // Card p3(13, 'c');
  // Card p4(3, 'd');
  // Card p5(2, 's');

  //End Test Case 1

  //Test Case 2:
  
  Card c1(6, 's');
  Card c2(8, 's');
  Card c3(10, 'd');
  Card c4(11, 'c');
  Card c5(12, 'c');

  Card p1(7, 'h');
  Card p2(9, 'h');
  Card p3(11, 'c');
  Card p4(12, 'd');
  Card p5(13, 's');

  //End Test Case 2

  //Put Test Case 3 here:
	/*
	Card c1(12, 's');
	Card c2(9, 'd');
	Card c3(21, 's');
	Card c4(7, 'd');
	Card c5(2, 'c');

	Card p1(10, 'd');
	Card p2(6, 's');
	Card p3(15, 'c');
	Card p4(3, 'h');
	Card p5(7, 'd');
	*/
  //End Test Case 3

	// input all the data
  computer.insert(c1);
  computer.insert(c2);
  computer.insert(c3);
  computer.insert(c4);
  computer.insert(c5);

  player.insert(p1);
  player.insert(p2);
  player.insert(p3);
  player.insert(p4);
  player.insert(p5);

	// main execution loop
  while ((player.size() != 0 || pile.getlength() != 0) && computer.size() != 0){
    if (player.size() == 0){
      cout << "Taking from pile." << endl;
      player.insert(pile.pop());
      cout << "You have " << pile.getlength() << " Cards in your pile and one in your deck" << endl;
    }

		// print out the list of action for user
    while (!ivalid){
      cout << "How to Play: " << endl;
      cout << "(1) Play from the top of your deck" << endl;
      cout << "(2) Peek Top of Deck" << endl;
      cout << "(3) View the current number of cards in deck" << endl;
      cout << "(4) View the current number of cards in opponent's deck" << endl;
      cout << "(5) View the current number of cards in the side pile" << endl;
			cout << "(6) Exit the game" << endl;
      cout << "Which option will you choose? ";
      cin >> uchoice;
      cout << endl << endl;;

			// check valid input to prevent running into infinite loop with different input rather than int
      if (!cin) {
        uchoice = 0;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n' );
      }
			
      switch(uchoice){
        case 1: // play from the deck
          playCard(computer, player, blank);            
          ivalid = true;
          break;
        case 2: // view top of deck
          viewer = player.remove();
          while (!pvalid){
            cout << "Top of your Deck: [" << viewer.value << viewer.suit << "]" << endl;
            cout << "Would you like to add it to your pile(0), or play this card along with top of your pile(1)? ";
            
            cin >> pilechoice;
						
						// check valid with different input rather than int
			      if (!cin) {
			        cin.clear();
			        cin.ignore(numeric_limits<streamsize>::max(), '\n' );
							cout << endl;
							cout << "Need to be an integer!" << endl;
							cout << "/////////////////////////////////" << endl << endl;           

						}else{ // print out error if invalid input or pile empty
							if (pilechoice == 0){
	              pile.push(viewer);
	              playCard(computer, player, blank);
	              pvalid = true;
	            }
	            else if(pilechoice == 1 && pile.getlength() != 0){ // pine is empty
	              pcard = pile.pop();
	              playCard(computer, player, pcard);
	              pvalid = true;
	            } else {
								cout << endl;
								cout << "Your input is invalid or The pile is currently empty!" << endl;
								cout << "/////////////////////////////////" << endl << endl;
							}
						}
            cout << endl;
          }
          pilechoice = -1;
          pvalid = false;
          ivalid = true;
          break;
        case 3: // out current number of cards in deck
					cout << "The current number of cards in deck: " << player.size() << endl;
          ivalid = true;
          cout << "/////////////////////////////////" << endl << endl;
          break;
        case 4: // show number of cards in opponent deck
          cout << "The current number of cards in opponent's deck: " << computer.size() << endl << endl;
          ivalid = true;
          cout << "/////////////////////////////////" << endl << endl;
          break;
        case 5: // view the number of cards in the pile
          cout << "The current number of cards in the side pile: " << pile.getlength() << endl << endl;
          cout << "/////////////////////////////////" << endl << endl;
          ivalid = true;
          break;
				case 6: // exit the program
					cout << "Bye Bye :-)" << endl;
					return 0;
        default:
          cout << "Invalid input, please try again!" << endl;
          cout << "/////////////////////////////////" << endl << endl;
          break;
      }
    }
    ivalid = false;
    uchoice = 0;
  }

	// print out the result
  if (player.size() == 0){
    cout << "Computer Wins! You played a good game but it seems fate was not on your side, try again?" << endl;
  }
  else{
    cout << "Player Wins! Great job on outwinning the computer, but do you care to prove it wasn't a fluke and try again?" << endl;
  }
  
  return 0;
  
  
}

// take the card and generate the game between player and computer
void playCard(Deck<Card> &comp, Deck<Card> &play, Card &alt){
  Card ptemp;
  Card ctemp;
  
  ctemp = comp.remove();
  ptemp = play.remove();
  cout << "Player Plays: [" << ptemp.value << ptemp.suit << "]" << endl;
  if (alt.value != 0){
    cout << "Player Plays from Pile: [" << alt.value << alt.suit << "]" << endl;
  }
  cout << "Computer Plays: [" << ctemp.value << ctemp.suit << "]" << endl;
  if (ctemp.value >= (ptemp.value + alt.value)){
    cout << "Computer wins the hand" << endl;
    comp.insert(ptemp);
    comp.insert(ctemp);
    if (alt.value != 0){
      comp.insert(alt);
    }
  }
  else{
    cout << "Player wins the hand" << endl;
    cout << "/////////////////////////////////" << endl << endl;
    play.insert(ptemp);
    play.insert(ctemp);
    if (alt.value != 0){
      play.insert(alt);
    }
  }
}