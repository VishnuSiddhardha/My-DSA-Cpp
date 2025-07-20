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

bool isMirror(TreeNode *one, TreeNode* two)
{
    if (one == NULL || two == NULL)
        return one == two;
    return (one->val == two->val) && 
    isMirror(one->left, two->right) && 
    isMirror(one->right, two->left);
}

bool isSymmetric(TreeNode *root)
{
    TreeNode* left = root->left;
    TreeNode *right = root->right;
    return isMirror(left, right);
}

int main()
{
    return 0;
}