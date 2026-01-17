//max to min / min to max :(heap)
// last non-leaf node sey start kro aur heapify down kro

#include<iostream>
using std::cout;
using std::cin;


void maxHeapify(int index, int* arr, int n) {

	int left = 2 * index + 1;
	int right = 2 * index + 2;

	int largest = index;

	if (left < n && arr[left] > arr[largest]) {

		largest = left;
	}
	if (right < n && arr[right] > arr[largest]) {

		largest = right;
	}

	if (largest != index) {

		std::swap(arr[largest], arr[index]);
		maxHeapify(largest, arr, n);
	}

}


void convertMinToMax(int n, int* arr) {

	for (int i = n / 2 - 1; i >= 0; ++i) {

		maxHeapify(i, arr,n);
	}
}