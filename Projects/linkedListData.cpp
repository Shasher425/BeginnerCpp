#include <iostream>
 
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList();
    ~LinkedList();

    void insert(int data);
    void remove(int data);
    void display();
    int length();
};

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void LinkedList::insert(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void LinkedList::remove(int data) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current != nullptr) {
        if (prev != nullptr)
            prev->next = current->next;
        else
            head = current->next;

        delete current;
    }
}

void LinkedList::display() {
    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }

    cout << "nullptr" << std::endl;
}

int LinkedList::length() {
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

int main() {
    LinkedList myList;

    char choice;
    do {
        int data;
        cout << "Enter the data to insert: ";
        cin >> data;
        myList.insert(data);

        cout << "Do you want to insert more elements? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Linked List: ";
    myList.display();

    cout << "Length of the list: " << myList.length() << std::endl;

    do {
        int data;
        cout << "Enter the data to remove: ";
        cin >> data;
        myList.remove(data);

        cout << "Do you want to remove more elements? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Linked List after removing elements: ";
    myList.display();

    return 0;
}
