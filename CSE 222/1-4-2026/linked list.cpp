#include<iostream>
using namespace std;

    struct Node {
        int data;
        Node* next;
};

    Node* insert(Node* head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if(head==NULL){
        head = newNode;
  }
    else {
        Node* temp = head;
    while(temp->next!=NULL) {
    temp = temp->next;
   }
    temp->next = newNode;
  }

       return head;
}

    void show(Node* head) {
    Node* temp = head;
    cout<<"Linked List: ";
    while(temp!=NULL) {
       cout<<temp->data<< "->";
       temp=temp->next;
  }
    cout << "NULL" << endl;
}

    int countNodes(Node* head){
    int count=0;
    Node* temp = head;

    while(temp!=NULL) {
       count++;
       temp=temp->next;
  }
    return count;
}

int main() {
    Node* head = NULL;
    int n, value;
  
    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i=1; i<=n; i++) {
       cout << "Enter value for node " << i << ": ";
       cin >> value;
       head = insert(head, value);
  }
    show(head);
    cout<<"Total Nodes: " << countNodes(head) << endl;

}
