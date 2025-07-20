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

int getLeftTreeHeight(TreeNode *root)
{
    int height = 0;
    while (root)
    {
        height++;
        root = root->left;
    }
    return height;
}

int getRightTreeHeight(TreeNode *root)
{
    int height = 0;
    while (root)
    {
        height++;
        root = root->right;
    }
    return height;
}

int countNodes(TreeNode *root)
{
    if (root == NULL) return 0;
    int left = getLeftTreeHeight(root);
    int right = getRightTreeHeight(root);
    if (left == right)
        return (1 << left) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    return 0;
}