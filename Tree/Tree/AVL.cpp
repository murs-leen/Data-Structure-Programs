//AVL- self balancing tree (Balanced BST)
// BST - worst time compleixty O(n)
//AVL insures to reduce BST time compleixty to O(log n)


#include<iostream>
using namespace std;

class Node {
public:

	int data;
	Node* left;
	Node* right;
	int height;

	Node(int x) :
		data(x), left(nullptr), right(nullptr),height(1) {
	}
};

int min(Node* root) {

	if (!root) return -1;
	if (root->left == nullptr)
		return root->data;

	return min(root->left);
}


int getHeight(Node* root) {

	return (root == nullptr ? 0 : root->height);
}


int getBalanceFactor(Node* root) {

	return (getHeight(root->left) - getHeight(root->right));

}


Node* rightRotation(Node* y) {

	Node* x = y->left;
	Node* T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = 1 + max(getHeight(y->left), getHeight(y->right));
	x->height = 1 + max(getHeight(x->left), getHeight(x->right));

	return x;

}


Node* leftRotation(Node* x) {

	Node* y = x->right;
	Node* T2 = y->left;

	y->left = x;
	x->right = T2;

	y->height = 1 + max(getHeight(y->left), getHeight(y->right));
	x->height = 1 + max(getHeight(x->left), getHeight(x->right));

	return y;
}


Node* insert(Node* root, int val) {

	if (!root) return new Node(val);

	if (val < root->data) root->left = insert(root->left, val);

	else if (val > root->data) root->right = insert(root->right, val);

	else return root;

	root->height = 1 + max(getHeight(root->left), getHeight(root->right));

	int bal = getBalanceFactor(root);


	//-------  Rotations --------


	// left-left rotation(LL)

	if (bal > 1 && val < root->left->data) return rightRotation(root);

	//right-right rotation(RR)

	else if (bal < -1 && val > root->right->data) return leftRotation(root);

	//left-right rotation(LR)

	else if (bal > 1 && val > root->left->data) {

		root->left =  leftRotation(root->left);
		return rightRotation(root);

	}

	//right-left rotation(RL)

	else if (bal < -1 && val < root->right->data) {

		root->right = rightRotation(root->right);
		return leftRotation(root);
	}

	//no rotation
	else return root;


}

Node* deleteNode(Node* root, int val) {

	if (!root) return nullptr;

	if (val < root->data)
		root->left = deleteNode(root->left, val);

	else if (val > root->data)
		root->right = deleteNode(root->right, val);

	else {

		// Case 1: no child
		if (!root->left && !root->right) {
			delete root;
			return nullptr;
		}

		// Case 2: one child (left)
		else if (!root->right) {
			Node* temp = root->left;
			delete root;
			return temp;
		}

		// Case 2: one child (right)
		else if (!root->left) {
			Node* temp = root->right;
			delete root;
			return temp;
		}

		// Case 3: two children
		else {

			root->data = min(root->right);
			root->right = deleteNode(root->right, root->data);
		}
	}

	// update height
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));

	// check balance
	int bal = getBalanceFactor(root);

	// LL(bal +ve, factor +ve)
	if (bal > 1 && getBalanceFactor(root->left) >= 0)
		return rightRotation(root);

	// LR (bal +ve factor -ve)
	if (bal > 1 && getBalanceFactor(root->left) < 0) {

		root->left = leftRotation(root->left);
		return rightRotation(root);
	}

	// RR
	if (bal < -1 && getBalanceFactor(root->right) <= 0)
		return leftRotation(root);

	// RL
	if (bal < -1 && getBalanceFactor(root->right) > 0) {

		root->right = rightRotation(root->right);
		return leftRotation(root);
	}

	return root;
}



void preorder(Node* root) {

	if (!root) return;

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node* root) {

	if (!root) return;

	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}


int main() {

	Node* root = nullptr;
	root = insert(root, 10);
	root = insert(root, 20); 
	root = insert(root, 30);
	root = insert(root, 40);


	root = insert(root, 67);
	root = insert(root, 46);
	root = insert(root, 78);
	root = insert(root, 45);

	cout << "Preorder: ";
	preorder(root);
	cout << "\nPostorder: ";
	postorder(root);

	root = deleteNode(root, 67);
	cout << endl;
	cout << "Preorder(After deletion): ";
	preorder(root); 
	cout << endl;
}
