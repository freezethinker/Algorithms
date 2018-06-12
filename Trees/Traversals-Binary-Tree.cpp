#include<iostream>
#include<malloc/malloc.h>

using namespace std;

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node * newNode (int num) {
    struct node * newNode = new node;
    newNode->data = num;
    newNode->left = newNode->right = NULL;

    return newNode;
}

void inorderTraversal(struct node * root) {
    if(root == NULL) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(struct node * root) {
    if(root == NULL) return;
    cout<<root->data<<" ";
    inorderTraversal(root->left);
    inorderTraversal(root->right);
}
void postorderTraversal(struct node * root) {
    if(root == NULL) return;
    inorderTraversal(root->left);
    inorderTraversal(root->right);
    cout<<root->data<<" ";
}

int main() {

    struct node * root = newNode(1);
    
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout<<endl<<"Inorder Traversal: ";
    inorderTraversal(root);
    cout<<endl<<"Preorder Traversal: ";
    preorderTraversal(root);
    cout<<endl<<"Postorder Traversal: ";
    postorderTraversal(root);

    return 0;
}