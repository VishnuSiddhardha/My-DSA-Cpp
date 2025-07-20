#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

vector<int> bottomView(Node *root)
{
    // Your Code Here
    vector<int> res;
    if (root == NULL) return res;

    map<int, int> nodes;
    queue<pair<Node*, int>> qu;
    qu.push({root, 0});
    while (!qu.empty())
    {
        auto top = qu.front();
        qu.pop();
        Node *node = top.first;
        int x = top.second;
        nodes[x] = node->data;
        if (node->left) qu.push({node->left, x-1});
        if (node->right) qu.push({node->right, x+1});
    }

    for (auto x : nodes)
    {
        res.push_back(x.second);
    }
    return res;
}

int main()
{

    return 0;
}