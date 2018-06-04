#include<bits/stdc++.h>

using namespace std;

struct newNode() {
    int data;
    struct newNode * next = NULL;
};

void printList (struct newNode * head) {
    struct newNode * current = head;
    while(current->next != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
}

int main() {

    struct newNode * head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(4);
    head->next->next->next = newNode(3);
    head->next->next->next->next = newNode(4);
    head->next->next->next->next->next = newNode(5);
    head->next->next->next->next->next->next = newNode(2);
    head->next->next->next->next->next->next->next = newNode(6);
    head->next->next->next->next->next->next->next->next = newNode(4);

    printList(head);

    return 0;   
}