#include "Player.h"

// default constructor
Player::Player() {

}

// initialize the balance
Player::Player(int balance) {

	this->balance = balance;
}

// getter and setter functions
int Player::getBalance() {

	return this->balance;
}

// update balance
void Player::setBalance(int balance) {

	this->balance = balance;
}