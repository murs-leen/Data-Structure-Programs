//Stack- implementation with array

// 1- push() -- inserting into stack
// 2- pop() -- removing from stack
//3- top() -- will return top value
//4- isEmpty()
// Time compelxity for all above operations is O(1) - constant

#include<iostream>
#include<stack>
using namespace std;

const int maxSize = 10;;
int arr[maxSize];
int top = -1;

bool isempty() {
	 
	return (top == -1);

}


void push(int x) {

	if (top < maxSize)
		arr[++top] = x;
	else
		cout << "Stack is full\n";

}


void pop() {

	if (!isempty())
		top--;
	else
		cout << "Stack is empty\n";

}


int Top() {

	return arr[top];
}


void print() {

	for (int i = 0; i < top; ++i) {
		cout << arr[i] << " ";

	}
}


int main() {

	for (int i = 0; i < 10; ++i) {

		push(i);

	}
	print();
	cout << endl;
	pop();
	print();
} 