#include<iostream>
using std::cout;
using std::cin;

#define MAX 10

struct Student {
	int priority;
	int data;

};


class PriorityQueue {

private:
	int front, rear, size;
	Student arr[MAX];

public:
	PriorityQueue() :
		front(0), rear(-1), size(0) {
	}

	bool isFull() { return size == MAX; }
	bool isEmpty() { return size == 0; }

	Student _front() { return arr[front]; }

	Student dequeue() {

		if (isEmpty()) {
			return { -1, -1 };
		}

		Student top = arr[0]; // Take the highest priority element

		// Shift everything left to fill the gap (if maintaining order at the start)
		for (int i = 0; i < size - 1; i++) {
			arr[i] = arr[i + 1];
		}

		rear--;
		size--;
		return top;
	}


	void enqueue(const Student& other) {
		if (isFull()) return;

		int i = size - 1;
		// Shift elements to the right until we find the correct position
		// Note: Comparing priority, not data
		while (i >= 0 && arr[i].priority > other.priority) {
			arr[i + 1] = arr[i];
			i--;
		}

		arr[i + 1] = other;
		rear++;
		size++;
	}

	void display() {

		cout << "Data | Priority\n";
		for (int i = front; i <= rear; ++i) {

			cout << arr[i].data << "\t" << arr[i].priority << std::endl;

		}

	}
};


int main() {

	Student st1, st2, st3, st4;
	st1.data = 40;
	st1.priority = 1;
	st2.data = 90;
	st2.priority = 3;
	st3.data = 49;
	st3.priority = 5;
	st4.data = 10;
	st4.priority = 1;

	PriorityQueue pq;
	pq.enqueue(st1);
	pq.enqueue(st4);
	pq.enqueue(st3);
	pq.enqueue(st2);
	pq.display();
	pq.dequeue();
	pq.display();
}