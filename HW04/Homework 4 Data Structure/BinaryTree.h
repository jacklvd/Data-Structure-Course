#ifndef BINARYTREE
#define BINARYTREE
#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
class BinaryTree {

protected:

	struct TreeNode
	{
		T val; // value in the node
		TreeNode* left; // pointer to left child node
		TreeNode* right; // pointer to right child node
	};

	TreeNode* root; // pointer to the root node
	int treeSize = 0;

	void insert(TreeNode*&, TreeNode*&);
	void emptytree(TreeNode*);
	void deleteNode(T, TreeNode*&);
	void makeDeletion(TreeNode*&);
	void display(TreeNode*, int indent) const;
	bool checkHeight(TreeNode* node);
	int height(TreeNode* node);

public:

	int insertCounter = 0;
	int removeCounter = 0;
	int findCounter = 0;

	// constructor
	BinaryTree()
	{
		root = nullptr;
	}

	// destructor
	~BinaryTree()
	{
		emptytree(root);
	}

	void insert(T data);
	void displayPostOrder() const;
	void remove(T data);
	int size();
	bool find(T data);
	bool checkHeightBalance();
	bool isEmpty() const { return root == nullptr; }
};

template <class T>
void BinaryTree<T>::insert(T data) {

	TreeNode* node = nullptr; // pointer to a new node

	// create a new node and store data in it
	node = new TreeNode;
	node->val = data;
	node->left = node->right = nullptr;

	// insert the node
	if (isEmpty()) {
		insertCounter++;
		root = node;
	}
	else {
		insert(root, node);
		treeSize++;
	}
}

template <class T>
void BinaryTree<T>::insert(TreeNode*& nodePtr, TreeNode*& node) {

	if (nodePtr == nullptr) {
		insertCounter++;
		nodePtr = node;
	}
	else if (node->val > nodePtr->val) {
		insertCounter++;
		insert(nodePtr->right, node); // search the left branch.
	}
	else {
		insertCounter++;
		insert(nodePtr->left, node); // search the right branch.
	}
}

template <class T>
void BinaryTree<T>::display(TreeNode* curr, int indent) const {

	int i;
	if (curr != nullptr) {
		display(curr->right, indent + 1);
		cout << "| ";
		if (curr == root) {
			cout << "Root -> ";
		}
		for (i = 0; i < indent && curr != root; i++) {
			cout << "         ";
		}
		cout << curr->val << endl;
		display(curr->left, indent + 1);
	}
}

template <class T>
void BinaryTree<T>::displayPostOrder() const {

	BinaryTree<T>::display(root, 0);
}

template <class T>
bool BinaryTree<T>::find(T data) {

	TreeNode* node = root;
	while (node) {
		if (node->val == data) {
			findCounter++;
			return true; // found the tree node
		}
		else if (data < node->val) {
			findCounter++;
			node = node->left;
		}
		else {
			findCounter++;
			node = node->right;
		}
	}
	return false;
}

template <class T>
int BinaryTree<T>::size() {
	return treeSize;
}

template <class T>
void BinaryTree<T>::deleteNode(T data, TreeNode*& node) {

	if (data < node->val) {
		removeCounter++;
		deleteNode(data, node->left); // move the pointer to the left
	}
	else if (data > node->val) {
		removeCounter++;
		deleteNode(data, node->right); // move the pointer to the right
	}
	else {
		removeCounter++;
		BinaryTree<T>::makeDeletion(node);
	}
}

template <class T>
void BinaryTree<T>::makeDeletion(TreeNode*& node) {

	// define a temporary poiner to use in reattaching
	// the left subtree
	TreeNode* tempNode = nullptr;

	if (node == nullptr) {
		cout << "Cannot delete empty node." << endl;
	}
	else if (node->right == nullptr) {
		tempNode = node;
		node = node->left; // reattach the left child
		delete tempNode;
	}
	else if (node->left == nullptr) {
		tempNode = node;
		node = node->right; // reattach the right child
		delete tempNode;
	}
	else {
		// if the node has two children
		// move one node to the right
		tempNode = node->right;
		// go to the end of left branch
		while (tempNode->left) {
			tempNode = tempNode->left;
		}
		// reattach the left subtree
		tempNode->left = node->left;
		tempNode = node;
		// reattach the right substree
		node = node->right;
		delete tempNode;
	}
}

template <class T>
void BinaryTree<T>::remove(T data) {

	BinaryTree<T>::deleteNode(data, root);
	treeSize--;
}

// delete the whole tree, function execute by the destructor
template <class T>
void BinaryTree<T>::emptytree(TreeNode* node) {

	if (node) {
		if (node->left) {
			emptytree(node->left); // move the pointer to point at left node
		}
		if (node->right) {
			emptytree(node->right); // move the pointer to point at the right node
		}
		delete node;
	}
}

// helper function to return the max node of right or left
template <class T>
int maxNode(T a, T b) {

	return (a >= b) ? a : b;
}

// calculate the height of tree
template <class T>
int BinaryTree<T>::height(TreeNode* node) {

	if (node == nullptr) {
		return 0;
	}
	return node->level;
}

// check the height of the tree
template <class T>
bool BinaryTree<T>::checkHeight(TreeNode* node) {

	if (node == nullptr) {
		return 1;
	}
	int rightNode, leftNode;
	rightNode = height(node->right);
	leftNode = height(node->left);

	if (abs(leftNode - rightNode) <= 1 && checkHeight(root->left)
		&& checkHeight(root->right)) {
		return 1;
	}
	return 0;
}

template <class T>
bool BinaryTree<T>::checkHeightBalance() {

	bool res = BinaryTree<T>::checkHeight(root);
	return res;
}
#endif