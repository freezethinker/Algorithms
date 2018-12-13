#include<iostream>

using namespace std;

struct node {
    int data; 
    struct node * link;
};

struct node * createNode(int data) {
    struct node * newNode = new node;
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

void printList(struct node * head) {
    struct node * current = head;
    while(current != NULL) {
        cout<<current->data;
        current = current->link;
    }
}

struct node * reverseList(node * current, node * prev) {

    if(current == NULL) {
        return prev;
    }

    struct node * next = current->link;
    current->link = prev;
    return reverseList(next, current);
}

int main() {
    struct node * head = createNode(1);
    head->link = createNode(2);
    head->link->link = createNode(3);
    head->link->link->link = createNode(4);
    head->link->link->link->link = createNode(5);

    printList(head);
    cout<<endl;

    head = reverseList(head, NULL);

    printList(head);

    return 0;
}