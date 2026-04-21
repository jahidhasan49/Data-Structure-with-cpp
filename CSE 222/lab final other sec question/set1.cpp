//warehouse management
#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

// --- Manual Stack Implementation (LIFO) ---
class ManualStack {
private:
    int arr[MAX_SIZE];
    int topIndex;

public:
    ManualStack() { topIndex = -1; }

    bool isFull() { return topIndex == MAX_SIZE - 1; }
    bool isEmpty() { return topIndex == -1; }

    void push(int val) {
        if (!isFull()) {
            arr[++topIndex] = val;
        }
    }

    void pop() {
        if (!isEmpty()) {
            topIndex--;
        }
    }

    int top() {
        if (!isEmpty()) return arr[topIndex];
        return -1;
    }

    // Helper for printing without destroying the original stack
    void display() {
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
    }
};

// --- Manual Queue Implementation (FIFO) ---
class ManualQueue {
private:
    int arr[MAX_SIZE];
    int frontIndex, rearIndex, count;

public:
    ManualQueue() {
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    bool isFull() { return count == MAX_SIZE; }
    bool isEmpty() { return count == 0; }

    void push(int val) {
        if (!isFull()) {
            rearIndex = (rearIndex + 1) % MAX_SIZE;
            arr[rearIndex] = val;
            count++;
        }
    }

    void pop() {
        if (!isEmpty()) {
            frontIndex = (frontIndex + 1) % MAX_SIZE;
            count--;
        }
    }

    int front() {
        if (!isEmpty()) return arr[frontIndex];
        return -1;
    }

    void display() {
        int tempFront = frontIndex;
        for (int i = 0; i < count; i++) {
            cout << arr[tempFront] << " ";
            tempFront = (tempFront + 1) % MAX_SIZE;
        }
    }
};

// --- Updated Print Function ---
void printStatus(ManualStack &s, ManualQueue &q) {
    cout << "Stack (Pile): ";
    s.display();
    cout << " | Queue (Shipping): ";
    q.display();
    cout << endl;
}

int main() {
    ManualStack warehouse;
    ManualQueue shipping;
    int choice, item;

    while (true) {
        cout << "\n1. Receive Item (Stack) 2. Process to Shipping (Stack->Queue) 3. Deliver (Queue) 4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            if (!warehouse.isFull()) {
                cout << "Enter Item ID: "; cin >> item;
                warehouse.push(item);
            } else {
                cout << "Warehouse Stack Full!\n";
            }
        } 
        else if (choice == 2) {
            if (!warehouse.isEmpty()) {
                if (!shipping.isFull()) {
                    item = warehouse.top();
                    warehouse.pop();
                    shipping.push(item);
                    cout << "Moved item " << item << " to shipping queue.\n";
                } else {
                    cout << "Shipping Queue Full!\n";
                }
            } else {
                cout << "Stack Empty!\n";
            }
        } 
        else if (choice == 3) {
            if (!shipping.isEmpty()) {
                cout << "Delivered item: " << shipping.front() << endl;
                shipping.pop();
            } else {
                cout << "Shipping Queue Empty!\n";
            }
        } 
        else if (choice == 4) {
            break;
        }

        printStatus(warehouse, shipping);
    }
    return 0;
}
