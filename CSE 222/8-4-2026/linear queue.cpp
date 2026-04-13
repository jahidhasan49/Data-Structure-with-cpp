#include<iostream>
using namespace std;

#define SIZE 10

int queue [SIZE];
int front = -1;
int rear =-1;

void enqueue (int item)
{
    if(rear == SIZE -1)
    {
        cout << "Overflow is occured"<< endl;
        return;
    }
    if(front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = item;
}

void dequeue()
{
    if (front == -1 || front > rear )
    {
        cout << "Underflow is occurred" << endl;
        return;
    }
    cout << "Deleted Element: " << queue[front] << endl;
    front++;
}

void show()
{
    if (front == -1 || front > rear )
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue: ";
    for (int i=front; i<=rear; i++)
    {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main()
{
    int option, value;

    while (true) {
        cout << " Linear Queue: " << endl;
        cout << " 1.Enqueue "<< endl;
        cout << " 2.Dequeue "<< endl;
        cout << " 3.Display "<< endl;
        cout << " 4.Exit "<< endl << endl;

        cout << "Enter option : " << endl;
        cin >> option;

      switch (option) {
      case 1:
        cout << "Enter value :";
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
        cout << "Invalid option" << endl;
        }
    }
}
