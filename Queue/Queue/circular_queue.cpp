#include<iostream>
using namespace std;

#define SIZE 3
int front = 0;
int rear = -1;
int arr[SIZE];
int capacity = 0;


int _front() {
	return arr[front];
}

bool isEmpty() {

	return capacity == 0;

}


bool isFull() {

	return capacity == SIZE;

}


void enqueue(int data) {

	if (isFull()) {
		cout << "Queue is full\n";
		return;
	}

	rear = (rear + 1) % SIZE;
	arr[rear] = data;
	capacity++;
}


void dequeue() {

	if (isEmpty()) 
		return;	
	
	front = (front + 1) % SIZE;
	capacity--;

}


void print() {

	if (isEmpty()) {

		cout << "Empty\n";
		return;
	}

	while (!isEmpty()) {
		cout << arr[front] << " ";
		dequeue();
	}
	cout << endl;

}


int main() {

	enqueue(2);
	enqueue(4);
	enqueue(6);

	dequeue();
	enqueue(10);
	//print();
	dequeue();
	print();

}