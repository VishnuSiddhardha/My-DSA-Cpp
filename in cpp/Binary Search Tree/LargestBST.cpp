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

class BSTInfo {
  public:
    int min;
    int max;
    int mxSz;

    BSTInfo(int mn, int mx, int sz) {
        min = mn;
        max = mx;
        mxSz = sz;
    }
};

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    BSTInfo findLargest(Node *root)
    {
        if (!root)
            return BSTInfo(INT_MAX, INT_MIN, 0);
        BSTInfo left = findLargest(root->left);
        BSTInfo right = findLargest(root->right);

        if (root->data > left.max && root->data < right.min) {
            return BSTInfo(min(root->data, left.min), max(root->data, right.max), 1 + left.mxSz + right.mxSz);
        }
        return BSTInfo(INT_MIN, INT_MAX, max(left.mxSz, right.mxSz));
    }

    int largestBst(Node *root) {
        // Your code here
        return findLargest(root).mxSz;
    }
};

int main()
{

    return 0;
}