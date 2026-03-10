#include<iostream>
using namespace std;

class Node {

public:
	int data;
	Node* nxt;
	Node(int x) : data(x), nxt(nullptr) {};

};

class LL {
	
public:
	Node* head;
	Node* tail;
	LL() :head(nullptr), tail(nullptr) {};

	void insertAtStart(int x) {

		Node* newNode = new Node(x);
		if (head == nullptr) {
			head = tail = newNode;
			tail->nxt = head;
		}
		else {

			newNode->nxt = head;
			head = newNode;
			tail->nxt = head;

		}

	}

	void atEnd(int x) {

		Node* newNode = new Node(x);
		if (head == nullptr) {
			head = tail = newNode;
			tail->nxt = head;
		}
		else {

			tail->nxt = newNode;
			tail = newNode;
			tail->nxt = head;

		}

	}

	void deleteS() {

		if (head == nullptr)
			cout << "Empty";

		else if (head == tail) {
			delete head;
			head = tail = nullptr;
		}
		else {

			Node* p = head;
			head = head->nxt;
			delete p;
			tail->nxt = head;
		}
	}

	void deletEnd() {

		if (head == nullptr)
			cout << "Empty";

		else if (head == tail) {
			delete head;
			head = tail = nullptr;
		}
		else {

			Node* temp = head;
			while (temp->nxt != tail) {
				temp = temp->nxt;
			}
			temp->nxt = head;
			delete tail;
			tail = temp;
		}
	}
};