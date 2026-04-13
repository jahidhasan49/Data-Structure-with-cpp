#include <iostream>
using namespace std;

int stack[5]; 
int top = -1;

void push() {
    int value;
    if (top == 4) { 
        cout << "Stack is Overflow!" << endl;
    }
    else {
        cout << "Enter value: ";
        cin >> value;
        top++;
        stack[top] = value;
        cout << "Pushed successfully!" << endl;
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack is Underflow!" << endl;
    }
    else {
        cout << "Popped value: " << stack[top] << endl;
        top--;
    }
}

void show() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
    }
    else {
        cout << "Stack elements: ";
        for (int i=top; i>=0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "STACK MENU: " << endl;
        cout << "1. Push\n2. Pop\n3. show\n4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: show(); break;
            case 4: cout << "Exiting.." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

}