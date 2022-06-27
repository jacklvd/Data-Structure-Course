#ifndef HASHTABLE
#define HASHTABLE
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 100;

class HashTable {

	protected:

		struct Table {
			int* table;
			bool* data;
		};
		Table* storage;
		int size;

	public:

		// exception classes
		class StackOverFlow{};
		class StackUnderFlow{};

		// constructor
		HashTable() {
			// initialize all the variables
			storage = new Table;
			storage->table = new int[SIZE];
			storage->data = new bool[SIZE];
			size = 0;
			for (int i = 0; i < SIZE; i++) {
				storage->table[i] = -1;
				storage->data[i] = false;
			}
		}

		// destructor
		~HashTable(){
			delete storage;
			storage = new Table;
		}	

		int Hash(int);
		int insert(int);
		int remove(int);
		int find(int);
		int getLength() { return size; }
		void printTable();

};

// hash function to find the empty in the table
int HashTable::Hash(int input) {

	return input % SIZE;
}

// insert data into the table
int HashTable::insert(int item) {

	if (size > SIZE) { 
		throw StackOverFlow();
	}
	// find index to insert item
	int counter = 1; // tracking the collisions
	int index = Hash(item);
	// this is where the collision happen
	while (storage->table[index] != -1 && !storage->data[index]) {
		index = (index + 1) % SIZE;
		counter++;
	}
	storage->table[index] = item;
	storage->data[index] = false;
	size++;
	return counter;
}

// remove data from the table
int HashTable::remove(int item) {

	int counter = 1; // keep track of collision
	int	index = Hash(item);
	int originialIndex = index;

	// looping to find spot of wanted for removing
	while (storage->table[index] != -1) {
		if (storage->table[index] == item) {
			storage->data[index] = true;
			storage->table[index] = -1;
			size--;
			return index;
		}
		// update index
		index = (index + 1) % SIZE;
		counter++;
		if (index == originialIndex) break;
	}
	return -1;
}

// find item from the table
int HashTable::find(int item) {

	int counter = 1; // to keep track of number of spots to check for that item
	int	index = Hash(item);
	int originialIndex = index;

	while (index != -1 || storage->data[index]) {
		if (storage->table[index] != -1 && storage->table[index] == item) {
			return counter; // return the collisions where item was found
		}
		index = (index + 1) % SIZE;
		counter++;
		if (index == originialIndex) break;
	}
	return -1; // not found
}

// print table
void HashTable::printTable() {

	cout << "---------Hash Table---------" << endl;
	for (int i = 0; i < SIZE; i++) {
		if (storage->table[i] != -1 && !storage->data[i]) {
			cout << "\tkey " << i << ": " << storage->table[i] << " " << endl;
		}
		else {
			cout << "Empty Spot" << endl;
		}
	}
	cout << endl;
}

#endif // !HASHTABLE