#include <iostream>

using namespace std;

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node * newNode(int num) {
    struct node * newNode = new node;
    newNode->right = newNode->left = NULL;
    newNode->data = num;
    return newNode;
}

void inOrder(struct node * node) {
    if(node != NULL) {
        inOrder(node->left);
        cout<<node->data<< " ";
        inOrder(node->right);
    }
} 

void mirror(struct node * node) {
    if(node == NULL) return;
    
    mirror(node->left);
    mirror(node->right);
    
    struct node * temp;
    temp = node->left;
    node->left = node->right;
    node->right = temp;
}

int main() {
    struct node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    cout<<"In order original tree: ";
    inOrder(root);
    mirror(root);
    cout<<endl<<"In order mirror tree: ";
    inOrder(root);

    return 0;
}
