#include <iomanip>
#include <iostream>
#include <cstring>
#include <random>
#include <math.h>
#include <list>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <set>
using namespace std;

///////////////////////////////////////////////////////////////////////
const int NUMBER_PLAYERS = 5; // constant value for size of a team

///////////Main Class//////////////////////////////////////////////////
class BBPlayer {
  private:
    string name;
    int shotsTaken;
    int shotsMade;
    int passesAttempted;
    int passesMade;
    int shotpercent;
    int passpercent;
  public:
    BBPlayer();
    BBPlayer(string, int, int, int, int, int, int);
    bool PassBall();
    int TakeShot(int, int);
    void setName(string uname) { name = uname; };
    void setTaken(int utaken) { shotsTaken = utaken; };
    void setShotsMade(int usmade) { shotsMade = usmade; };
    void setAttempted(int uattempt) { passesAttempted = uattempt; };
    void setPassesMade(int upmade) { passesMade = upmade; };
    void setShotPercent(int percent){shotpercent = percent;};
    void setPassPercent(int percent){passpercent = percent;};
    string getName() { return name; };
    int getTaken() { return shotsTaken; };
    int getSMade() { return shotsMade; };
    int getAttempted() { return passesAttempted; };
    int getPMade() { return passesMade; };
    int getShotPercent(){return shotpercent;};
    int getPassPercent(){return passpercent;};
    int successPercent(int );
    void display();
    ~BBPlayer() { name = " "; shotsTaken = 0; shotsMade = 0; passesAttempted = 0; passesMade = 0; };
};

///////////////////////////////////////////////////////////////////////
BBPlayer::BBPlayer() { // default constructors
	name = " ";
	shotsTaken = 0;
	shotsMade = 0;
	passesAttempted = 0;
	passesMade = 0;
  shotpercent = shotpercent = rand() % 30 + 50;
  passpercent = passpercent = rand() % 30 + 65; 
};

///////////////////////////////////////////////////////////////////////
BBPlayer::BBPlayer(string uname, int uTaken, int uSMade, int uAttempted, int uPMade, int spercent, int ppercent) { // initialize variables
  name = uname;
  shotsTaken = uTaken;
  shotsMade = uSMade;
  passesAttempted = uAttempted;
  passesMade = uPMade;
  shotpercent = spercent;
  passpercent = ppercent;
};

///////////////////////////////////////////////////////////////////////
bool BBPlayer::PassBall() { //pass ball function
  int i = rand() % 100 + 1;
  double PassPct;
  PassPct = successPercent(0);

  // base on the successPercent to determind whether users are able to make a pass
  if (i > PassPct){ // pass fail
    ++passesAttempted;
    successPercent(0);
    return false;
  }
  else { // if pass success increment the passAttempted and call successPercent
    ++passesAttempted;
    ++passesMade;
    successPercent(0);
    return true;
  }   
}

///////////////////////////////////////////////////////////////////////
int BBPlayer::TakeShot(int score, int mode) { //Mode is for rebound
  double shootPct;
  //random calculate the shot percentage/accuracy for different point modes
  int onePoint = rand() % 80 + 1;
  int twoPoint = rand() % 100 + 1;
  int threePoint = rand() % 120 + 1;
  if (mode == 1){
    shotpercent = 60;
  }
  //take the score and determind if the player is able to make the shot
  //base on the successPercent.
  if (score == 1){
    if (onePoint < shotpercent){
      cout << "Player " << name << " scores one point." << endl << endl;
      ++shotsTaken;
      ++shotsMade;
      if (mode != 1){
          shootPct = successPercent(1);
      } 
      return 1;
    }
    else {
      ++shotsTaken;
      return 0;
    }
  }
  else if (score == 2){
    if (twoPoint < shotpercent){
      cout << "Player " << name << " scores two points." << endl << endl;
      ++shotsTaken;
      ++shotsMade;
      if (mode != 1){
        shootPct = successPercent(1);
      } 
      return 2;
    }
    else {
      ++shotsTaken;
      return 0;
    }
  }
  else if (score == 3){
    if (threePoint < shotpercent){
      cout << "Player " << name << " scores three points." << endl << endl;
      ++shotsTaken;
      ++shotsMade;
      if (mode != 1){
      shootPct = successPercent(1);
    } 
    return 3;
    }
    else {
      ++shotsTaken;
      if (mode != 1){
        shootPct = successPercent(1);
      } 
      return 0;
    }
  }
}

