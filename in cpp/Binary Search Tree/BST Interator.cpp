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

class BSTIterator
{
public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root)
    {
        pushAll(root, st);
    }

    int next()
    {
        TreeNode *node = st.top();
        st.pop();
        if (node->right)
            pushAll(node->right, st);
        return node->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
    void pushAll(TreeNode *root, stack<TreeNode *> &st)
    {
        while (root != NULL)
        {
            st.push(root);
            root = root->left;
        }
    }
};

int main()
{

    return 0;
}