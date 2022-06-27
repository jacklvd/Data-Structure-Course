// Requirement 1:
#ifndef WHEEL_H
#define WHEEL_H

#include <iostream>
#include <cstring>
#include <random>
#include <cstdlib>
using namespace std;

class Wheel {

private:
    int min_range;
    int max_range;
    int ball;           // to store random numbers

public:
    Wheel();
    Wheel(int, int);    // constructor for setting range
    void spin();        // generate random number
    void spin(bool, int, int); // generate random number, update the range for the hard mode
    int getBall();      // get that random number
    int getHouseBall(); // get the house number
};

#endif