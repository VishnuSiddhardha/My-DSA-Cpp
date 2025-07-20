#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int widthOfBinaryTree(TreeNode *root)
{
    queue<pair<TreeNode*, unsigned int>> qu;
    qu.push({root, 0});
    int maxi = 0;
    while (!qu.empty())
    {
        int size = qu.size();
        int mini = qu.front().second;
        int first, last;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = qu.front().first;
            unsigned int ind = qu.front().second - mini;
            qu.pop();
            if (i == 0) first = ind;
            last = ind;
            if (node->left) qu.push({node->left, (unsigned int)2*ind+1});
            if (node->right) qu.push({node->right, (unsigned int)2*ind+2});
        }
        maxi = max(maxi, last-first+1);
    }
    return maxi;
}

int main()
{
    return 0;
}