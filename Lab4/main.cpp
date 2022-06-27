#include <iostream>
#include <cstring>
#include "TVshow.h"
#include "Movie.h"
#include "Show.h"
using namespace std;

// print out the list of action for user to input
void intructions() {

  cout << "--------------------------------------------------" << endl;
  cout << "List of action for running program" << endl;
  cout << "1. For an instance of Show." << endl;
  cout << "2. For an instance of Movie." << endl;
  cout << "3. For an instance of TV Show." << endl;
  cout << "4. For an instance of Movie declared as Show." << endl;
  cout << "5. For an instance of TV Show declared as Show." << endl;
  cout << "6. Exit" << endl << endl;
}


int main() {

  int iinput;
  string sinput;
  // case 1, 2, 3
  // Show
  Show show("Sword Art Online", "The year is 2022, and gamers have lined up on launch day for Sword Art Online, a hotly-anticipated MMORPG that lets players connect to an immersive virtual reality world with special helmets called Nerve Gear. Kirito is one such gamer who's eager to jump back into action, having spent a great deal of time as a beta tester, and quickly becomes friends with newbie warrior Klein. But soon, Sword Art Online's 10,000 players discover that not only are they unable to log out, the only way they can return to their physical bodies is by beating the 100-level tower's final boss - death in the game means death in the real world. Now, with no one else to turn to, Kirito and the other participants must survive the game as best they can.");
  // Movie
  Movie movie("Avatar", "When his brother is killed in a robbery, paraplegic Marine Jake Sully decides to take his place in a mission on the distant world of Pandora. There he learns of greedy corporate figurehead Parker Selfridge's intentions of driving off the native humanoid \"Navi\" in order to mine for the precious material scattered throughout their rich woodland. In exchange for the spinal surgery that will fix his legs, Jake gathers knowledge, of the Indigenous Race and their Culture, for the cooperating military unit spearheaded by gung-ho Colonel Quaritch, while simultaneously attempting to infiltrate the Na'vi people with the use of an \"avatar\" identity. While Jake begins to bond with the native tribe and quickly falls in love with the beautiful alien Neytiri, the restless Colonel moves forward with his ruthless extermination tactics, forcing the soldier to take a stand - and fight back in an epic battle for the fate of Pandora.", "Director-Writer: James Cameron \nCasts: Sam Worthington, Zoe Saldana, Sigourney Weaver");
  // TV show
  TVshow tvshow(3, 8, "Sex Education", "A teenage boy with a sex therapist mother teams up with a high school classmate to set up an underground sex therapy clinic at school.");

  //  case 4 and 5
  Show *movies = new Movie("How to train your dragon", "A hapless young Viking who aspires to hunt dragons becomes the unlikely friend of a young dragon himself, and learns there may be more to the creatures than he assumed.", "Producer: Walt Disney");

  Show *tvshows = new TVshow(1, 16, "All of Us are Dead", "A high school becomes ground zero for a zombie virus outbreak. Trapped students must fight their way out or turn into one of the rabid infected.");

  cout << "Welcome to the Show Program!" << endl << endl;

  while (true) {

    intructions();
    cout << "Your choice: ";
    cin >> iinput;
    cout << endl;

    switch(iinput) {
      case 1: // an instance of Show.
        cout << "The show is now showing ..." << endl << endl;
        show.setTitle(show.getTitle());
        show.setDescription(show.getDescription());
        show.details();
        break;
      case 2: // an instance of Movie.
        cout << "Now showing a movie ..." << endl << endl;
        movie.getCredits();
        movie.Play();
        break;
      case 3: // an instance of TV show.
        cout << "Looking for a TV show ..." << endl << endl;
        tvshow.Play();
        tvshow.details();
        tvshow.showdetails();
        break;
      case 4: // an instance of Movie declared as Show.
        cout << "Now showing a movie ..." << endl << endl;
        movies->setTitle(movies->getTitle());
        movies->setDescription(movies->getDescription());
        movies->details();       
        break;
      case 5: // an instance of TV Show declared as Show.
        cout << "Looking for a TV show ..." << endl << endl;
        tvshows->setTitle(tvshows->getTitle());
        tvshows->setDescription(tvshows->getDescription());
        tvshows->Play();
        tvshows->details();
        tvshows->showdetails();
        break;
      case 6: // exit/terminate the program
        return 0;
        break;
      default: // loop again when get invalid input from user
        cout << "Invalid Input" << endl << endl;
        break;
    }
  }
}