///////////////////////////////////////////////////////////////////////
int BBPlayer::successPercent(int mode){ // mode is for pass, shot, and rebound

  if (mode == 0){ // Mode 0 is pass
    //percent = (passesMade / passesAttempted) * 100;
    passpercent += 1;
    passpercent -= (passesAttempted - passesMade) * 2;
    return passpercent;
  }
  else if (mode == 1){  // Mode 1 is Shot
    shotpercent += 1;
    shotpercent -= (shotsTaken - shotsMade) * 2;
    //percent = (shotsMade / shotsTaken) * 100;
    return shotpercent;
  }
  else if (mode == 2){  // Mode 2 is Rebound
    shotpercent = 60;
    return shotpercent;
  }
  else {
    cout << "Error" << endl;
  }
}

///////////////////////////////////////////////////////////////////////
void BBPlayer::display() // display the statistic of the game
{
  cout << "Player: " << name << endl;
  cout << "Shots taken: " << shotsTaken << endl;
  cout << "Shots made: " << shotsMade << endl;
  cout << "Shot Percentage: " << shotpercent << endl;
  cout << "Passes attempted: " << passesAttempted << endl;
  cout << "Passes made: " << passesMade << endl;
  cout << "Pass Percentage: " << passpercent << endl << endl;
}

///////////////////////////////////////////////////////////////////////
void intro() // display list of action for the game
{
  cout << endl;
  cout << "Here is the list of actions for the basketball game:" << endl;
  cout << "1. Take shot" << endl;
  cout << "2. Pass" << endl;
  cout << "3. See players stats" << endl;
  cout << "4. See score" << endl << endl;
}

