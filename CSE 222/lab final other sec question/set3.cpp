//Sestem of emeregency room
#include <iostream>
#include <string>

using namespace std;

// --- Node structure for linked list based implementation ---
struct Node {
    string name;
    Node* next;
    Node(string val) : name(val), next(nullptr) {}
};

// --- Manual Stack Implementation (LIFO) ---
class ManualStack {
private:
    Node* topNode;
public:
    ManualStack() : topNode(nullptr) {}

    void push(string name) {
        Node* newNode = new Node(name);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (topNode) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    string top() {
        return topNode ? topNode->name : "";
    }

    bool empty() {
        return topNode == nullptr;
    }

    void display() {
        if (empty()) { cout << "Empty"; return; }
        Node* temp = topNode;
        while (temp) {
            cout << "[" << temp->name << "] ";
            temp = temp->next;
        }
    }
};

// --- Manual Queue Implementation (FIFO) ---
class ManualQueue {
private:
    Node *frontNode, *rearNode;
public:
    ManualQueue() : frontNode(nullptr), rearNode(nullptr) {}

    void push(string name) {
        Node* newNode = new Node(name);
        if (rearNode == nullptr) {
            frontNode = rearNode = newNode;
            return;
        }
        rearNode->next = newNode;
        rearNode = newNode;
    }

    void pop() {
        if (frontNode == nullptr) return;
        Node* temp = frontNode;
        frontNode = frontNode->next;
        if (frontNode == nullptr) rearNode = nullptr;
        delete temp;
    }

    string front() {
        return frontNode ? frontNode->name : "";
    }

    bool empty() {
        return frontNode == nullptr;
    }

    void display() {
        if (empty()) { cout << "Empty"; return; }
        Node* temp = frontNode;
        while (temp) {
            cout << "[" << temp->name << "] ";
            temp = temp->next;
        }
    }
};

// --- Main Program Logic ---
int main() {
    ManualStack critical;
    ManualQueue nonCritical;
    int choice;
    string name;

    while (true) {
        cout << "\n1. Add Critical  2. Add Non-Critical  3. Treat Patient  4. Display  5. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Critical Patient Name: "; cin >> name;
            critical.push(name);
        } else if (choice == 2) {
            cout << "Enter Non-Critical Patient Name: "; cin >> name;
            nonCritical.push(name);
        } else if (choice == 3) {
            if (!critical.empty()) {
                cout << "Treating Critical (LIFO): " << critical.top() << endl;
                critical.pop();
            } else if (!nonCritical.empty()) {
                cout << "Treating Non-Critical (FIFO): " << nonCritical.front() << endl;
                nonCritical.pop();
            } else {
                cout << "No patients in queue.\n";
            }
        } else if (choice == 4) {
            cout << "\n--- Waiting List ---";
            cout << "\nCritical (Stack): "; critical.display();
            cout << "\nNon-Critical (Queue): "; nonCritical.display();
            cout << endl;
        } else if (choice == 5) {
            break;
        }
    }
    return 0;
}
