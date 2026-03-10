#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* nxtNode;

    Node(int x) : data(x), nxtNode(nullptr) {};
};

class LinkedList {
public:
    int size;
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr), size(0) {};

    void insertAtStart(int x);
    void insertAtEnd(int x);
    void deleteFromStart();
    void deleteFromEnd();
    void display();
};

void LinkedList::insertAtStart(int x) {
    Node* newNode = new Node(x);
    newNode->nxtNode = head;
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
    size++;
}

void LinkedList::insertAtEnd(int x) {
    Node* newNode = new Node(x);
    if (head == nullptr) {
        head = tail = newNode;
        size++;
        return;
    }
    tail->nxtNode = newNode;
    tail = newNode;
    size++;
}

void LinkedList::deleteFromStart() {
    if (head == nullptr) {
        cout << "List is empty already!\n";
        return;
    }
    Node* temp = head;
    head = head->nxtNode;
    delete temp;
    size--;
    if (head == nullptr) {
        tail = nullptr;
    }
}

void LinkedList::deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty already!\n";
        return;
    }
    else if (head->nxtNode == nullptr) {
        delete head;
        tail = head = nullptr;
        size--;
    }
    else {
        Node* temp = head;
        for (int i = 0; i < size - 2; ++i) {
            temp = temp->nxtNode;
        }
        delete temp->nxtNode;      // free last node
        temp->nxtNode = nullptr;
        tail = temp;
        size--;
    }
}

void LinkedList::display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->nxtNode;
    }
    cout << "NULL\n";
}

int main() {
    LinkedList list;

    // Insert at start
    list.insertAtStart(10);
    list.insertAtStart(20);
    list.insertAtStart(30);
    cout << "After insertAtStart: ";
    list.display();

    // Insert at end
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    cout << "After insertAtEnd: ";
    list.display();

    // Delete from start
    list.deleteFromStart();
    cout << "After deleteFromStart: ";
    list.display();

    // Delete from end
    list.deleteFromEnd();
    cout << "After deleteFromEnd: ";
    list.display();

    return 0;
}
