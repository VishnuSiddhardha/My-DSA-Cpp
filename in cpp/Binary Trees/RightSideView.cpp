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
// space - O(n)
vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL) return ans;
    queue<TreeNode*> qu;
    qu.push(root);
    while (!qu.empty())
    {
        vector<int> arr;
        int n = qu.size();
        TreeNode *temp;
        for (int i = 0; i < n; i++)
        {
            temp = qu.front();
            qu.pop();
            if (temp->left) qu.push(temp->left);
            if (temp->right) qu.push(temp->right);
        }
        ans.push_back(temp->val);
    }
    return ans;

}
// space - O(logn)
void rinorder(TreeNode* root, int level, vector<int> &ans)
{
    if (root == NULL) return;
    if (ans.size() == level) ans.push_back(root->val);
    rinorder(root->right, level+1, ans);
        rinorder(root->left, level+1, ans);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    rinorder(root, 0, ans);
    return ans;
}

int main()
{
    return 0;
}