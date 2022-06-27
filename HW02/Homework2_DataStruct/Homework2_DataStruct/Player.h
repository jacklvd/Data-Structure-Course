#ifndef PLAYER_H
#define PLAYER_H

#include "Wheel.h"

class Player {

private:
    // store the balance of the player
    int balance;
public:
    // instance of the wheel class
    Wheel wheel;
    // defautl constructor
    Player();
    Player(int);
    // setter and getter function
    int getBalance();
    void setBalance(int);
};


#endif