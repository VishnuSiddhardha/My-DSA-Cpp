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

class Solution {
    int solve(TreeNode *root)
    {
        if (root == NULL) return 1e7;
        if (!root->left && !root->right) return 1;

        int left = solve(root->left);
        int right = solve(root->right);

        return 1+min(left,right);
    }
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return solve(root);

        if (root == nullptr)
        return 0;
        if (root->left == nullptr)
        return minDepth(root->right) + 1;
        if (root->right == nullptr)
        return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

int main() {
    
    return 0;
}