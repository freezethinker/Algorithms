#include<iostream>
#include<map>

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

struct Node * insertInOrder(struct Node * head, int num) {
    cout<<"In";
    struct Node * temp = new Node;
    struct Node * current = head;

    temp->data = num;
    temp->next = NULL;

    cout<<head->data;
    
    if(head == NULL) {
        head = temp;
    }
    else {
        while(current->next != NULL) {
            current = current->next;  
        }
        temp->next = current->next;
        current->next = temp;
    }
    return head;
}

void computeIntersection (struct Node * head1, struct Node * head2) {
    struct Node * head3, * current = head1;
    map <int, bool> listOne;
    map <int, bool> :: iterator iter;
    
    while(current -> next != NULL) {
        listOne.insert(pair <int, bool> (current->data, 0));
        current = current->next;
    } listOne.insert(pair <int, bool> (current->data, 0));

    current = head2;

    cout<<endl<<"Intersection Elements: ";
    while(current->next != NULL) {
        if(listOne.find(current->data) != listOne.end()) {
            head3 = insertInOrder(head3, current->data);
            cout<<current->data<<" ";
            listOne.erase(current->data);
        }
        current = current->next;
    }

    // if(listOne.find(current->data) != listOne.end()) {
    //     head3 = insertInOrder(head3, current->data);
    //     cout<<current->data;
    //     listOne.erase(current->data);
    // }
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

    computeIntersection(head1, head2);

    return 0;
}