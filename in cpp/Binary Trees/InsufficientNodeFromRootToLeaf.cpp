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
    bool postorder(TreeNode *root, int limit)
    {
        // base case
        if (!root) return false;
        if (!root->left && !root->right) {
            // if you get > 0, that means you don't even
            // have that sum also in that path
            return limit <= root->val ;
        }

        limit -= root->val;
        bool left = postorder(root->left, limit);
        bool right = postorder(root->right, limit);
        cout << "Resolving at: " << root->val << endl;

        if (!left) root->left = NULL;
        if (!right) root->right = NULL;
        return left || right;
    }
public:
    TreeNode *sufficientSubset(TreeNode *root, int limit)
    {
        bool result = postorder(root, limit);
        if (!result) return NULL;
        return root;
    }
};

TreeNode* buildTree() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->right = nullptr;

    root->right->left = new TreeNode(17);
    root->right->right = new TreeNode(4);

    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(1);

    root->right->left->left = nullptr;
    root->right->left->right = nullptr;

    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(3);

    return root;
}


int main()
{
    TreeNode *root = buildTree();
    Solution obj;
    obj.sufficientSubset(root, 22);
    return 0;
}