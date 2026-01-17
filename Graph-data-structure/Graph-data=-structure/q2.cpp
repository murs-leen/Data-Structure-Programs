//Graph Representation
// Adjacency List - directed

#define MAX_SIZE 100
#include<iostream>
using namespace std;


class Queue {
private:

	int front, rear, size;
	int** data;

public:
	Queue() :
		front(0), rear(-1), size(0) {

		data = new int* [MAX_SIZE];
		for (int i = 0; i < MAX_SIZE; ++i) {

			data[i] = new int[2];
		}
	}
	bool isFull() { return size == MAX_SIZE; }
	bool isEmpty() { return size == 0; }

	void enqueue(int u, int v) {

		if (isFull()) return;

		rear = (rear + 1) % MAX_SIZE;
		data[rear][0] = u;
		data[rear][1] = v;
		size++;
	}
	
	void dequeue(int& u, int& v) {
		
		if (isEmpty()) return;

		u = data[front][0];
		v = data[front][1];
		front = (front + 1) % MAX_SIZE;
		size--;
	}

};

class Node {
public:
	
	int data;
	Node* nxtNode;

public:
	Node() {};
	Node(int x) :
		data(x), nxtNode(nullptr) {
	}

};


class Linked_List {

public:

	Node* head;

	Linked_List() : head(nullptr) {}

	void insertAtEnd(int x) {

		if (!head) {
			head = new Node(x);
			return;
		}
		Node* temp = head;

		while (temp->nxtNode != nullptr)
			temp = temp->nxtNode;

		temp->nxtNode = new Node(x);
	}


	Linked_List& operator=(const Linked_List& other) {

		if (this == &other) { return *this; }

		Node* temp = this->head;

		while (temp) {

			Node* next = temp->nxtNode;
			delete temp;
			temp = next;

		}
		head = nullptr;

		Node* curr = other.head;

		while (curr) {

			insertAtEnd(curr->data);
			curr = curr->nxtNode;

		}

		return *this;
	}


	void display() {

		Node* temp = head;

		while (temp) {
			cout << temp->data << " | ";
			temp = temp->nxtNode;
		}
		cout << "null";
	}

	~Linked_List() {

		while (head) {

			Node* temp = head;
			head = head->nxtNode;
			delete temp;
		}

	}

};


class Graph {

private:

	int vertices;
	Linked_List* array;   // ⭐ array of Linked_List

public:

	Graph() : vertices(0), array(nullptr) {}

	void addVertex() {

		Linked_List* newArr = new Linked_List[vertices + 1];

		for (int i = 0; i < vertices; i++)
			newArr[i] = array[i];

		delete[] array;
		array = newArr;

		vertices++;
	}

	void addEdge(int u, int v) {

		if (u < 0 || u >= vertices ||
			v < 0 || v >= vertices) {

			cout << "Invalid vertex!\n";
			return;
		}

		array[u].insertAtEnd(v);   // ⭐ using your linked list class

	}

	void displayGraph() {

		for (int i = 0; i < vertices; i++) {
			cout << i << " -> ";
			array[i].display();
			cout << endl;
		}
	}
};

int main() {

	Graph g;
	g.addVertex();
	g.addVertex();
	g.addVertex();

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(0, 2);
	g.displayGraph();
    return 0;

}