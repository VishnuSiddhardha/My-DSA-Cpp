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
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void inorder(Node *root, vector<int> &arr)
    {
        if (root == NULL) return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> one, two;
        inorder(root1, one);
        inorder(root2, two);
        int i = 0, j = 0;
        int n = one.size(), m = two.size();
        vector<int> ans;
        while (i < n && j < m)
        {
            if (one[i] < two[j]) {
                ans.push_back(one[i]);
                i++;
            }
            else {
                ans.push_back(two[j]);
                j++;
            }
        }
        while (i < n)
            ans.push_back(one[i++]);
        while (j < m)
            ans.push_back(two[j++]);
        return ans;
    }
};

int main()
{

    return 0;
}