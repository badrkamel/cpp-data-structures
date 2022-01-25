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
	Node *root = NULL;

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

	bool search(Node *pnode, int key) {
		if (pnode==NULL) {
			return false;
		} else if (pnode->value==key) {
			return true;
		} else {
			if (key < pnode->value)
				return search(pnode->left, key);
			else
				return search(pnode->right, key);
		}
	}

	void preOrder(Node *pNode) {
		if (pNode==NULL) {
			return;
		}
		cout << pNode->value << " ";
		preOrder(pNode->left);
		preOrder(pNode->right);
	}
	void preOrder() {
		cout << "Preorder:: \n";
		preOrder(root);
		cout << endl;
	}

	Node *MIN_Node(Node *pNode) {
		if (pNode==NULL) {
			cout << "Tree Is Empty\n";
			return NULL;
		}
		if (pNode->left==NULL) {
			return pNode;
		}
		return MIN_Node(pNode->left);
	}

	Node *MAX_Node(Node *pNode) {
		if (pNode==NULL) {
			cout << "Tree Is Empty\n";
			return NULL;
		}
		if (pNode->right==NULL) {
			return pNode;
		}
		return MAX_Node(pNode->right);
	}

	Node *remove(Node *pNode, int key) {
		if (pNode==NULL) {
			return NULL;
		}
		if (key<pNode->value)
			pNode->left = remove(pNode->left, key);
		else if (key>pNode->value)
			pNode->right = remove(pNode->right, key);

		else {
			// Leaf node to delete
			if (pNode->left == NULL && pNode->right==NULL)
				pNode = NULL;

			// one children
			else if (pNode->left != NULL && pNode->right == NULL) {
				Node *temp = pNode;
				pNode = pNode->left;
				delete temp;
			}
			else if (pNode->left == NULL && pNode->right != NULL) {
				Node *temp = pNode;
				pNode = pNode->right;
				delete temp;
			}
			else {
				Node* max = MAX_Node(pNode->left);
				pNode->value = max->value;
				pNode->left = remove(pNode->left, max->value);
			}
		}
		return pNode;
	}

};

int main() {
	cout << "BST\n\n";

	BST tree;

	tree.MIN_Node(tree.root);

	// Insert values into BST
	int values[10] = {34,23,22,6,16,18,57,38,95,12};
	for (int i{}; i<10;i++) {
		tree.insert(values[i]);
	}

	Node *root = tree.root;

	tree.preOrder();

	tree.search(root, 4) ? cout << "Found\n" : cout << "Not found\n";
	tree.search(root, 6) ? cout << "Found\n" : cout << "Not found\n";

	tree.remove(root, 6);
	tree.preOrder();
	tree.remove(root, 94);
	tree.remove(root, 95);

	tree.preOrder();

	Node *min = tree.MIN_Node(root);
	if (min != NULL) {
		cout << "The Minimum Value Is: " << min->value << endl;
	}

	Node *max = tree.MAX_Node(root);
	if (max != NULL) {
		cout << "The Maximun Value Is: " << max->value << endl;
	}

}
