#include<iostream>
using namespace std;

const int n_size = 20;
int stack[n_size];
int top = -1;

void push(int data) {
    if (top == n_size - 1) {
        cout << "Stack is Full" << endl;
    } else {
        top++;
        stack[top] = data;
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Popped element: " << stack[top] << endl;
        top--;
    }
}

void peek() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "The top element is: " << stack[top] << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int data;
        cout << "Enter the data: ";
        cin >> data;
        push(data);
    }

    cout << "Elements of the stack:" << endl;
    for (int i = top; i >= 0; i--) {
        cout << "Element: " << stack[i] << endl;
    }

    pop();

    cout << "Elements after pop:" << endl;
    for (int i = top; i >= 0; i--) {
        cout << "Element: " << stack[i] << endl;
    }

    peek();

    return 0;
}
