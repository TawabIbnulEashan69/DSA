#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* last;

public:
    CircularLinkedList() : last(nullptr) {}

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
    }

    void display() {
        if (last == nullptr) return;
        Node* temp = last->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }

    void deleteNode(int value) {
        if (last == nullptr) return;
        Node* current = last->next;
        Node* previous = last;
        do {
            if (current->data == value) {
                if (current == last) {
                    if (last->next == last) {
                        delete last;
                        last = nullptr;
                    } else {
                        previous->next = current->next;
                        last = previous;
                        delete current;
                    }
                } else {
                    previous->next = current->next;
                    delete current;
                }
                return;
            }
            previous = current;
            current = current->next;
        } while (current != last->next);
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtBeginning(5);
    cll.display();
    cll.deleteNode(20);
    cll.display();
    return 0;
}