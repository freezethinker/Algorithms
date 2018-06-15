#include<iostream>

using namespace std;

struct node {
    int data;
    struct node * next;
};

struct node * newNode(int num) {
    struct node * newNode = new node;
    newNode->data = num;
    newNode->next = NULL;
    return newNode;
}

int main() {

    struct node * head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    
    return 0;
}