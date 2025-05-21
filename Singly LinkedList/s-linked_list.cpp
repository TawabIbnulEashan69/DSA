#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


class LinkedList {
    Node* head;

public:

    LinkedList() {
        head = NULL;
    }

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }


        temp->next = newNode;
    }


    void display() {

        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        cout << "List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }


    void deleteNode(int value) {

        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << value << " deleted" << endl;
            return;
        }

        Node* current = head;
        Node* previous = NULL;
        while (current != NULL && current->data != value) {
            previous = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << value << " not found" << endl;
            return;
        }

        previous->next = current->next;
        delete current;
        cout << value << " deleted" << endl;
    }
};

int main() {

    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);

    list.display();

    list.deleteNode(20);

    list.display();


    list.deleteNode(50);

    return 0;
}