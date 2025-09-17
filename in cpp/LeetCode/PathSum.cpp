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

class Solution
{
    bool dfs(TreeNode *root, int curSum)
    {
        if (root->left == NULL && root->right == NULL)
            return root->val == curSum;
        curSum -= root->val;
        bool left = false;
        if(root->left) left = dfs(root->left, curSum);
        if (left) return true;
        bool right = false;
        if (root->right) right = dfs(root->right, curSum);
        return right;
    }
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return dfs(root, targetSum);
    }
};

int main()
{

    return 0;
}