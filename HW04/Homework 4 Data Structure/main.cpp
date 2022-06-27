#include "BinaryTree.h"
#include "HashTable.h"
#include "test.h"
#include "testTree.h"
#include <iostream>
#include <random>
using namespace std;

// prototype functions
void Task3();
void Task4A();
void Task4B();

int main() {

	int choice;

	// prompt the user'choices of input
	while (true) {
		cout << "Choose the task you want to see:" << endl;
		cout << "1. Task 3" << endl;
		cout << "2. Task 4a" << endl;
		cout << "3. Task 4b" << endl;
		cout << "4. Quit" << endl;
		cout << "Your choice: ";
		cin >> choice;
		cout << endl;

		// check user input to prevent going through infinite loop
		if (!cin) {
			choice = 0;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (choice) {
			
			case 1:
				Task3();
				break;
			case 2:
				Task4A();
				break;
			case 3:
				Task4B();
				break;
			case 4:
				return 0;
				break;
			default:
				cout << "Invalid Input!" << endl;
				break;
		}
	}
}

void Task3() {
	// task 3:
	srand(time(NULL));
	HashTable HashT;
	BinaryTree<int> Tree;
	int choice = 0;
	int array[100];
	int sumCollision = 0;
	int sumAVLTreeCollision = 0;

	// task 3a:
	for (int i = 0; i < 100; i++) {
		int num = rand() % 100 + 1;
		array[i] = num;
	}

	for (int i = 0; i < 50; i++) {
		sumCollision += HashT.insert(array[i]);
		Tree.insert(array[i]);
	}

	cout << "Collision happened when insert in Hash Table: " << sumCollision << endl;
	cout << "Collision happened when insert in BST: " << Tree.insertCounter << endl << endl;

	// task 3b:
	sumCollision = 0;

	for (int i = 0; i < 50; i += 7) {
		sumCollision += HashT.remove(array[i]);
		Tree.remove(array[i]);
	}

	cout << "Collision happened when remove number at index % 7 == 0 in Hash Table: " << sumCollision << endl;
	cout << "Collision happened when remove number at index % 7 == 0 in BST: " << Tree.removeCounter << endl << endl;

	// task 3c:
	sumCollision = 0;
	Tree.removeCounter = 0;

	for (int i = 50; i < 100; i++) {
		HashT.insert(array[i]);
		Tree.insert(array[i]);
	}

	for (int i = 50; i < 100; i++) {
		sumCollision += HashT.remove(array[i]);
		Tree.remove(array[i]);
	}

	cout << "Collision happened when remove 50 remaining of data in Hash Table: " << sumCollision << endl;
	cout << "Collision happened when remove 50 remaining of data in BST: " << Tree.removeCounter << endl << endl;

	// task 3d:
	for (int i = 0; i < 100; i += 9) {
		sumCollision += HashT.find(array[i]);
		Tree.find(array[i]);
	}

	cout << "Collision happened when find index % 9 == 0 in Hash Table: " << sumCollision << endl;
	cout << "Collision happened when find index % 9 == 0 in BST: " << Tree.findCounter << endl << endl;

	cout << "-----------END of Task 3-----------" << endl << endl;
}

void Task4A() {

	Test test;

	test.testInsert();
	test.testRemove();
	test.testNotInRemove();
	test.testFind();
	test.testFindNotInlist();
	cout << endl;
	test.testPrint();
}

void Task4B() {

	TestTree test;

	test.testInsert();
	test.testRemove();
	test.testFind();
	test.testFindNotInTree();
	test.testPrint();
}