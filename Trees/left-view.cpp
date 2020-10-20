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
 *         \      \
 *          6      9
 *                  \
 *                  10
 * 
 * Output :1 2 4 5 6 10
**/

int max_level = 0;

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

void printLeftView(struct node * root, int current_level) {
    if(root == NULL) return;
    
    // cout<<"{META :: Element:" << root->data << " Current Level: " << current_level << " Max Level: " << max_level << "}" << endl;
    
    if(max_level < current_level) {
        cout << root->data << " ";
         max_level = current_level;
    }

    printLeftView(root->left, current_level + 1);
    printLeftView(root->right, current_level + 1);
}

void leftView(struct node * root) {
    if(root == NULL) return;
    printLeftView(root, 1);
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
    root->right->right->right->right = newNode(9);
    root->right->right->right->right->right = newNode(10);

    leftView(root);

    return 0;
}
