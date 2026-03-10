//#include<iostream>
//#include<queue>
//#include<vector>
//using namespace std;
//
//#define SIZE 13
//
//class Node {
//public:
//
//	int data;
//	Node* leftNode;
//	Node* rightNode;
//
//	Node(int x)
//		:data(x), leftNode(nullptr), rightNode(nullptr) {
//	}
//
//};
//
//class BinaryTree {
//public:
//
//	int index; 
//	BinaryTree()
//		:index(-1){ }
//
//	Node* buildTree(int*);
//	Node* buildBST(Node*, int);
//	void inorder(Node*);
//	void preorder(Node*);
//	void postorder(Node*);
//	void levelOrderTraversel(Node*);
//	int max(Node*);
//	Node* min(Node*);
//};
//
//Node* BinaryTree::buildBST(Node* root, int data) {
//
//	if (!root) return new Node(data);
//	if (data > root->data) root->rightNode = buildBST(root->rightNode, data);
//	if (data < root->data) root->leftNode = buildBST(root->leftNode, data);
//	return root;
//
//}
//
//int BinaryTree::max(Node* root) {
//
//	if (!root) return -1;
//
//	if (root->rightNode == nullptr)
//		return root->data;
//
//	return max(root->rightNode);
//
//}
//
//
//Node* BinaryTree::min(Node* root) {
//
//	if (!root) return nullptr;
//
//	if (root->leftNode == nullptr)
//		return root;
//
//	return min(root->leftNode);
//}
//
//
//Node* BinaryTree::buildTree(int* node) {
//
//	index++;
//	if (node[index] == -1) { return nullptr; }
//
//	Node* newNode = new Node(node[index]);
//	newNode->leftNode = buildTree(node);
//	newNode->rightNode = buildTree(node);
//	return newNode;
//
//}
//
//
//void BinaryTree::inorder(Node* root) {
//
//	if (root == nullptr) return;
//	inorder(root->leftNode);
//	cout << root->data << " ";
//	inorder(root->rightNode);
//
//}
//
//
//void BinaryTree::preorder(Node* root) {
//
//	if (!root) { return; }
//	
//	cout << root->data << " ";
//	preorder(root->leftNode);
//	preorder(root->rightNode);
//}
//
//
//void BinaryTree::postorder(Node* root) {
//
//	if (!root) { return; }
//
//	preorder(root->leftNode);
//	preorder(root->rightNode);
//	cout << root->data << " ";
//
//}
//
//
//void BinaryTree::levelOrderTraversel(Node* root) {
//
//	queue<Node*> q;
//	q.push(root);
//
//	while (!q.empty()) {
//
//		Node* currNode = q.front();
//		q.pop();
//		cout << currNode->data << " ";
//		if (currNode->leftNode) q.push(currNode->leftNode);
//		if (currNode->rightNode) q.push(currNode->rightNode);
//
//		}
//	
//} 
//
//
//int countNodes(Node* root) {
//
//	if (!root) { return 0; }
//	return 1 + countNodes(root->leftNode) + countNodes(root->rightNode);
//
//}
//
//
//int countLeafNodes(Node* root) {
//
//	if (!root) return 0;
//	if (!root->leftNode && !root->rightNode) return 1;
//	return countLeafNodes(root->leftNode) + countLeafNodes(root->rightNode);
//}
//
//
//int sumOfNodes(Node* root) {
//
//	if (!root) { return 0; }
//	return root->data + sumOfNodes(root->leftNode) + sumOfNodes(root->rightNode);
//
//}
//
//
//int heightOfTree(Node* root) {
//
//	if (!root) {
//		return 0; // counting the height based on nodes
//		// return -1; counting the height based on edges
//	}
//	
//	int leftHeight = heightOfTree(root->leftNode);
//	int rightHeight = heightOfTree(root->rightNode);
//
//	if (leftHeight > rightHeight) return 1 + leftHeight;
//	else return 1 + rightHeight;
//
//}
//
//
//bool isIdentical(Node* root, Node* subroot) {
//
//	if (!root && !subroot) return true;       // dono null ? identical
//	if (!root || !subroot) return false;      // ek null ? not identical
//	if (root->data != subroot->data) return false;
//
//	return isIdentical(root->leftNode, subroot->leftNode) &&
//		isIdentical(root->rightNode, subroot->rightNode);
//}
//
//bool isSubtree(Node* root, Node* subRoot) {
//
//	if (!subRoot) return true;   // empty tree is subtree
//	if (!root) return false;
//
//	if (isIdentical(root, subRoot)) return true;
//
//	return isSubtree(root->leftNode, subRoot) ||
//		isSubtree(root->rightNode, subRoot);
//}
//
//
//
//Node* deleteNode(Node* root, int val) {
//
//	if (!root) return false;
//
//	//leaf node
//	if (!root->leftNode && !root->rightNode) {
//
//		delete root;
//		root = nullptr;
//	}
//
//	//single child node at right
//	if (!root->leftNode) {
//
//		Node* temp = root;
//		root = root->rightNode;
//		delete temp;
//	}
//
//	//single child node at left
//	if (!root->rightNode) {
//
//		Node* temp = root;
//		root = root->leftNode;
//		delete temp;
//	}
//
//	//two child nodes
//	else {
//
//		Node* temp = min(root->rightNode);
//		root->data = temp->data;
//		root->rightNode = deleteNode(root->rightNode, temp->data);
//	}
//	return root;
//}
//
//
//int main() {
//
//	int size = 0;
//	int node[SIZE] = { 1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1 };
//	BinaryTree* tree = new BinaryTree();
//	Node* root = tree->buildTree(node);
//	tree->index = -1;
//	tree->inorder(root);
//
//
//}