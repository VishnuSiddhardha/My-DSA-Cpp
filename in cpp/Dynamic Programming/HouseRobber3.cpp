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
    pair<int, int> preOrder(TreeNode *root)
    {
        if (!root) return {0,0};
        pair<int, int> left = preOrder(root->left);
        pair<int, int> right = preOrder(root->right);

        int choose = root->val + left.first + right.first;
        int notChoose = max(left.first, left.second) + max(right.first, right.second);

        return {notChoose, choose};
    }
public:
    int rob(TreeNode* root) {
        pair<int, int> ans = preOrder(root);
        return max(ans.first, ans.second);
    }
};

int main() {
    
    return 0;
}