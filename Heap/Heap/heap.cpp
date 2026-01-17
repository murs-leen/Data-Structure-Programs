// heap is a Complete Binary Tree
// we use array instead of linked list for implementation
// all basic operations of heap (max)
// min heap to max heap
// max to min heap

#include<iostream>
using namespace std;

#define MAX_SIZE 10


void swap(int& a, int& b) {

	int temp = a;
	a = b;
	b = temp;
}


void heapifyUp(int* arr, int size) {

	int i = size;
	while (i > 0 && arr[(i - 1) / 2] > arr[i]) {

		swap(arr[(i - 1) / 2], arr[i]);
		i = (i - 1) / 2;
	}
}


void insert(int& size, int* arr, int data) {

	if (size == MAX_SIZE) {

		cout << "Heap overflow\n";
		return;
	}
	arr[size] = data;
	cout << endl;
	cout << data << " inserted in heap\n";
	heapifyUp(arr,size);
	size++;
}

void heapifyDown(int index, int size, int* arr) {

	int left = 2 * index + 1;
	int right = 2 * index + 2;

	int largest = index;

	// Check left child
	if (left < size && arr[left] < arr[largest])
		largest = left;

	// Check right child
	if (right < size && arr[right] < arr[largest])
		largest = right;

	// If largest is not the parent, swap and continue
	if (largest != index) {

		swap(arr[index], arr[largest]);
		heapifyDown(largest, size, arr);
	}
}

void deleteVal(int* arr, int& size) {

	if (size == 0) {
		cout << "Heap is empty!\n";
		return;
	}

	arr[0] = arr[size - 1];
	size--;
	heapifyDown(0,size,arr);
}

void display(int* arr, int size) {

	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
}



int main() {

	int size = 0;
	int heapArray[MAX_SIZE];
	insert(size, heapArray, 15);
	insert(size, heapArray, 20);
	insert(size, heapArray, 18);
	insert(size, heapArray, 10);
	insert(size, heapArray, 25);
	insert(size, heapArray, 30);

	cout << "Before: ";
	display(heapArray, size);
	cout << endl;
	deleteVal(heapArray, size);
	cout << "\nAfter: ";
	display(heapArray, size);

}