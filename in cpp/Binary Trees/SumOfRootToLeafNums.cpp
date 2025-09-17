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
    void solve(int &res, int num, TreeNode *root)
    {
        if (!root->left && !root->right) {
            res += (num*10) + root->val;
            return;
        }
        num = num * 10 + root->val;
        if (root->left) solve(res, num, root->left);
        if (root->right) solve(res, num, root->right);
    }
public:
    int sumNumbers(TreeNode *root)
    {
        int res = 0;
        solve(res, 0, root);
        return res;
    }
};

int main()
{

    return 0;
}