//Traffic management system
#include <iostream>
using namespace std;

struct Vehicle {
    int id;
    string arrivalTime;
};

class CircularQueue {
    int front, rear, size, count;
    Vehicle* queue;

public:
    CircularQueue(int s) {
        size = s;
        queue = new Vehicle[size];
        front = 0; rear = -1; count = 0;
    }

    bool isFull() { return count == size; }
    bool isEmpty() { return count == 0; }

    void enqueue(int id, string time) {
        if (isFull()) { cout << "Queue Full!\n"; return; }
        rear = (rear + 1) % size;
        queue[rear] = {id, time};
        count++;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Empty!\n"; return; }
        cout << "Vehicle " << queue[front].id << " passed the intersection.\n";
        front = (front + 1) % size;
        count--;
    }
};

int main() {
    CircularQueue traffic(5);
    int direction = 1;

    // Simulate adding vehicles
    traffic.enqueue(101, "10:00");
    traffic.enqueue(102, "10:01");
    traffic.enqueue(103, "10:02");

    while (!traffic.isEmpty()) {
        cout << "\n--- Light is GREEN for Direction " << direction << " ---" << endl;
        traffic.dequeue();
        
        // Transition to next direction (1 to 4)
        direction = (direction % 4) + 1;
    }

    cout << "\nAll vehicles processed." << endl;
    return 0;
}
