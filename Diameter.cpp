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

int height(Node* root, int &d)
{
    if(root == NULL)
        return 0;
    int lh = height(root->left,d);
    int rh = height(root->right,d);
    d = max(d, lh+rh);
    return 1 + max(lh,rh);
}

int diameter(Node* root)
{
    int d = 0;
    height(root, d);
    return d;
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

    cout << diameter(root);
}


