// BFS(Breath-First-Search)
// DFS(Depth-First-Search)
// All possible paths 
// cycle detection

#include<iostream>
using namespace std;

#define MAX_SIZE 100

class Stack {
public:
	int arr[MAX_SIZE],top;
	
	Stack() :
		top(-1) {
	}

	bool isFull() { return top == MAX_SIZE - 1; }

	bool isEmpty() { return top == -1; }

	void push(int x) {

		if (isFull()) return;
		arr[++top] = x;
	}

	int pop() {

		if (isEmpty()) return 0;
		return arr[top--];
	}

};


class Queue {
public:
	int f, r, s;
	int arr[MAX_SIZE];
	Queue() :
		f(0), r(0), s(0) {
	}
	bool isFull() {

		return s == MAX_SIZE;
	}
	bool isEmpty() {

		return s == 0;
	}

	void enqueue(int val) {

		if (isFull()) return;
		arr[r] = val;
		r = (r + 1) % MAX_SIZE;
		s++;

	}
	void dequeue() {

		if (isEmpty()) return;

		f = (f + 1) % MAX_SIZE;
		s--;
		
	}
	int front() {
		return arr[f];
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

	void display() {

		Node* temp = head;

		while (temp) {
			cout << temp->data << " | ";
			temp = temp->nxtNode;
		}
		cout << "null";
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
		array[v].insertAtEnd(u);

	}

	void displayGraph() {

		for (int i = 0; i < vertices; i++) {
			cout << i << " -> ";
			array[i].display();
			cout << endl;
		}
	}

	// -------------- BFS -------------------

	void BFS(int start) {

		if (start < 0 || start >= vertices) {
			cout << "Invalid start vertex!\n";
			return;
		}

		bool* visited = new bool[vertices];
		for (int i = 0; i < vertices; i++)
			visited[i] = false;

		Queue q;
		q.enqueue(start);
		visited[start] = true;

		cout << "BFS: ";

		while (!q.isEmpty()) {

			int u = q.front();
			q.dequeue();
			cout << u << " ";

			// Traverse adjacency list of u
			Node* temp = array[u].head;

			while (temp != nullptr) {
				int v = temp->data;

				if (!visited[v]) {
					visited[v] = true;
					q.enqueue(v);
				}

				temp = temp->nxtNode;
			}
		}

		cout << endl;
		delete[] visited;
	}


	// ------ DFS (Recursive) --------

	void DFS(int start,bool visited[]) {

			visited[start] = true;
			cout << start << " ";

			Node* temp = array[start].head;
			while (temp != nullptr) {

				int v = temp->data;

				if (!visited[v]) {

					DFS(v, visited);
				}

				temp = temp->nxtNode;
			}


	}


	// ----- DFS (Stack) -------

	void DFS_stack(int start) {

		if (start < 0 || start >= vertices) {

			cout << "Invalid start vertex!\n";
			return;
		}

		bool* visited = new bool[vertices];

		for (int i = 0; i < vertices; i++)
			visited[i] = false;

		Stack st;
		st.push(start);
		visited[start] = true;

		while (!st.isEmpty()) {

			int curr = st.pop();

			cout << curr << " ";
			Node* temp = array[curr].head;

			while (temp != nullptr) {


				if (!visited[temp->data]) {

					visited[temp->data] = true;
					st.push(temp->data);
				}
				temp = temp->nxtNode;

			}

		}
		delete[] visited;
	}



	void getAllPaths(int start, int target, bool visited[], int path[], int pathIdx) {

		// 1. Add current node to the path
		visited[start] = true;
		path[pathIdx++] = start;
		
		if (start == target) {

			cout << "Path: ";
			for (int i = 0; i < pathIdx; i++) {
				cout << path[i];
				if (i < pathIdx - 1) cout << " -> ";
			}
			cout << endl;
		}

		else {

			// 3. Recurse for neighbors
			Node* temp = array[start].head;

			while (temp != nullptr) {

				int v = temp->data;

				if (!visited[v]) {

					getAllPaths(v, target, visited, path, pathIdx);
				}

				temp = temp->nxtNode;
			}
		}

		// 4. BACKTRACK: Unmark current node so it can be used in other paths
		visited[start] = false;

		// (pathIdx decreases automatically because it was passed by value)
	}




	// -------- Cycle Detection (Undirected Graph - DFS) --------

	bool cycleDetection(bool visited[], int parent, int curr) {

		visited[curr] = true;

		Node* temp = array[curr].head;

		while (temp != nullptr) {

			int adj = temp->data;

			// If adjacent node is visited and not parent → cycle

			if (visited[adj] && adj != parent) return true;

			// If not visited → DFS call
			if (!visited[adj]) {

				if (cycleDetection(visited, curr, adj)) return true;
			}

			temp = temp->nxtNode;
		}

		return false;   
	}


};



int main() {

	Graph g;

	g.addVertex(); 
	g.addVertex();
	g.addVertex();
	g.addVertex();
	g.addVertex();
	g.addVertex();
	g.addVertex();

	g.addEdge(0, 1);
	g.addEdge(0, 2); 
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 5);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(5, 6);

	g.displayGraph();
	g.BFS(0);

	bool visited[50] = { false };/*
	cout << "DFS (recursive) : ";
	g.DFS(0, visited);*/

	cout << "\nDFS (stack): ";
	g.DFS_stack(0);

	int path[50];
	cout << "\nAll possible paths from 0 to 5: \n";
	g.getAllPaths(0, 5, visited, path, 0);

	if (g.cycleDetection( visited, -1, 0)) cout << " true\n" << endl;


}
