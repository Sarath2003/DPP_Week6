#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int d)
{
    Node* t = new Node;
    t->data = d;
    t->left = NULL;
    t->right = NULL;
    return t;
}

void levelOrder(Node* node)
{
    if(node == NULL)
        return;
    queue<Node*> q;
    q.push(node);
    while(!q.empty())
    {
        Node* t = q.front();
        cout << t->data << " ";
        q.pop();
        if(t->left != NULL)
            q.push(t->left);
        if(t->right != NULL)
            q.push(t->right);
    }
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

    levelOrder(root);
}



