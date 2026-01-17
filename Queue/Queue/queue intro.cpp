//Queue introduction


// Implementation-Array based
// Queue is the same as its name says
// Enqueue :Elms are instered into the queue at the end (tail/rear)
// Dequeue :Elms are deleted from the front(head)
// All operations in queue takes O(1) time complexity(constant time complexity)



#include<iostream>
using namespace std;

#define SIZE 10

int front = -1;
int rear = -1;
int arr[SIZE];

bool isFull() {

	if (rear == SIZE - 1)
		return true;
	return false;

}


bool isEmpty() {

	if (front == -1 && rear == -1)
		return true;
	return false;

}


void enqueue(int x) {

	if (isFull()) {

		cout << "Queue is full!\n";
		return;
	}
	if (isEmpty()) {

		front++;rear++;
		arr[rear] = x;
	}
	else {

		arr[++rear] = x;

	}
}


void dequeue() {

	if (isEmpty()) {

		cout << "Queue is empty!\n";
		return;
	}
	if (front == rear)
	{
		front = rear = -1;
	}
	else
		front++;

}


void display() {

	if (isEmpty())
	{
		cout << "Empyt\n";
		return;
	}
	cout << "Queue: ";
	for (int i = front; i <= rear; ++i) {

		cout << arr[i] << " ";
	}

}


int main() {


}