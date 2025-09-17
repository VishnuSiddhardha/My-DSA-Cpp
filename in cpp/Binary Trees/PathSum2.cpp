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
    void dfs(TreeNode* root, int sum ,vector<int> &temp, vector<vector<int>> &res)
    {
        if (!root->left && !root->right) {
            if (root->val == sum) {
                res.push_back(temp);
                res.back().push_back(root->val);
            }
            return;
        }
        sum = sum - root->val;
        temp.push_back(root->val);
        if (root->left) dfs(root->left, sum,temp,res);
        if (root->right) dfs(root->right, sum, temp, res);
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> arr;
        dfs(root, targetSum, arr, ans);
        return ans;
    }
};

int main() {
    
    return 0;
}