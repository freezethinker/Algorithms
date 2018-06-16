#include<iostream>

using namespace std;

struct node {
    int data;
    struct node * link;
};

struct node * newNode(int num) {
    struct node * newNode = new node;
    newNode->data = num;
    newNode->link = NULL;
    return newNode;
}

void printLinkedList(struct node * head) {
    struct node * current = head;
    while(current != NULL) {
        cout<<current->data<<" ";
        current = current->link;
    }
}

void reverseLinkedList(struct node * head) {
    struct node * prev = NULL;   
    struct node * current = head;
    struct node * next = NULL;

    while(current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    * head = * prev;
}
// 1 2 3 4
// C

int main() {

    struct node * head = newNode(1);
    head->link = newNode(2);
    head->link->link = newNode(3);
    head->link->link->link = newNode(4);

    cout<<"Original Linked List: ";
    printLinkedList(head);
    // cout<<head->data;
    reverseLinkedList(head);

    cout<<endl<<"Reverse Linked List: ";
    printLinkedList(head);
    // cout<<head->data;

    return 0;
}