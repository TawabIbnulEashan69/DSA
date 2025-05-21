#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insertAtHead(int value) {
        Node* newNode = new Node{value, nullptr, head};
        if (head) head->prev = newNode;
        head = newNode;
    }

    void insertAtTail(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteNode(int value) {
        Node* temp = head;
        while (temp && temp->data != value) temp = temp->next;
        if (!temp) return;
        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        if (temp == head) head = temp->next;
        delete temp;
    }

    void displayForward() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayBackward() {
        Node* temp = head;
        if (!temp) return;
        while (temp->next) temp = temp->next;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtHead(10);
    dll.insertAtHead(20);
    dll.insertAtTail(30);
    dll.displayForward();
    dll.displayBackward();
    dll.deleteNode(20);
    dll.displayForward();
    return 0;
}