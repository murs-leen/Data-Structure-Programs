#include<iostream>
#include<stack>
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

public:

	int** matrix;
	int vertices;

	Adjacency_Matrix() :
		matrix(nullptr), vertices(0) {
	}

	void addVertex();
	void addEdge(int, int);
	void display();
	void BFS(int);
	void DFS(int, bool*);										

};




void Adjacency_Matrix::addVertex() {

	int** newMatrix = new int*[vertices + 1];

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
	matrix[y][x] = 1;

}


void Adjacency_Matrix::display() {
	
	char ch = 'A';

	cout << "Adjacent Matrix:\n";

	cout << "---";
	for (int i = 0; i < vertices; ++i)
		cout  << ch++ <<" ";

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


void Adjacency_Matrix::BFS(int start) {

	if (start < 0 || start > vertices - 1) return;

	bool* visited = new bool[vertices];

	for (int i = 0; i < vertices; ++i) {
		visited[i] = false;
	}

	cout << "BFS: ";
	Queue q;
	q.enqueue(start);
	visited[start] = true;

	while (!q.isEmpty()) {

		int curr = q._front();
		q.dequeue();
		cout << curr << " ";
	
		for (int i = 0; i < vertices; ++i) {

			if (matrix[curr][i] > 0 && !visited[i]) {

				visited[i] = true;
				q.enqueue(i);

			}
		}
	}

	delete[] visited;

}


//recursive(DFS)

void Adjacency_Matrix::DFS(int start, bool visited[]) {

	visited[start] = true;
	cout << start << " ";

	for (int i = 0; i < vertices; ++i) {

		if (matrix[start][i] == 1 && !visited[i])
			DFS(i, visited);
	}
}


//DFS-stack

void _DFS(Adjacency_Matrix& g, int start) {

	bool visited[7] = { false };
	std::stack<int> st;
	st.push(start);
	visited[start] = true;

	while (!st.empty()) {

		int curr = st.top();
		st.pop();
		cout << curr << " ";

		for (int i = 0; i < g.vertices; ++i) {

			if (g.matrix[curr][i] == 1 && !visited[i]) {

				st.push(i);
				visited[i] = true;
			}
		}

	}
		 

}

int main() {

	Adjacency_Matrix graph;

	graph.addVertex(); // 0
	graph.addVertex(); // 1
	graph.addVertex(); // 2
	graph.addVertex(); // 3
	graph.addVertex(); // 4
	graph.addVertex(); // 5
	graph.addVertex(); // 6



	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(1, 3);
	graph.addEdge(2, 4);
	graph.addEdge(3, 5);
	graph.addEdge(3, 4);
	graph.addEdge(4, 5);
	graph.addEdge(5, 6);

	graph.display();
	cout << endl;
	graph.BFS(0);
	bool visited[7] = { false };
	int start = 0;
	cout << "\nDFS: ";
	graph.DFS(start, visited);

	cout << "\nDFS<stack>: ";
    std::cout << endl;
	_DFS(graph, 0);
    std::cout << endl;
    return 0;
}