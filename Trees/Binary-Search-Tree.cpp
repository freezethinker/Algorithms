#include<iostream>
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

struct node * insertIntoBST (struct node * root, int num) {
    struct node * temp = newNode(num);
    if(root == NULL)
        return temp;
    if(num < root->data) root->left = insertIntoBST(root->left, num);
    if(num > root->data) root->right = insertIntoBST(root->right, num);
    return root;
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
    struct node * root = newNode(10);
    
    insertIntoBST(root, 8);
    insertIntoBST(root, 14);
    insertIntoBST(root, 7);
    insertIntoBST(root, 4);
    insertIntoBST(root, 12);
    insertIntoBST(root, 20);
    insertIntoBST(root, 9);

    cout<<endl<<"Inorder Traversal: ";
    inorderTraversal(root);
    cout<<endl<<"Preorder Traversal: ";
    preorderTraversal(root);
    cout<<endl<<"Postorder Traversal: ";
    postorderTraversal(root);
    return 0;
}