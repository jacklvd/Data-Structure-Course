#include "Wheel.h"

int house_ball;
int house_min = 1;
int house_max;

// default constructor
Wheel::Wheel() {
  
}

// assign value for range
Wheel::Wheel(int min_range, int max_range) {
  
  this->min_range = min_range;
  this->max_range = max_range;
  house_max = this->max_range;
}

// generate random number
void Wheel::spin() {
  ball = rand() % max_range + min_range;
}

void Wheel::spin(bool pResult, int houseWin, int callTime) {
  if (callTime == 2) {
    house_ball = rand() % house_max + house_min;
    // Check the range of house in hardmode
    // cout << house_max << endl;
    // cout << house_min << endl;
    
    return;
  }

  if (pResult == true) {
    house_min += 1;
    if (house_max < max_range){
      house_max += 1;
    }
    house_ball = rand() % house_max + house_min;
  }
  else {
    house_ball = rand() % house_max + house_min;
  }

  if (houseWin >= 2) {
    house_max -= 1;
    if (house_min > 1){
      house_min -= 1;
    }
    house_ball = rand() % house_max + house_min;
  }
  // Check the range of house in hardmode
  // cout << house_max << endl;  
  // cout << house_min << endl;
}

// get the random number which was generated in spin()
int Wheel::getBall() {

  return ball;
}

// get the house ball
int Wheel::getHouseBall() {

  return house_ball;
}