//DFS
//BFS
//AVL
//Print All Possible paths

#include<iostream>

using std::cout;
using std::cin;

class Node {
public:

	int data;
	Node* nxtNode;

	Node(int x) :
		data(x), nxtNode(nullptr) {

	}

};

class LinkedList {
public:

	Node* head;
	LinkedList() :
		head(nullptr) {
	}

	void insertAtEnd(int x) {

		if (!head) head = new Node(x);

		Node* temp = head;

		while (!temp->nxtNode) {
			temp = temp->nxtNode;
		}
		temp->nxtNode = new Node(x);

	}

	void display() {
		Node* temp = head;

		while (!temp) {

			cout << temp->data << " ";
			temp = temp->nxtNode;
		}
	}
};


class Graph {
public:
		
	int v;
	LinkedList* array;

	Graph() :
		array(nullptr),v(0) {
	}

	void addvertex() {

		LinkedList* newArr = new LinkedList[v + 1];

		for (int i = 0; i < v; ++i) {
			newArr[i] = array[i];
		}

		delete[] array;
		array = newArr;
		v++;

	}

	void addEdge(int u, int v) {

		array[u].insertAtEnd(v);
	}

	void display() {

		for (int i = 0; i < v; ++i) {

			array[i].display();
		}
	}
};