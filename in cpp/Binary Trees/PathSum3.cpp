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
    int solve (TreeNode* root,int curSum, int k, unordered_map<long long, int> &mp)
    {
        if (!root) return 0;
        curSum += 1LL * root->val;
        int count = mp[curSum-k];
        mp[curSum]++;
        int left = solve(root->left, curSum, k, mp);
        int right = solve(root->right, curSum, k, mp);
        mp[curSum]--;
        return count+left+right;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> mp;
        mp[0] = 1;
        int count = solve(root, 0, targetSum, mp);
        return count;
    }
};

int main() {
    
    return 0;
}