///////////////////////////////////////////////////////////////////////
int main() 
{
  // display all necessary variables
  BBPlayer team1[NUMBER_PLAYERS];
  BBPlayer enemy;
  enemy.setName("of The Opposing Team");
  string sinput;    // user string input (the user name)
  bool haspos = 1;  // haspossession
  int iinput;       // user integer input
  int enemyscore = 0;
  int score = 0;
  int possessions = 20; // the game will end when possession reaches 0
  int reboundchance = 0;
  int shotval;
  srand(time(NULL));

  // main execution of the program
  cout << "Welcome to the basketball game!" << endl << endl;
  
  set<string> nameSet;
  
  for (int i = 0; i < NUMBER_PLAYERS; i++) {
    cout << "Please enter the name for player " << i + 1 << ":" << endl;
    cin >> sinput;
    // check if user enter a same/exist name and force to re-enter new input
    transform(sinput.begin(), sinput.end(), sinput.begin(), ::toupper);
    while (nameSet.find(sinput) != nameSet.end()) {
      cout << "Existing name, please enter a new name for the player " << i + 1 << ":" << endl;
      cin >> sinput;
      transform(sinput.begin(), sinput.end(), sinput.begin(), ::toupper);
    }
    team1[i].setName(sinput);
    nameSet.insert(sinput);
  }
  cout << endl;
  
  srand (time(NULL));
  int currPlayer = rand() % 5;

  while (possessions != 0){ // control the game float

    while(haspos == 1){ // to control each player turn
      cout << "--------------------------------------------------------------" << endl; 
      cout << "You are player " << team1[currPlayer].getName() << endl;
      reboundchance = rand() % 2;
      intro();
      cout << "Your choice: ";
      cin >> iinput;
      cout << endl;
      cout << "--------------------------------------------------------------" << endl;

      // check if the player enter invalid input, even if they entered input as non-integer
      // references: https://stackoverflow.com/questions/16698670/switch-statement-inside-a-while-loop-which-loop-infinitely
      if ( !std::cin ) {
        iinput = 0;
        std::cin.clear();
        std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
      }

      switch(iinput){
        case 1: // shot action as well as determind whether player have rebound or not
          cout << "How many points would you like to make? (1, 2, 3)" << endl;
          cin >> iinput;
          cout << endl;
          switch(iinput) {
            case 1:
              if (team1[currPlayer].TakeShot(iinput, 0) == 1){
                score += 1;
              }
              else{
                if (reboundchance == 0){  //0 = fail
                  cout << "Shot Missed, and rebound failed. The opposing team now has the ball." << endl << endl;
                  haspos = 0;
                }
                else {
                  cout << "Shot missed. The ball rebounds back to you."<< endl;
                }
              }
              break;
            case 2:
              if (team1[currPlayer].TakeShot(iinput, 0) == 2){
                score += 2;
              }
              else {
                if (reboundchance == 0){  //0 = fail
                  cout << "Shot Missed, and rebound failed. The opposing team now has the ball."<< endl << endl;
                  haspos = 0;
                }
                else{
                  cout << "Shot missed. The ball rebounds back to you."<< endl;
                }
              }              
              break;
            case 3:
              if (team1[currPlayer].TakeShot(iinput, 0) == 3){
                score += 3;
              }
              else {
                if (reboundchance == 0){  //0 = fail
                  cout << "Shot Missed, and rebound failed. The opposing team now has the ball."<< endl << endl;
                  haspos = 0;
                }
                else{
                  cout << "Shot missed. The ball rebounds back to you."<< endl;
                }
              }
              break;
          }
          break;
        case 2: // pass ball action
          if (team1[currPlayer].PassBall() == true){
            cout << "Which player do you want to have the ball?" << endl;
            cin >> sinput;
            transform(sinput.begin(), sinput.end(), sinput.begin(), ::toupper);
            cout << endl;

            for (int i = 0; i < NUMBER_PLAYERS; i++){
              if (sinput == team1[currPlayer].getName()) {
                cout << "You cannot pass to yourself!" << endl << endl;
                break;
              }
              else if (sinput == team1[i].getName()) {
                currPlayer = i;
                break;
                //test to see if pass succeeds
                //if pass succeeds currPlayer = 1;
              }
              else if ((i == 4) && (sinput != team1[i].getName())) {
                cout << "Invalid Input. Please Try Again." << endl << endl;
                break;
              }
            }
          }
          else {
            cout << "Pass Failed, Opposing Team now has the ball." << endl << endl;
            haspos = 0;
          }
          //enter code for passing
          break;
        case 3: // display the statistic of each player
          for (int i = 0; i < NUMBER_PLAYERS; i++) {
            team1[i].display();
          }
          break;
        case 4: // the current team score/enemy score and the possessions left
          cout << "Your Team's score: " << score << endl;
          cout << "Opposing Team's score: " << enemyscore << endl;
          cout << "Current possessions: " << possessions << endl << endl;
          break;
        default:
          cout << "Invalid Input!" << endl << endl;
          break;
      }
    }
    possessions--;

    //enter enemy's code here
    while (haspos == 0){
      shotval = rand() % 3 + 1;
      reboundchance = rand() % 2;
      cout << "Taking Shot" << endl << endl;
      if (enemy.TakeShot(shotval, 1) == shotval){
        enemyscore += shotval;
      } else {
        if (reboundchance == 0){
          haspos = 1;
          cout << "Shot missed. Rebound failed. Your team now has the ball." << endl << endl;
        } else {
          cout << "Shot missed. Rebounded." << endl << endl;
        }
      }
    }
    cout << "The Opposing Team's Score is: " << enemyscore << endl << endl;
  }
  cout << endl;
  cout << "--------------------------------------------------------------" << endl;
  cout << "The Game Ends" << endl << endl;
  cout << "Your team score is " << score << endl;
  cout << "The Opposing Team's score is " << enemyscore << endl << endl;

  // display result of the game by comparing each team's score
  if (score > enemyscore) {
    cout << "Your team wins.";
  } else if (score == enemyscore) {
    cout << "The match ends as a DRAW.";
  } else {
    cout << "The winner is the Opposing Team.";
  }  
}

