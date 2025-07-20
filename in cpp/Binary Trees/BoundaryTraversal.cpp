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

class Solution {
  public:
    bool isLeaf(Node *node)
    {
        return (node->left == NULL) && (node->right == NULL);
    }
    void addLeftNodes(Node *root, vector<int> &ans)
    {
        Node *cur = root->left;
        while (cur)
        {
            if (isLeaf(cur)) break;
            ans.push_back(cur->data);
            if (cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }
    void addRightNode(Node *root, vector<int> &ans)
    {
        Node *cur = root->right;
        vector<Node*> arr;
        while (cur)
        {
            if (!isLeaf(cur)) arr.push_back(cur);
            if (cur->right) cur = cur->right;
            else cur = cur->left;
        }
        for (int i = arr.size()-1; i >= 0; i--)
        {
            ans.push_back(arr[i]->data);
        }
    }
    void addLeaves(Node *root, vector<int> &ans)
    {
        if (isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }
        if (root->left) addLeaves(root->left, ans);
        if (root->right) addLeaves(root->right, ans);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if (root == NULL) return ans;
        if (!isLeaf(root)) ans.push_back(root->data);
        addLeftNodes(root, ans);
        addLeaves(root, ans);
        addRightNode(root, ans);
        return ans;
    }
};


int main()
{
    return 0;
}
