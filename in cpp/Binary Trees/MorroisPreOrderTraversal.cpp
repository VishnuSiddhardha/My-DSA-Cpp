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

vector<int> preorder(TreeNode *root)
{
    vector<int> ans;
    while (root != NULL)
    {
        if (!root->left) 
        {
            ans.push_back(root->val);
            root = root->right;
        }
        else
        {
            TreeNode *cur = root->left;
            while (cur->right && cur->right != root)
            {
                cur = cur->right;
            }
            if (cur->right == NULL)
            {
                cur->right = root;
                ans.push_back(root->val);
                root = root->left;
            }
            else 
            {
                cur->right = NULL;
                root = root->right;
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}