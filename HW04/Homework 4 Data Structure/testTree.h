#ifndef TESTTREE
#define TESTTREE
#include "BinaryTree.h"

class TestTree {
	
	public:
		BinaryTree<int> BTree;

		void testInsert();
		void testRemove();
		void testFind();
		void testFindNotInTree();
		void testPrint();
};

void TestTree::testInsert() {

	try {
		BTree.insert(30);
		BTree.insert(50);
		BTree.insert(45);
		BTree.insert(51);
		BTree.insert(12);
		BTree.insert(15);
		BTree.insert(7);
		BTree.insert(9);
		BTree.insert(61);
	}
	catch (...) {
		cout << "Fail!" << endl;
	} 
}

void TestTree::testRemove() {

	try {
		BTree.remove(50);
		BTree.remove(45);
		BTree.remove(15);
		BTree.remove(9);
	}
	catch (...) {
		cout << "Fail!" << endl;
	}
}

void TestTree::testFind() {
	
	try {
		if (BTree.find(61)
			&& BTree.find(12)
			&& BTree.find(30))
			cout << "Pass!" << endl;
	}
	catch (...) {
		cout << "Fail!" << endl;
	}
}

void TestTree::testFindNotInTree() {

	try {
		if (BTree.find(43) == false
			&& BTree.find(4) == false
			&& BTree.find(81) == false
			&& BTree.find(79) == false)
			cout << "Pass!" << endl;
	}
	catch (...) {
		cout << "Fail!" << endl;
	}
}


void TestTree::testPrint() {

	try {
		BTree.displayPostOrder();
	}
	catch (...) {
		cout << "Fail!" << endl;
	}
}

#endif // TESTTREE