#ifndef STUDENT
#define STUDENT
#include <string>
#include <iostream>
using namespace std;

class Student {

	private:
		string firstName;
		string lastName;
		string MNumber;

	public:
		Student(); //constructor;
		void setFirst(string); // student's first name
		void setLast(string); // student's last name
		void setMNumber(string); // student's MNumber
		string getFirst();
		string getLast();
		string getMNumber();
};

// constructor
Student::Student() {}

void Student::setFirst(string name) {
	firstName = name;
}

void Student::setLast(string name) {
	lastName = name;
}

void Student::setMNumber(string number) {
	MNumber = number;
}

string Student::getFirst() {
	return firstName;
}

string Student::getLast() {
	return lastName;
}

string Student::getMNumber() {
	return MNumber;
}

#endif // !STUDENT