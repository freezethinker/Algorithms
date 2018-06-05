#include<iostream>
#include<unordered_set>

using namespace std;

struct Node {
    int data;
    struct Node * next;
};

struct Node * newNode (int num) {
    Node * temp = new Node;
    temp->data = num;
    temp->next = NULL;
    return temp;
};

void printList (struct Node * head) {
    struct Node * current = head;
    while(current->next != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
}

void removeDuplicates(struct Node * head) {
    unordered_set<int> nonDuplicates;
    struct Node * current = head;
    struct Node * prev = head;
    while(current->next != NULL) {
        if(nonDuplicates.find(current->data) == nonDuplicates.end()) {
            nonDuplicates.insert(current->data);
        }
        else {
            prev->next = current->next;
        }
        prev = current;
        current = current->next;
    }
}

int main() {

    struct Node * head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(4);
    head->next->next->next = newNode(3);
    head->next->next->next->next = newNode(4);
    head->next->next->next->next->next = newNode(5);
    head->next->next->next->next->next->next = newNode(2);
    head->next->next->next->next->next->next->next = newNode(6);
    head->next->next->next->next->next->next->next->next = newNode(4);

    cout<<"Original list: ";
    printList(head);

    removeDuplicates(head);

    cout<<endl<<"Updated list: ";
    printList(head);

    return 0;   
}