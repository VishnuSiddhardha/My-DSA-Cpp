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

void preorder(TreeNode *root, vector<int> &res)
{
    if (root == NULL)
        return;
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
}

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> result;
    preorder(root, result);
    return result;
}

void inorder(TreeNode *root, vector<int> &res)
{
    if (root == NULL)
        return;
    inorder(root->left, res);
    inorder(root->right, res);
    res.push_back(root->val);
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> result;
    inorder(root, result);
    return result;
}

void postorder(TreeNode *root, vector<int> &res)
{
    if (root == NULL)
        return;
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
}


vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> result;
    postorder(root, result);
    return result;
}

int main()
{
    return 0;
}