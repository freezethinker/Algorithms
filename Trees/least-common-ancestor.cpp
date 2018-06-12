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

void leastCommonAncestor(struct node * root, int l, int r) {
    if(root == NULL) return;
    else if(root->data > l && root->data > r) leastCommonAncestor(root->left, l, r);
    else if(root->data < l && root->data < r) leastCommonAncestor(root->right, l, r);
    else {
        cout<<"LCA: "<<root->data;
        return;
    }
}

int main() {

    struct node * root = newNode(20);

    root->left = newNode(10);
    root->right = newNode(30);

    root->left->right = newNode(13);
    root->left->left = newNode(5);
    root->right->left = newNode(22);
    root->right->right = newNode(35);

    root->right->left->right = newNode(24);

    leastCommonAncestor(root, 22, 35);

    return 0;
}