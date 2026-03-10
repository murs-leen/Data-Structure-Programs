////Linked-List
////Insertion at end of the list(forward list)
//
//
//#include<iostream>
//using namespace std;
//
//class Node {
//
//public:
//	int data;
//	Node* nextNodeLink;
//
//	Node(int val) : data(val), nextNodeLink(nullptr) {};
//
//};
//
//
//class Linked_List {
//	  
//public:
//	Node* head;
//	Node* tail;
//	Linked_List() : head(nullptr),tail(nullptr) {};
//	void insertAtTail(int x);
//	void printNodeList();
//};
//
//void Linked_List::printNodeList() {
//
//	Node* temp = head;
//	cout << "\nList: ";
//
//	while (temp != nullptr) {
//		cout << temp->data << " ";
//		temp = temp->nextNodeLink;
//	}
//	cout << "\n";
//
//}
//
//
//void Linked_List::insertAtTail(int x) {
//
//	Node* temp = new Node(x);
//
//	if (head == nullptr) { // if no node created yet, then point head and tail to the newly created node
//
//		head = temp;
//		tail = temp;
//	} 
//	else
//	{
//		tail->nextNodeLink = temp; // link 2nd last node to the last newly created node
//		tail = temp; // redefine the link of tail to the latest last node
//	}
//
//}
//
//
//int main() {
//
//	Linked_List list;
//	int num, val;
//
//	cout << "How many numbers you want to add: ";
//	cin >> num;
//	cout << "Forward List:\n";
//	for (int i = 0; i < num; ++i) {
//
//		cout << "Enter number " << i + 1 << ": ";
//		cin >> val;
//		list.insertAtTail(val);
//		list.printNodeList();
//
//	}
//	return 0;
//
//}
