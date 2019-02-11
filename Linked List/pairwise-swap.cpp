#include <iostream>

// Not working, to fix

using namespace std;

struct node {
    int data;
    struct node *link;
};

struct node * newNode(int data) {
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

void swapNodes(struct node * one, struct node * two) {
        struct node * temp;
        temp = two;
        two->link = one;
        one->link = two;
}

struct node * pairwiseSwap(struct node * head) {
    if(!head || !(head->link)) 
return head; 

struct node* curr=head; 
struct node* succ=curr->link->link; 

curr->link->link=curr; 
curr->prev=curr->link; 
curr->link=swapPair(succ); 
curr->prev->prev=NULL; 
if(curr->link) 
curr->link->prev=curr; 

return (curr->prev); 
}

int main() {

    struct node * head = newNode(1);
    head->link = newNode(2);
    head->link->link = newNode(3);
    printList(head);

    head = pairwiseSwap(head);

    // printList(head);

    return 0;
}