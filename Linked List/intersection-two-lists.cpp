#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node * next; 
};

struct Node * newNode (int num) {
    struct Node * temp = new Node;
    temp->data = num;
    temp->next = NULL;
    return temp;
};

void printList (struct Node * head) {
    struct Node * current = head;
    cout<<current->data<<" ";
    if(current->next != NULL) printList(current->next);
}

int main() {
    struct Node * head1 = newNode(1);
    head1->next = newNode(4);
    head1->next->next = newNode(2);
    head1->next->next->next = newNode(5);
    head1->next->next->next->next = newNode(3);

    struct Node * head2 = newNode(4);
    head2->next = newNode(7);
    head2->next->next = newNode(2);

    cout<<endl<<"List 1: ";
    printList(head1);

    cout<<endl<<"List 2: ";
    printList(head2);

    return 0;
}