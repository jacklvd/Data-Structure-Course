#include "SortAlgorithm.h"
#include "Student.h"
#include "LinkedList.h"
#include <random>
#include <iostream>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;
using namespace std;

// task 3
char randomCharGenerator(int, int); // create a random character
string firstRand(int); // create first name
string lastRand(int); // create last name
string MNumberRand(int); // create MNumber
void instruction();
void display();

const int SIZE = 50; // we need to store 50 names

int main() {

	// declare all the needed data
	srand(time(NULL));
	int lenFirst = 0; // length of first name
	int lenLast = 0; // length of last name
	int lenMNum = 8; // length of the mnumber
	string first, last, mnum;
	int input1 = 0, input2 = 0;

	// main executed loop
	while (true) {

		LinkedList<string>* list = new LinkedList<string>[SIZE];
		Sort<LinkedList<string>> sort(SIZE);
		Student stu; // information for person

		string arr1[SIZE]; // arrays for first name
		string arr2[SIZE]; // arrays for last name
		string arr3[SIZE]; // arrays for mnumber

		for (int i = 0; i < SIZE; i++) {
			lenFirst = rand() % 12 + 2;
			lenLast = rand() % 12 + 3;
			first = firstRand(lenFirst); // create first name
			last = lastRand(lenLast); // create last name
			mnum = "M" + MNumberRand(lenMNum); // create the mnumber

			// set all the information for the student class to send to arrays
			stu.setFirst(first);
			stu.setLast(last);
			stu.setMNumber(mnum);

			// random generate information
			string getFirst = stu.getFirst();
			string getLast = stu.getLast();
			string getMNum = stu.getMNumber();

			// set the array values
			arr1[i] = getFirst;
			arr2[i] = getLast;
			arr3[i] = getMNum;

		}

		display();
		cout << "Your choice: ";
		cin >> input1;
		cout << endl;

		// check user input to prevent going through infinite loop
		if (!cin) {
			input1 = 0;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input" << endl;
			return 0;
		}
		else {
			// add item into linked list
			if (input1 == 1) {
				for (int i = 0; i < SIZE; i++) {
					list[i].addItem(arr1[i]);
					list[i].addItem(arr2[i]);
					list[i].addItem(arr3[i]);
				}
			}
			else if (input1 == 2) {
				for (int i = 0; i < SIZE; i++) {
					list[i].addItem(arr2[i]);
					list[i].addItem(arr1[i]);
					list[i].addItem(arr3[i]);
				}
			}
			else if (input1 == 3) {
				for (int i = 0; i < SIZE; i++) {
					list[i].addItem(arr3[i]);
					list[i].addItem(arr1[i]);
					list[i].addItem(arr2[i]);
				}
			}
			else if (input1 == 4) { // exit
				return 0;
			}
		}

		instruction();
		cout << "Your choice: ";
		cin >> input2;
		cout << endl;

		if (!cin) {
			input2 = 0;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (input2) {

			case 1: // bubble sort
			{
				sort.bubbleSort(list);
				break;
			}

			case 2: // insertion sort
			{
				sort.insertionSort(list);
				break;
			}

			case 3: // quick sort
			{
				sort.quickSort(list, 0, SIZE - 1);
				break;
			}

			case 4: // exit
				return 0;
				break;

			default:
				cout << "Invalid Input" << endl << endl;
				break;
		}

		cout << "Press 1 for display accending" << endl;
		cout << "Press 2 for display descending" << endl;
		cin >> input1;
		cout << endl;

		if (!cin) {
			input1 = 0;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input" << endl;
		} else {				
			if (input1 == 1) { // accending
				for (int i = 0; i < SIZE; i++) {
					list[i].printList();
					cout << "----------------------" << endl;
				}
			}
			else if (input1 == 2) { // descending
				for (int i = SIZE - 1; i >= 0; i--) {
					list[i].printList();
					cout << "----------------------" << endl;
				}
			}
		}
	}
}

// generate random characters
char randomCharGenerator(int start, int end) {

	//This was taken from
	//https://msdn.microsoft.com/en-us/library/bb982398.aspx
	random_device rd;   // non-deterministic generator
	mt19937 gen(rd()); // to seed mersenne twister.
	uniform_int_distribution<> dist(start, end); //Returns a random number
	return static_cast<char> (dist(gen));
}

// get first name
string firstRand(int len) {

	string first;
	first += randomCharGenerator(65, 90);
	for (int i = 1; i < len; i++) first += randomCharGenerator(97, 122);
	return first;
}

// get last name
string lastRand(int len) {

	string last;
	last += randomCharGenerator(65, 90);
	for (int i = 1; i < len; i++) last += randomCharGenerator(97, 122);
	return last;
}

// get MNumber
string MNumberRand(int len) {

	string MNum;
	for (int i = 0; i < len; i++) MNum += randomCharGenerator(48, 57);
	return MNum;
}

void instruction() {

	cout << "           ------------Table of Choice------------" << endl;
	cout << "              1. Bubble Sort" << endl;
	cout << "              2. Insertion Sort" << endl;
	cout << "              3. Quick Sort" << endl;
	cout << "              4. Exit" << endl;
	cout << "           ---------------------------------------" << endl << endl;
}

void display() {

	cout << "Choose what oder to display" << endl;
	cout << "   1. First Name" << endl;
	cout << "   2. Last Name" << endl;
	cout << "   3. MNumbers" << endl;
	cout << "   4. Exit" << endl << endl;
}


//// test for task 2 (done)
// int main() 
// {

// 	srand(time(NULL));
// 	int number = 100000;
// 	Sort<int> sort(number);
	
// 	int* arr = new int[number];
		
// 	for (int i = 0; i < number; i++) {
// 		arr[i] = rand() % (2 * number) + 1;
// 	}

// 	// get starting timepoint
// 	auto start = Clock::now();

// 	// testing function
// 	sort.quickSort(arr, 0, number - 1);

// 	// get ending timepoint
// 	auto stop = Clock::now();

// 	// get duration
// 	auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start).count();

// 	cout << "Time taken by Quick Sort: "
// 		<< duration << " ms" << endl;
// }