/* Program Output

Welcome to the basketball game!

Please enter the name for player 1:
Long
Please enter the name for player 2:
Long
Existing name, please enter a new name for the player 2:
Jenn
Please enter the name for player 3:
Nick
Please enter the name for player 4:
Haru
Please enter the name for player 5:
Huber

--------------------------------------------------------------
You are player LONG

Here is the list of actions for the basketball game:
1. Take shot
2. Pass
3. See players stats
4. See score

Your choice: kfs

--------------------------------------------------------------
Invalid Input!

--------------------------------------------------------------
You are player LONG

Here is the list of actions for the basketball game:
1. Take shot
2. Pass
3. See players stats
4. See score

Your choice: 5

--------------------------------------------------------------
Invalid Input!

--------------------------------------------------------------
You are player LONG

Here is the list of actions for the basketball game:
1. Take shot
2. Pass
3. See players stats
4. See score

Your choice: 1

--------------------------------------------------------------
How many points would you like to make? (1, 2, 3)
2

Player LONG scores two points.

--------------------------------------------------------------
You are player LONG

Here is the list of actions for the basketball game:
1. Take shot
2. Pass
3. See players stats
4. See score

Your choice: 2

--------------------------------------------------------------
Which player do you want to have the ball?
Haru

--------------------------------------------------------------
You are player HARU

Here is the list of actions for the basketball game:
1. Take shot
2. Pass
3. See players stats
4. See score

Your choice: 1

--------------------------------------------------------------
How many points would you like to make? (1, 2, 3)
3

Player HARU scores three points.

--------------------------------------------------------------
You are player HARU

Here is the list of actions for the basketball game:
1. Take shot
2. Pass
3. See players stats
4. See score

Your choice: 3

--------------------------------------------------------------
Player: LONG
Shots taken: 1
Shots made: 1
Shot Percentage: 62
Passes attempted: 1
Passes made: 1
Pass Percentage: 84

Player: JENN
Shots taken: 0
Shots made: 0
Shot Percentage: 54
Passes attempted: 0
Passes made: 0
Pass Percentage: 75

Player: NICK
Shots taken: 0
Shots made: 0
Shot Percentage: 79
Passes attempted: 0
Passes made: 0
Pass Percentage: 69

Player: HARU
Shots taken: 1
Shots made: 1
Shot Percentage: 69
Passes attempted: 0
Passes made: 0
Pass Percentage: 83

Player: HUBER
Shots taken: 0
Shots made: 0
Shot Percentage: 72
Passes attempted: 0
Passes made: 0
Pass Percentage: 79

--------------------------------------------------------------
You are player HARU

Here is the list of actions for the basketball game:
1. Take shot
2. Pass
3. See players stats
4. See score

Your choice: 4

--------------------------------------------------------------
Your Team's score: 5
Opposing Team's score: 0
Current possessions: 3

--------------------------------------------------------------
You are player HARU

Here is the list of actions for the basketball game:
1. Take shot
2. Pass
3. See players stats
4. See score

Your choice: 1

--------------------------------------------------------------
How many points would you like to make? (1, 2, 3)
3

Shot Missed, and rebound failed. The opposing team now has the ball.

Taking Shot

Shot missed. Rebound failed. Your team now has the ball.

The Opposing Team's Score is: 0

--------------------------------------------------------------
You are player HARU

Here is the list of actions for the basketball game:
1. Take shot
2. Pass
3. See players stats
4. See score

Your choice: 2

--------------------------------------------------------------
Which player do you want to have the ball?
Nick

--------------------------------------------------------------
You are player NICK

Here is the list of actions for the basketball game:
1. Take shot
2. Pass
3. See players stats
4. See score

Your choice: 2

--------------------------------------------------------------
Which player do you want to have the ball?
kfs

Invalid Input. Please Try Again.

--------------------------------------------------------------
You are player NICK

Here is the list of actions for the basketball game:
1. Take shot
2. Pass
3. See players stats
4. See score

Your choice: 2

--------------------------------------------------------------
Pass Failed, Opposing Team now has the ball.

Taking Shot

Player of The Opposing Team scores one point.

Taking Shot

Shot missed. Rebounded.

Taking Shot

Player of The Opposing Team scores one point.

Taking Shot

Player of The Opposing Team scores one point.

Taking Shot

Player of The Opposing Team scores one point.

Taking Shot

Player of The Opposing Team scores three points.

Taking Shot

Shot missed. Rebound failed. Your team now has the ball.

The Opposing Team's Score is: 7

--------------------------------------------------------------
You are player NICK

Here is the list of actions for the basketball game:
1. Take shot
2. Pass
3. See players stats
4. See score

Your choice: 2

--------------------------------------------------------------
Pass Failed, Opposing Team now has the ball.

Taking Shot

Player of The Opposing Team scores one point.

Taking Shot

Shot missed. Rebound failed. Your team now has the ball.

The Opposing Team's Score is: 8


--------------------------------------------------------------
The Game Ends

Your team score is 5
The Opposing Team's score is 8

The winner is the Opposing Team.
*/