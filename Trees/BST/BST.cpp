#include <iostream>

using namespace std;

struct Node {
	int value;
	Node *left, *right;

	Node (int v) {
		value = v;
		left = right = NULL;
	}
};

struct BST
{
	Node *root;
	BST() {
		root = NULL;
	}

	Node *insert(Node *pNode, int value) {
		if (pNode==NULL) {
			Node *node = new Node(value);
			pNode = node;
		} else {
			if (value < pNode->value) {
				pNode->left = insert(pNode->left, value);
			} else {
				pNode->right = insert(pNode->right, value);
			}
		}
		return pNode;
	}

	void insert(int value) {
		root = insert(root, value);
	}

	void preOrder(Node *pNode) {
		if (pNode==NULL) {
			return;
		}
		cout << pNode->value << " ";
		preOrder(pNode->left);
		preOrder(pNode->right);
	}
};

int main() {
	cout << "BST\n\n";

	BST tree;

	// Insert values into BST
	int values[10] = {34,23,22,6,16,18,57,38,95,12};
	for (int i{}; i<10;i++) {
		tree.insert(values[i]);
	}

	cout << "Display the Tree Content \n";
	tree.preOrder(tree.root);
	cout << endl;
}
