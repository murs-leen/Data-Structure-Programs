#include<iostream>
using namespace std;


class Node {

public:

	int data;
	Node* nxtNode;

	Node(int x) :nxtNode(nullptr), data(x) {};
};


class LinkedList {

public:

	Node* head;
	Node* tail;

	LinkedList() :head(nullptr), tail(nullptr) {};

	void insertAtStart(int x);
	void insertAtEnd(int x);
	void insertAtIndex(int x, int idx);
	void deleteFromStart();
	void deleteFromEnd();

	void display()const {

		Node* temp = head;

		cout << "\nList is:";
		while (temp != nullptr) {
			
			cout << temp->data << " ";
			temp = temp->nxtNode;
		}

	}
};


void LinkedList::insertAtStart(int x) {

	Node* newNode = new Node(x);

	if (head == nullptr) {
		tail = newNode;
	}
	newNode->nxtNode = head;
	head = newNode;

}

 
void LinkedList::insertAtEnd(int x) {

	Node* newNode = new Node(x);
	
	if (head == nullptr) {

		head = tail = newNode;
	}
	else {

		tail->nxtNode = newNode;
		tail = newNode;
	}

}


void LinkedList::deleteFromStart() {

	if (head == nullptr) {

		cout << "List is already empty!\n";
		return;
	}

	Node* temp = head;
	head = head->nxtNode;
	delete temp;

	if (head == nullptr) {

		tail = nullptr;
	}

}


void LinkedList::deleteFromEnd() {

	if (head == nullptr) {

		cout << "List is already empty!\n";
		return;
	}
	Node* temp = head;

	while (temp->nxtNode != tail) {
		temp = temp->nxtNode;
	}
}

int main() {

	LinkedList list;
	cout << "Inserted at start: ";
	list.insertAtStart(1);
	list.display();
	cout << "\nInserted at end:";
	list.insertAtEnd(2);
	list.display();
	cout << "\nInserted at end:";
	list.insertAtEnd(4);
	list.display();
	cout << "\nInserted at start: ";
	list.insertAtStart(0);
	list.display();
	cout << " \n0-deleted:";
	list.deleteFromStart();
	list.display();


	cout << " \n1-deleted:";
	list.deleteFromStart();
	list.display();

}