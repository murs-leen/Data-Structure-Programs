//// Tree data structure
//
//#include<iostream>
//using namespace std;
//
//class Node {
//public:
//
//	int data;
//	Node* left;
//	Node* right;
//
//	Node(int x)
//		: data(x), left(nullptr), right(nullptr) {
//	}
//
//};
//
//Node* buildTree(Node* node) {
//
//	int val;
//	cout << "Enter data: ";
//	cin >> val;
//
//	if (val == -1) return nullptr;
//
//	node = new Node(val);
//
//	cout << "Enter data for right node of value: " << val << ":";
//	node->right = buildTree(node->right);
//	cout << "Enter data for left node of value: " << val << ":";
//	node->left = buildTree(node->left);
//
//	return node;
//
//}
//
//Node* getNewNode(int val) {
//
//	Node* newNode = new Node(val);
//	return newNode;
//}
//
//
//Node* insert(Node* node, int val) {
//
//	if (!node) {
//
//		node = getNewNode(val);
//	}
//	if (val < node->data) {
//		node->left = insert(node->left, val);
//	}
//	else if (val > node->data) {
//		node->right = insert(node->right, val);
//	}
//
//	return node;
//}
//
//bool search(Node* node, int data) {
//
//	if (!node) return false;
//	if (data == node->data) return true;
//	if (data < node->data) return search(node->left, data);
//	else if (data > node->data) return search(node->right, data);
//}
//
//void print(Node* node) {
//	
//	if (!node) return;
//
//	cout << node->data << " ";
//	print(node->left);
//	print(node->right);
//
//}
//int main() {
//
//	Node* root = nullptr;
//	root = buildTree(root);
//	print(root);
//
//
//}