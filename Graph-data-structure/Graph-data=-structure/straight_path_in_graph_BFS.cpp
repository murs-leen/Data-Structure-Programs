#include<iostream>
using namespace std;

#define CAPACITY 100

class Queue {

private:

	int data[CAPACITY];
	int front, rear, size;

public:

	Queue() :
		front(0), rear(0), size(0) {

		for (int i = 0; i < CAPACITY; ++i)
			data[i] = -1;

	}

	bool isFull() { return size == CAPACITY - 1; }
	bool isEmpty() { return size == 0; }
	int _front() { return data[front]; }

	void enqueue(int x) {

		if (isFull()) return;

		data[rear] = x;
		rear = (rear + 1) % CAPACITY;
		size++;

	}

	void dequeue() {

		if (isEmpty()) return;

		front = (front + 1) % CAPACITY;
		size--;
	}


};

class Adjacency_Matrix {

private:

	int** matrix;
	int vertices;

public:

	Adjacency_Matrix() :
		matrix(nullptr), vertices(0) {
	}

	void addVertex();
	void addEdge(int, int);
	void display();
	void BFS(int,int);
	void DFS();

};


void Adjacency_Matrix::addVertex() {

	int** newMatrix = new int* [vertices + 1];

	for (int i = 0; i < vertices + 1; ++i) {

		newMatrix[i] = new int[vertices + 1];

	}

	//copy old data
	for (int j = 0; j < vertices; ++j) {
		for (int k = 0; k < vertices; ++k) {

			newMatrix[j][k] = matrix[j][k];
		}
	}

	//initializing new row-col nodes to zero
	for (int k = 0; k < vertices + 1; ++k) {

		newMatrix[k][vertices] = 0;
		newMatrix[vertices][k] = 0;

	}


	for (int i = 0; i < vertices; ++i) {

		delete[] matrix[i];
	}
	delete[] matrix;

	vertices++;
	matrix = newMatrix;

}


void Adjacency_Matrix::addEdge(int x, int y) {

	if (x < 0 || x > vertices - 1 ||
		y < 0 || y > vertices - 1) return;

	if (matrix[x][y] == 1 && matrix[y][x] == 1) {

		cout << "These nodes already have connection\n";
		return;
	}

	matrix[x][y] = 1;
}


void Adjacency_Matrix::display() {

	char ch = 'A';

	cout << "Adjacent Matrix:\n";

	cout << "---";
	for (int i = 0; i < vertices; ++i)
		cout << ch++ << " ";

	ch = 'A';
	cout << endl;

	for (int i = 0; i < vertices; ++i) {

		cout << ch << ": ";

		for (int j = 0; j < vertices; ++j) {

			cout << matrix[i][j] << " ";
		}

		ch++;
		cout << endl;
	}

}

void Adjacency_Matrix::BFS(int start, int goal) {

	if (start < 0 || start > vertices - 1) return;

	bool* visited = new bool[vertices];
	int* parents = new int[vertices];

	for (int i = 0; i < vertices; ++i) {

		visited[i] = false;
		parents[i] = -1;
	}

	Queue q;
	q.enqueue(start);
	visited[start] = true;

	while (!q.isEmpty()) {

		int curr = q._front();
		q.dequeue();

		if (curr == goal) break;

		for (int i = 0; i < vertices; ++i) {
			if (matrix[curr][i] > 0 && !visited[i]) {

				visited[i] = true;
				q.enqueue(i);
				parents[i] = curr;
			}
		}
	}

	// --- PROBLEM 1: Check if goal was actually reached ---


	if (!visited[goal]) {

		cout << "Goal tak koi rasta nahi mila!" << endl;
	}

	else {

		// --- PROBLEM 2: Store and Print Path ---

		int path[100];
		int idx = 0;

		for (int v = goal; v != -1; v = parents[v]) {

			path[idx++] = v;
		}

		char nodeName = 'A';
		// Seedha Print karo (Start se Goal tak)

		cout << "Final Path: ";
		for (int i = idx - 1; i >= 0; i--) {

			cout << (char)(nodeName + path[i]);
			if (i > 0) cout << " -> ";
		}
		cout << endl;
	}

	// --- PROBLEM 3: Free Memory ---
	delete[] visited;
	delete[] parents;

}



int main() {

	Adjacency_Matrix graph;

	graph.addVertex();
	graph.addVertex();
	graph.addVertex();
	graph.addVertex();
	graph.addVertex();
	graph.addVertex();
	graph.addVertex();
	graph.addVertex();
	graph.addVertex();
	graph.addVertex();
	graph.addVertex();
	graph.addVertex();
	graph.addVertex();


	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(1, 3);
	graph.addEdge(1, 4);
	graph.addEdge(2, 5);
	graph.addEdge(3, 6);
	graph.addEdge(4, 7);
	graph.addEdge(4, 8);
	graph.addEdge(5, 9);
	graph.addEdge(6, 10);
	graph.addEdge(6, 11);
	graph.addEdge(8, 12);

	graph.display();
	cout << endl;
	graph.BFS(0,9);
    return 0;
    
}