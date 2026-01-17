//#include<iostream>
//using namespace std;
//
//void bubbleSort(int* arr, int size) {
//
//	for (int i = 0; i < size - 1; ++i) {
//		for (int j = 0; j < size - i - 1; ++j) {
//			if (arr[j] >= arr[j + 1]) {
//				swap(arr[j], arr[j + 1]);
//			}
//		}
//	}
//}
//
//void removeDuplicates(int* arr, int size) {
//
//		for (int j = 0; j < size - 1; ++j) {
//
//			if (arr[j] == arr[j + 1]) {
//
//				for(int k = j; k < size - 1; k++)
//					arr[k] = arr[k + 1];
//			size--;
//			j--;
//			}
//		}
//}
//
//int findMissing(int* arr, int size) {
//
//	int missingNum = arr[0];
//
//	for (int i = 1; i < size; ++i) {
//
//		if (arr[i] != ++missingNum) return missingNum;
//	}
//	return -1;
//}
