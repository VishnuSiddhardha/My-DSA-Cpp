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

void findKthSmallest(TreeNode *root, int k, int &cntr, int &ans)
{
    if (root == NULL) return;

    findKthSmallest(root->left, k, cntr, ans);
    cntr += 1;
    if (cntr == k) ans = root->val;
    findKthSmallest(root->right, k, cntr, ans);
}

int kthSmallest(TreeNode *root, int k)
{
    int ans = 0, cntr = 0;
    findKthSmallest(root, k, cntr, ans);
    return ans;
}

int main()
{

    return 0;
}