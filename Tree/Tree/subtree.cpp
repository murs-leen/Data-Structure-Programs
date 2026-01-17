//is identical
//is subtree
// mirror of tree
//desturctrue for bst

#include<iostream>
#include<stack>
struct Node {

	int data;
	Node* left;
	Node* right;
};

bool isIdentical(Node* r1, Node* r2) {

	if (!r1 || !r2) return r1 == r2;
	bool isLeftIdentical = isIdentical(r1->left, r2->left);
	bool isRightIdentical = isIdentical(r1->right, r2->right);

	return isLeftIdentical && isRightIdentical && r1->data == r2->data;
}


bool isSubtree(Node* root, Node* subroot) {

	if (!subroot) return true;
	if (!root) return false;

	if (isIdentical(root, subroot)) return true;


	return isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
}

void mirrorTree(Node* root) {

	if (!root) return; 

	std::stack<Node*> st;
	st.push(root);

	while (!st.empty()) {

		Node* curr = st.top();
		
		std::swap(curr->left, curr->right);
		st.pop();

		if (curr->left) st.push(curr->left);
		if (curr->right) st.push(curr->right);
	}

}


// post order traversel
void BST_destructure(Node* root) {

	if (!root) return;

	if (root->left) BST_destructure(root->left);
	if (root->right) BST_destructure(root->right);

	delete root;
	root = nullptr;

}

