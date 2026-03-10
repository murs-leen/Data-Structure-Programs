#include<iostream>
using namespace std;

class Node {
public:

	int data;
	Node* nxtNode;

	Node(int x) :data(x), nxtNode(nullptr) {}

};


class Queue {
private:

	Node* head;
	Node* tail;

	Queue() :head(nullptr), tail(nullptr) {}
	void enqueue(int x);
	void dequeue();
	bool isEmpty();

};


bool Queue::isEmpty() {

	if (!head)
		return true;
	return false;
}


void Queue::enqueue(int x) {

	Node* newNode = new Node(x);

	if (isEmpty()) {
		head = tail = newNode;
		return;

	}
	tail->nxtNode = newNode;
	tail = newNode;

}


void Queue::dequeue() {

	if (isEmpty()) {
		return;
	}
	Node* temp = head;
	head = head->nxtNode;
	delete temp;

	if (head == nullptr)
		head = tail = nullptr;

}

