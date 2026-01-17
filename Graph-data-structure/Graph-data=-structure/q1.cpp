//Graph Representation
//2. Adgacency Matrix
// store edges in queue

#define MAX_SIZE 100
class Queue {
private:
	int** data;
	int front, rear, size;

public:
	
	Queue() :
		front(0), rear(-1), size(0) {

		data = new int* [MAX_SIZE];
		for (int i = 0; i < MAX_SIZE; ++i) {
			data[i] = new int[2];
		}
	}

	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_SIZE - 1; }

	void enqueue(int u, int v) {

		if (isFull()) return;

		data[rear][0] = u;
		data[rear][1] = v;
		rear = (rear + 1) % MAX_SIZE;
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

#include<iostream>
using namespace std;

class Graph {
private:

	int** matrix;
	int vertices;
public:
	Graph() :
		vertices(0), matrix(nullptr) {
	}

	//add vertex
	void addVertex() {

		vertices++;
		int** adjMatrix = new int* [vertices];
		for (int i = 0; i < vertices; ++i) {
			adjMatrix[i] = new int[vertices];
		}

		for (int i = 0; i < vertices - 1; ++i) {
			for (int j = 0; j < vertices - 1; ++j) {
				adjMatrix[i][j] = matrix[i][j];
			}
		}
		for (int i = 0; i < vertices; ++i) {
			adjMatrix[vertices - 1][i] = 0;   // fill row
			adjMatrix[i][vertices - 1] = 0;   // fill column
		}

		for (int i = 0; i < vertices - 1; ++i) {
			delete[] matrix[i];
		}
		delete[] matrix;
		matrix = adjMatrix;
	}

	// add edge
	void addEdge(int u, int v) {

		if (u < 0 || u > vertices - 1 ||
			v < 0 || v > vertices - 1) {
			cout << "Invalid vertex values!\n";
			return;
		}
		matrix[u][v] = 1;
		matrix[v][u] = 1;

	}

	//Display
	void display() {

		Queue q;
		for (int i = 0; i < vertices; ++i) {
			for (int j = 0; j < vertices; ++j) {
				cout << matrix[i][j] << " ";
				if (matrix[i][j] == 1)
					q.enqueue(i, j);
			}
			cout << endl;
		}

		cout << "Edges: \n";
		int u, v;
		while (!q.isEmpty()) {
			q.dequeue(u, v);
			if (u < v)
				cout << u << "----" << v << endl;
		}
	}

};

int main(){

	int vertices, edges;
	int weight; // for weighted graph
	cout << "Enter number of vertices: ";
	cin >> vertices;

	int** adjacencyMatrix = new int* [vertices];
	
	for (int i = 0; i < vertices; ++i) {
		adjacencyMatrix[i] = new int[vertices];
	}

	for (int i = 0; i < vertices; ++i) {
		for (int j = 0; j < vertices; ++j) {
			adjacencyMatrix[i][j] = 0;
		}
	}

	cout << "Enter number of edges:";
	cin >> edges;
	int u, v;
	for (int i = 0; i < edges; ++i) {
		cout << "Enter vertices name to build edge(e.g: 2 and 4):";
		cin >> u >> v;
		cout << "Enter weight:";
		cin >> weight;
		adjacencyMatrix[u][v] = weight;
		adjacencyMatrix[v][u] = weight; // for directed graph we dont have to write this
	}

	cout << "Adjacency Matrix: " << endl;
	for (int i = 0; i < vertices; ++i) {
		for (int j = 0; j < vertices; ++j) {
			cout << adjacencyMatrix[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "Edges:\n";
	for (int i = 0; i < vertices; ++i) {
		for (int j = 0; j < vertices; ++j) {
			if (adjacencyMatrix[i][j] != 0)
				cout << i << "-----" << j << endl;
		}
	}

    return 0;
} 

