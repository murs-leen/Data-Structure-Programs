////Linked List
////Insertion at index
//
//#include<iostream>
//using namespace std;
//
//class Node {
//
//public:
//
//	int data, length;
//	Node* nxtNode;
//
//	Node(int x) : data(x), nxtNode(nullptr),length(0) {};
//
//};
//
//
//class LinkedList {
//
//public:
//
//	Node* head;
//
//	LinkedList() :head(nullptr){};
//
//	void insertAtStart(int);
//	void insertAtIndex(int, int);
//	void display()const;
//
//};
//
//
//void LinkedList::insertAtStart(int x) {
//
//    //Head -> existing first Node ->....n
//  
//    Node* newNode = new Node(x); // creating new Node
//    newNode->nxtNode = head; // pointing new Node to the existing first Node
//    head = newNode; // pointing head to the newly created Node
//
//    // Head -> newNode -> existing first Node ->....n
//}
//
//void LinkedList::insertAtIndex(int x, int idx) {
//
//	
//	if (idx == 1) {
//
//		insertAtStart(x);
//		return;
//	}
//
//	Node* newNode = new Node(x);
//	Node* p = head;
//
//	for (int i = 0; i < idx - 2; ++i)  // to reach at n-1 node (n is the index where we have to insert our new node)
//		p = p->nxtNode;
//	 
//	newNode->nxtNode = p->nxtNode; // n - 1 node contains the address of n node
//	p->nxtNode = newNode;
//
//}
//
//
//void LinkedList::display()const {
//
//	Node* temp = head;
//
//	cout << "List is: ";
//	while (temp != nullptr) {
//
//		cout << temp->data << " ";
//		temp = temp->nxtNode;
//	}
//	cout << endl;
//}
//
//
//int main() {
//
//	LinkedList list;
//	list.insertAtIndex(1, 1);
//	list.display();
//	list.insertAtIndex(3, 2);
//	list.display();
//	list.insertAtIndex(5, 2);
//	list.display();
//	list.insertAtIndex(7, 1);
//	list.display();
//
//}