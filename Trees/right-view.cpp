#include<iostream>

using namespace std;

/**
 * Input :
 *        1
 *      /   \
 *    2      3
 *     \      \ 
 *      4      7
 *       \      \
 *        5      8
 *         \      
 *          6
 * 
 * Output : 1 3 7 8 6  
**/

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node * newNode(int num) {
    struct node * newNode = new node;
    newNode->data = num;
    newNode->right = newNode->left = NULL;
    return newNode;
}

int levels_traversed = 0;

void printRightView(struct node * root, int current_level) {
    if(root == NULL) return;
    
    if(levels_traversed < current_level) {
        cout << root->data << " ";
        levels_traversed = current_level;
    }
    
    printRightView(root->right, current_level + 1);
    printRightView(root->left, current_level + 1);
}

void rightView(struct node * root) {
    if(root == NULL) return;
    printRightView(root, 1);
}

int main() {
    
    struct node * root = newNode(1);
    
    root->left = newNode(2);
    root->right = newNode(3);
    
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    
    root->right->right = newNode(7);
    root->right->right->right = newNode(8);
    
    rightView(root);
    
    return 0;
}
