#ifndef AVLTREE
#define AVLTREE
#include <iostream>
#include <iomanip>
#include<sstream>
#include<algorithm>
using namespace std;

template <class T>
class AVLTree {

	protected:
		struct TreeNode
		{
			T val; // value in the node
			TreeNode* left; // pointer to left child node
			TreeNode* right; // pointer to right child node
		};
		TreeNode* root;
		int treeSize;
		T* store[];

		int height(TreeNode*);
		int different(TreeNode*);

		// right-right rotation
		TreeNode* rightRotation(TreeNode* parent) {

			TreeNode* temp;
			temp = parent->right; //point root to the right node
			parent->right = temp->left; //assign parent to the left node
			temp->left = parent; // rotate
			return temp; // return that value

		}

		// left-left rotation
		TreeNode* leftRotation(TreeNode* parent) {

			TreeNode* temp;
			temp = parent->left;
			parent->left = temp->right;
			temp->right = parent;
			return temp;

		}

		// balance function
		TreeNode* balance(TreeNode* node) {

			int balanceFactor = different(node);

			if (balanceFactor > 1) {
				// left-left rotation
				if (different(node->left) > 0) {
					node = leftRotation(node);
				}
				// left-right rotation
				else {
					TreeNode* temp;
					temp = node->left;
					node->left = rightRotation(temp);
					node = leftRotation(node);
				}
			}
			else if (balanceFactor < -1) {
				// right-left rotation
				if (different(node->right) > 0) {
					TreeNode* temp;
					temp = node->right;
					node->right = leftRotation(temp);
					node = rightRotation(node);
				}
				// right-right rotation
				else {
					node = rightRotation(node);
				}
			}
			return node;
		}

		// insert and balance at the same time
		TreeNode* insert(TreeNode* root, T data) {

			if (root == nullptr) {
				root = new TreeNode;
				root->val = data;
				root->left = root->right = nullptr;
				return root;
			}
			// find where to insert the node
			// add the node and balance it at the same time
			else if (data < root->val) {
				root->left = insert(root->left, data);
				root = balance(root);
			}
			else if (data >= root->val) {
				root->right = insert(root->right, data);
				root = balance(root);
			}
			return root;
		}

		// find node with minimum value
		TreeNode* minNode(TreeNode* node) {
			
			TreeNode* curr = node;

			// loop down to find the leftmost node
			while (curr->left != nullptr) {
				curr = curr->left;
			}
			return curr;
		}

		// new balance function used for remove()
		TreeNode* balanceRemove(TreeNode* node) {

			// update the balance factor as well as height of tree
			int balanceFactor = different(node);

			if (balanceFactor > 1) {
				// right-right rotation
				if (different(node->left) >= 0) {
					node = rightRotation(node);
				}
				// left-right rotation
				else {
					node->left = leftRotation(node->left);
					node = rightRotation(node);
				}
			}
			else if (balanceFactor < -1) {
				// left-left rotation
				if (different(node->right) <= 0) {
					node = leftRotation(node);
				}
				// right-left rotation
				else {
					node->right = rightRotation(node->right);
					node = leftRotation(node);
				}
			}
			return node;
		}

		TreeNode* remove(TreeNode* node, T data) {
			
			// find left-right node to move the pointer to the delete node
			if (node == nullptr) {
				return node; // tree is empty
			}
			// if node value is bigger than the value to be deleted
			if (data < node->val) {
				node->left = remove(node->left, data);
				node = balanceRemove(node);
			}
			// if node value is smaller than the value to be deleted
			else if (data > node->val) {
				node->right = remove(node->right, data);
				node = balanceRemove(node);
			}
			// if the data found is same as the root then it is the one to be deleted
			else {
				// node with only one child or no child
				if ((node->left == nullptr) || (node->right == nullptr)) {
					TreeNode* temp = node->left ? node->left : node->right;
					// no child case
					if (temp == nullptr) {
						temp = node;
						node = nullptr;
					}
					else { // one child case
						*node = *temp; // copy the content of of non-empty child
					}
					free(temp); // free memory of temp node
				}
				else {
					// node with 2 children
					TreeNode* temp = minNode(node->right);
					node->val = temp->val;
					node->right = remove(node->right, temp->val);
				}
			}

			// if tree has only one node then return
			if (node == nullptr) return node;
			node = balanceRemove(node);
			return node;
		}

