
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

void leftView(Node* node)
{
    if(node == NULL)
        return;
    queue<Node*> q;
    q.push(node);
    while(!q.empty())
    {
        int nodeCount = q.size();
        for(int i=0; i<nodeCount; i++)
        {
            Node* t = q.front();
            q.pop();
            if(i == 0)
                cout << t->data << " ";
            if(t->left != NULL)
                q.push(t->left);
            if(t->right != NULL)
                q.push(t->right);
        }
        cout << endl;
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

    leftView(root);
}




