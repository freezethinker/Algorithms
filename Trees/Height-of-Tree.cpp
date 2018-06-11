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

int getHeight (struct node * root) {
    if(root == NULL) return 0;
    else {
        int left_height = getHeight(root->left);
        int right_height = getHeight(root->right);
        if(left_height > right_height) return (left_height+1);
        else return (right_height+1);
    }
}

int main() {

    struct node * root = newNode(1);
    
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int h = getHeight(root);
    cout<<"Height of the tree: "<<h<<endl;
    
    return 0;
}