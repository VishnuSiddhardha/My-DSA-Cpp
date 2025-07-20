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

void traverse(Node *root, vector<int> &path, vector<vector<int>> &paths)
{
    if (root == NULL) return;
    if (!root->left  && !root->right)
    {
        paths.push_back(path);
    }
    else
    {
        path.push_back(root->data);
        traverse(root->left, path, paths);
        traverse(root->right, path, paths);
    }
    path.pop_back();
}

vector<vector<int>> Paths(Node *root)
{
    // code here
    vector<vector<int>> paths;
    vector<int> path;
    traverse(root, path, paths);
    return paths;
}

int main()
{
    return 0;
}