//#include<iostream>
//using namespace std;
//const int SIZE = 50;
//class ArrayBST {
//	int arr[SIZE];
//public:
//	//constructor
//	ArrayBST() {
//		for (int i = 0; i < SIZE; ++i)
//			arr[i] = -1;
//	};
//	void insertion(int val) {
//		int i = 0;
//		//if tree is empty
//		if (arr[i] == -1) {
//			arr[i] = val;
//			cout << "Inserted " << val << " at root." << endl;
//			return;
//		}
//		while (true) {
//			//if value is small go left
//			if (val < arr[i]) {
//				int left = 2 * i + 1;
//				if (left >= SIZE) {
//					cout << "Tree is full. Cannot be inserted." << endl;
//					return;
//				}
//				if (arr[left] == -1) {
//					arr[left] = val;
//					cout << "Inserted " << val << " at index " << left << endl;
//					return;
//				}
//				else {
//					i = left;
//				}
//			}
//			//if value is large go right
//			else if (val > arr[i]) {
//				int right = 2 * i + 2;
//				if (right >= SIZE) {
//					cout << "Tree is full. Cannot be inserted." << endl;
//					return;
//				}
//				if (arr[right] == -1) {
//					arr[right] = val;
//					cout << "Inserted " << val << " at index " << right << endl;
//					return;
//				}
//				else {
//					i = right;
//				}
//			}
//			else {
//				cout << "Duplicates arent allowed!" << endl;
//				return;
//			}
//		}
//	}
//
//	//binary search
//	int search(int val) {
//		int i = 0;
//		while (i < SIZE && arr[i] != -1) {
//			if (val == arr[i]) {
//				return i;
//			}
//			else if (val < arr[i]) {
//				i = 2 * i + 1;
//			}
//			else {
//				i = 2 * i + 2;
//			}
//		}
//		return -1;
//	}
//
//	void deleteion(int v) {
//		if (search(v) != -1) {
//			arr[search(v)] = -1;
//			cout << "Deleted!" << endl;
//		}
//		else
//			cout << "Not found!" << endl;
//	}
//
//	//Printing inroder
//	void print(int v = 0) {
//		if (arr[v] == -1)
//			return;
//		print(2 * v + 1);
//		cout << arr[v] << ' ';
//		print(2 * v + 2);
//	}
//
//};
//void menu() {
//	ArrayBST Faizan;
//	int choice, val;
//	do {
//		cout << "\n===Menu===" << endl;
//		cout << "1. Insertion" << endl;
//		cout << "2. Deletion" << endl;
//		cout << "3. Search" << endl;
//		cout << "4. Inorder Print" << endl;
//		cout << "5. Exit" << endl;
//		cout << "Choice:";
//		cin >> choice;
//		switch (choice) {
//		case 1:
//			cout << "Enter value to insert:";
//			cin >> val;
//			Faizan.insertion(val);
//			break;
//		case 2:
//			cout << "Enter value to delete:";
//			cin >> val;
//			Faizan.deleteion(val);
//			break;
//		case 3:
//			cout << "Enter value to search:";
//			cin >> val;
//			if (Faizan.search(val) == -1)
//				cout << "Not found!" << endl;
//			else
//				cout << "Found at index " << Faizan.search(val) << endl;
//			break;
//		case 4:
//			Faizan.print();
//			break;
//		case 5:
//			cout << "Exiting..." << endl;
//		default:
//			cout << "Invalid Input!";
//		}
//		cout << endl;
//	} while (choice != 5);
//}
//int main() {
//	menu();
//	return 0;
//}