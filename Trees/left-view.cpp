#include<iostream>

using namespace std;

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node * newNode(int num) {
    struct node * newNode = new node;
    newNode->data = num;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void printLeftView(struct node * root) {
    if(root == NULL) return;

    cout<<root->data<<endl;
    if(root->left != NULL) printLeftView(root->left);
    else printLeftView(root->right);
}

int main() {

    struct node * root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    root->left->left->right = newNode(8);

    printLeftView(root);

    return 0;
}