		// all the values of a subtree in descending order
		void getAllDescending(TreeNode* node);
		// all the values of a subtree in ascending order
		void getAllAscending(TreeNode* node);
		void display(TreeNode*, int) const;
		void emptyTree(TreeNode*);
		bool checkHeight(TreeNode*);

	public:

		// constructor
		AVLTree() {
			root = nullptr;
			treeSize = 0;
		}

		// destructor - to avoid memory leak
		~AVLTree() {
			emptyTree(root);
			root = nullptr;
			treeSize = 0;
		}

		void insert(T);
		void remove(T);
		void display() const;
		void getAllDescending();
		void getAllAscending();
		int size();
		bool checkBalance();
		bool find(T);
		bool isEmpty() { return root == nullptr; }

		TreeNode* findTree(T data) {

			TreeNode* node = root;
			if (node == nullptr) {
				return nullptr;
			}

			while (node) {
				if (node->val == data) {
					return node; // found the tree node
				}
				else if (data < node->val) {
					node = node->left;
				}
				else {
					node = node->right;
				}
			}
      return nullptr;
		}
};

// calculate the height/levels of the tree
template <class T>
int AVLTree<T>::height(TreeNode* node) {

	int level = 0;
	if (node != nullptr) {
		int leftLevel = height(node->left);
		int rightLevel = height(node->right);
		int maxLevel = max(leftLevel, rightLevel);
		level = maxLevel + 1;
	}
	return level;
}

// calculate the different between height of left and right node to
// determine if shoudl balance the tree
template <class T>
int AVLTree<T>::different(TreeNode* node) {

	if (node == nullptr) {
		return 0;
	}
	int left = height(node->left);
	int right = height(node->right);
	int factor = left - right;
	return factor;
}

template <class T>
void AVLTree<T>::insert(T data) {
	
	root = insert(root, data);
	treeSize++;
}

template <class T>
void AVLTree<T>::remove(T data) {

	root = remove(root, data);
	treeSize--;
}

template <class T>
void AVLTree<T>::display(TreeNode* curr, int indent) const {

	int i;
	if (curr != nullptr) {
		display(curr->right, indent + 1);
		cout << "| ";
		if (curr == root) {
			cout << "Root -> ";
		}
		for (i = 0; i < indent && curr != root; i++) {
			cout << "        ";
		}
		cout << curr->val << endl;
		display(curr->left, indent + 1);
	}
}

// display in postorder
template <class T>
void AVLTree<T>::display() const {
	
	display(root, 1);
}

template <class T>
int AVLTree<T>::size() {
	return treeSize;
}

// delete the whole tree, function execute by the destructor
template <class T>
void AVLTree<T>::emptyTree(TreeNode* node) {

	if (node) {
		if (node->left) {
			emptyTree(node->left); // move the pointer to point at left node
		}
		if (node->right) {
			emptyTree(node->right); // move the pointer to point at the right node
		}
		delete node;
	}
}

// check the height of the tree
template <class T>
bool AVLTree<T>::checkHeight(TreeNode* node) {

	if (node == nullptr) {
		return 1;
	}
	int rightNode, leftNode;
	rightNode = height(node->right);
	leftNode = height(node->left);

	if (abs(leftNode - rightNode) <= 1 && checkHeight(node->left)
		&& checkHeight(node->right)) {
		return 1;
	}
	return 0;
}

template <class T>
bool AVLTree<T>::checkBalance() {

	bool res = AVLTree<T>::checkHeight(root);
	return res;
}

template <class T>
bool AVLTree<T>::find(T data) {

	TreeNode* node = root;
	while (node) {
		if (node->val == data) {
			return true; // found the tree node
		}
		else if (data < node->val) {
			node = node->left;
		}
		else {
			node = node->right;
		}
		return false;
	}
}

template <class T>
void AVLTree<T>::getAllAscending(TreeNode* node) {

	if (node == nullptr) {
		return;
	}
	getAllAscending(node->left);
	cout << node->val << " ";
	getAllAscending(node->right);
}

template <class T>
void AVLTree<T>::getAllAscending() {

	getAllAscending(root);
}

template <class T>
void AVLTree<T>::getAllDescending(TreeNode* node) {

	if (node == nullptr) {
		return;
	}
	getAllDescending(node->right);
	cout << node->val << " ";
	getAllDescending(node->left);
}

template <class T>
void AVLTree<T>::getAllDescending() {

	getAllDescending(root);
}

#endif