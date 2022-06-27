#ifndef TEST
#define TEST
#include <iostream>
#include "HashTable.h"
using namespace std;

class Test {

	public:

		HashTable Hash;

		void testInsert();
		void testRemove();
		void testNotInRemove();
		void testFind();
		void testFindNotInlist();
		void testPrint();
};

void Test::testInsert() {

	try {
		if (Hash.insert(7) >= 1
			&& Hash.insert(100) >= 1
			&& Hash.insert(50) >= 1
			&& Hash.insert(70) >= 1
			&& Hash.insert(30) >= 1
			&& Hash.insert(25) >= 1
			&& Hash.insert(25) >= 1
			&& Hash.insert(13) >= 1
			&& Hash.insert(51) >= 1
			&& Hash.insert(13) >= 1)
			cout << "Insert: Pass!" << endl;
	}
	catch (...) {
		cout << "Fail" << endl;
	}
}

void Test::testRemove() {

	try {
		if ((Hash.remove(13) >= 1)
			&& (Hash.remove(50) >= 1)
			&& (Hash.remove(7) >= 1))
			cout << "Remove: Pass!" << endl;
	}
	catch (...) {
		cout << "Fail" << endl;
	}
}

void Test::testNotInRemove() {

	try {
		if ((Hash.remove(52) == -1)
			&& (Hash.remove(53) == -1)
			&& (Hash.remove(95) == -1)
			&& (Hash.remove(15) == -1))
			cout << "Remove: Pass!" << endl;
	}
	catch (...) {
		cout << "Fail" << endl;
	}
}

void Test::testFind() {

	try {
		if (Hash.find(30) >= 1
			&& Hash.find(25) >= 1
			&& Hash.find(100) >= 1)
			cout << "Find: Pass!" << endl;
	}
	catch (...) {
		cout << "Fail!" << endl;
	}
}

void Test::testFindNotInlist() {

	try {
		if (Hash.find(105) == -1
			&& Hash.find(1) == -1
			&& Hash.find(47) == -1)
			cout << "Find: Pass!" << endl;
	}
	catch (...) {
		cout << "Fail!" << endl;
	}
}

void Test::testPrint() {

	try {
		Hash.printTable();
	}
	catch (...) {
		cout << "Fail!" << endl;
	}
}

#endif // !TEST