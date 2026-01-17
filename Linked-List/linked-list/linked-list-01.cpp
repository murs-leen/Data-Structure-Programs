//Linked List 
// Insertion at start of the list (backward list)

#include <iostream>
using namespace std;


class Node {
public:

   int data; // to store data 
   Node* nxtNodeList; // to store the address of next node

   Node(int val) : data(val), nxtNodeList(nullptr) {}

};


class Linked_List {
public:

   Node* head; 
   Linked_List() : head(nullptr) {}

   void insertAtStart(int x);
   void printNodeList();
   ~Linked_List(); // Destructor to free memory

};


void Linked_List::insertAtStart(int x) {

   //Head -> existing first Node ->....n
 
   Node* newNode = new Node(x); // creating new Node
   newNode->nxtNodeList = head; // pointing new Node to the existing first Node
   head = newNode; // pointing head to the newly created Node

   // Head -> newNode -> existing first Node ->....n
}


void Linked_List::printNodeList() {

   Node* temp = head;
   cout << "\nList: ";

   while (temp != nullptr) {
       cout << temp->data << " ";
       temp = temp->nxtNodeList;
   }
   cout << "\n";

}


Linked_List::~Linked_List() {

   Node* current = head;

   while (current != nullptr) {

       Node* next = current->nxtNodeList;
       delete current;
       current = next;
   }

   head = nullptr;

}


int main() {

   Linked_List list;
   int num, val;

   cout << "How many numbers you want to add: ";
   cin >> num;
	  cout <<"Backward list" << endl;
   for (int i = 0; i < num; ++i) {

       cout << "Enter number " << i + 1 << ": ";
       cin >> val;
       list.insertAtStart(val);
       list.printNodeList();

   }
   
   return 0;

}