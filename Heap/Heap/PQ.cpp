//Priorty Queue
// array based
#include<iostream>
using std::cout;
using std::cin;

#define MAX_SIZE 100
class Queue {
public:

	int size;
	int arr[MAX_SIZE];

	Queue() : size(0) {

		for (int i = 0; i < MAX_SIZE; ++i) arr[i] = 0;

	}
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_SIZE; }
	int top() { return arr[0]; }

	void dequeue() {

		if (isEmpty()) { return; }

		//right shifting
		for (int i = 0; i < size - 1; ++i) {
			arr[i] = arr[i + 1];
		}

		size--;
	}

	void enqueue(int x) {

		if (isFull()) { return; }

		int i = size - 1;
		//left shifting
		for (; i >= 0 && arr[i] > x; --i) {

			arr[i + 1] = arr[i];
		}
		arr[i + 1] = x;
		size++;
	}

	void display() {

		for (int i = 0; i < size; ++i) {
			cout << arr[i] << " ";
		}
	}

};

int main() {

	Queue pq;
	pq.enqueue(10);
	pq.enqueue(15);
	pq.enqueue(40);
	pq.enqueue(9);
    std::cout << "Priority Queue: ";
    pq.display();
	pq.dequeue();
	pq.display();
}