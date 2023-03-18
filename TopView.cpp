
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

void topView(Node* root)
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
        cout << t[0] << " ";
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

    topView(root);
}
