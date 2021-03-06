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

int getHeight (struct node * root) {
    if(root == NULL) return 0;
    else {
        int left_height = getHeight(root->left);
        int right_height = getHeight(root->right);
        if(left_height > right_height) return (left_height+1);
        else return (right_height+1);
    }
}

void printLevel(struct node * root, int level) {
    if(root == NULL) return;

    if(level == 1) cout<<root->data<<" ";
    else {
        printLevel(root->left, level-1);
        printLevel(root->right, level-1);
    }
}

void levelOrderTraversal(struct node * root) {
    int h, i, direction = 0;
    h = getHeight(root);
    for(i = 0; i <= h; i++) {
        printLevel(root, i);
        cout<<endl;
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

    cout<<endl<<"Level order traversal: ";
    levelOrderTraversal(root);

    return 0;
}