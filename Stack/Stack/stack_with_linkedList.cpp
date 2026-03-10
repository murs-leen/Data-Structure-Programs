#include<iostream>
using namespace std;


class Node {
public:

	int data;
	Node* nxtNode;

	Node(int x) : data(x), nxtNode(nullptr) {}

};

class Stack {
public:

	Node* head;

	Stack() :head(nullptr) {};
	void push(int x);
	void pop();
	int top();
	bool isEmpty();

};


void Stack::push(int x) {

	Node* newNode = new Node(x);
	newNode->nxtNode = head;
	head = newNode;

}

void Stack::pop() {

	if (isEmpty()) {

		cout << "Stack is empty!\n";
		return;
	}

	Node* temp = head;
	head = head->nxtNode;
	delete temp;

}

int Stack::top() {

	if (isEmpty())
		return -1;

	return head->data;

}


bool Stack::isEmpty() {

	return (head == nullptr);
}