#include "TVshow.h"
#include <iostream>

/*
Initialize and overidde the Show class with derived TVshow class
*/

// Global variable
Show show;

// Default constructor
TVshow::TVshow() {

}

// Default constructor with 4 parameters
TVshow::TVshow(int season, int episode, string title, string description) {
  this->seasons = season;
  this->episodes = episode;
  seArray[season][episode];
  show.setTitle(title);
  show.setDescription(description);
  this->setTitle(title);
  this->setDescription(description);
}
/////////////////Getter and Setter/////////////////
int TVshow::getSeasons() {

  return seasons;
}
int TVshow::getEpisodes() {

  return episodes;
}
void TVshow::setSeasons(int season) {

  seasons = season;
}
void TVshow::setEpisodes(int episode) {

  episodes = episode;
}

void TVshow::setse(int season, int episode) {
  
  seArray[season][episode];
}
/////////////////////////////////////////////////

// print out the details
void TVshow::showdetails()
{
  show.showdetails();
  cout << "Now showing season " << this->seasons << ", episode " << this->episodes << endl << endl;
}

// ask users to input season and episode then store in seasons and episodes
void TVshow::Play()
{
  int season, episode;
  cout << "Which season are you looking for?" << endl;
  cout << "Enter: ";
  cin >> this->seasons;
  cout << endl << "Which episode would you like?" << endl;
  cout << "Enter: ";
  cin >> this->episodes;
  cout << endl;
};
