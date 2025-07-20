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

int height(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int left = height(root->left, maxi);
    int right = height(root->right, maxi);
    maxi = max(maxi, left+right);
    return max(left, right)+1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    int maxi = 0;
    int len = height(root, maxi);
    return maxi;
}

int main()
{
    return 0;
}