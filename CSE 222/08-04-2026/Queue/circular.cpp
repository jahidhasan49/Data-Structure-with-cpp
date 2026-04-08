//circular queue
#include <iostream>
using namespace std;

int n;
int *arr;
int front = -1;
int rear = -1;

void enqueue(int val) {

    if ((front == 0 && rear == n - 1) || (rear == (front - 1) % (n - 1))) {
        cout << "Queue Overflow\n";
        return;
    }
    if (front == -1) {
        front = rear = 0;
    }
    else if (rear == n - 1 && front != 0) {
        rear = 0;
    }

    else {
        rear++;
    }

    arr[rear] = val;
    cout << val << " inserted\n";
}
void dequeue() {
    if (front == -1) {
        cout << "Queue Underflow\n";
        return;
    }

    cout << arr[front] << " deleted\n";

    if (front == rear) {
        front = rear = -1;
    }

    else if (front == n - 1) {
        front = 0;
    }
    else {
        front++;
    }
}
void display() {
    if (front == -1) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue elements: ";

    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
    } else {
        for (int i = front; i < n; i++) {
            cout << arr[i] << " ";
        }
        for (int i = 0; i <= rear; i++) {
            cout << arr[i] << " ";
        }
    }

    cout << endl;
}

int main() {
    int choice, value;

    cout << "Enter size of queue: ";
    cin >> n;

    arr = new int[n];

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Insert (Enqueue)\n";
        cout << "2. Delete (Dequeue)\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    delete[] arr;
    return 0;
}
