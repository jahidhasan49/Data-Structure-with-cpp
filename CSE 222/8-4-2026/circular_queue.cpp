#include<iostream>
using namespace std;
#define SIZE 5

int queue [SIZE];
int front = -1;
int rear =-1;

void enqueue (int x) {
if ((rear+1) % SIZE == front) {

    cout << "Overflow is occured"<< endl;
    return;
  }
     if(front == -1) {
        front = rear = 0;
      } 
     else {
     rear = (rear +1) % SIZE ;
    }
     queue[rear] = x;
}

void dequeue() {
if (front == -1) {
    cout << "Underflow is occurred" << endl;
    return;
}
 cout << "Deleted Element: " << queue[front] << endl;

 if (front == rear) {
    front = rear =-1;
 } else {
 front = (front +1) % SIZE;
 }
}

 void show() {
 if (front == -1) {
    cout << "Queue is empty" << endl;
    return ;
  }
    cout << "Queue: ";
    int front;

    while (true) {
        cout << queue[front] << " ";
        if (front==rear) 
            break;
        front = (front+1) % SIZE;
    }

    cout << endl;
 }

int main()
{
    int option, value;

    while (true) {
        cout << "Circular Queue: " << endl;
        cout << " 1.Enqueue "<< endl;
        cout << " 2.Dequeue "<< endl;
        cout << " 3.Display "<< endl;
        cout << " 4.Exit "<< endl;

        cout << "Enter option : " << endl;
        cin >> option;

        switch (option) {
      case 1:
        cout << "Enter value :" ;
        cin >> value ;
        enqueue(value);
        break;

      case 2:
        dequeue();
        break;

      case 3:
        show();
        break;

      case 4:
        return 0;

      default :
        cout << "Invalid choice" << endl;
         }
    }
}
