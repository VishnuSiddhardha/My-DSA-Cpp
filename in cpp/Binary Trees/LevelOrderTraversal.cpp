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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL) return ans;
    queue<TreeNode*> qu;
    qu.push(root);
    while (!qu.empty())
    {
        vector<int> arr;
        int n = qu.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *temp = qu.front();
            qu.pop();
            if (temp->left) qu.push(temp->left);
            if (temp->right) qu.push(temp->right);
            arr.push_back(temp->val);
        }
        ans.push_back(arr);
    }
    return ans;

}

int main()
{
    return 0;
}