#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int x)
{
    Node *temp = new Node;
    temp -> data = x;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

int height(Node* root)
{
    if(root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout << height(root);
}
