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

void bottomView(Node* root)
{
    if(root == NULL)
        return;
    unordered_map<int, vector<int>> m;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    int val = 0, mn = 0, mx = 0;
    while(!q.empty())
    {
        auto t = q.front();
        q.pop();
        Node* node = t.first;
        val = t.second;
        m[val].push_back(node->data);
        if(node->left != NULL)
            q.push({node->left, val-1});
        if(node->right != NULL)
            q.push({node->right, val+1});

        if(mn > val)
            mn = val;
        if(mx < val)
            mx = val;
    }

    for(int i=mn; i<=mx; i++)
    {
        vector<int> t = m[i];
        cout << t[t.size()-1] << " ";
    }
}

int main()
{
    Node* root = newNode(20);
    root -> left = newNode(8);
    root -> right = newNode(22);
    root -> left -> left = newNode(5);
    root -> left -> right = newNode(3);
    root -> right -> left = newNode(4);
    root -> right -> right = newNode(25);
    root -> left -> right -> left = newNode(10);
    root -> left -> right -> right = newNode(14);

    bottomView(root);
}
