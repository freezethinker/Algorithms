#include<iostream>
#include<stack>

// With stack and alternative needs alterations

using namespace std;

struct node {
    int data;
    struct node * next;
};

struct node * newNode(int data) {
    struct node * newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node * kreverse (struct node * head, int k) { 
    struct node * current = head; 
    struct node * next = NULL; 
    struct node * prev = NULL; 

    int count = 0;
    
    while (current != NULL && count < k) {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++; 
    }

    if (next !=  NULL) 
       head->next = kreverse(next, k);
  
    return prev;
}

struct node * kreversewithstack (struct node * head, int k) {
    stack<struct node *> s;
    struct node * current = head; 
    struct node * first = NULL;
    struct node * headbkp = head;
    
    while(current != NULL) {
        int count = 0;    
        while (current != NULL && count < k) {
            s.push(current);
            current = current->next;
            count++; 
        }

        if(first == NULL) {
                first = s.top();
                head = first;
                s.pop();
            }

        while(s.size() > 0) {
                first->next = s.top();
                first = first->next;
                s.pop();
        }
    }
    first->next = NULL;
    return head;
}

struct node * kreversewithstackwithalt (struct node * head, int k, int flag) {

    stack<struct node *> s;

    struct node * current = head; 
    struct node * first = NULL;
    struct node * headbkp = head;
    
    while(current != NULL) {
        int count = 0;    
        while (current != NULL && count < k) {
            if(flag == 1) {
                s.push(current);
                current = current->next;
            }
            else {
                first = current->next;
                current = current -> next;
            }
            count++; 
        }

        if(first == NULL && flag == 1) {
            first = s.top();
            head = first;
            s.pop();
        }

        while(s.size() > 0 && flag == 1) {
                first->next = s.top();
                first = first->next;
                s.pop();
        }

        if(flag) flag = 0;
        else flag = 1;
    }
    first->next = NULL;
    return head;
}

void printList(struct node * head) {
    struct node * current = head;
    while(current != NULL) {
        cout<<current->data;
        current = current->next;
    }
}

int main() {

    struct node * head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    printList(head);
    cout<<endl;

    // head = kreverse(head, 3);
    // head = kreversewithstack(head, 3);
    head = kreversewithstackwithalt(head, 3, 1);

    printList(head);

    return 0;
}