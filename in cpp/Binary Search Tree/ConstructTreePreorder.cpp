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

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    stack<TreeNode*> st;
    TreeNode *root = new TreeNode(preorder[0]);
    TreeNode *prev = root;
    st.push(root);
    int ind = 1, n = preorder.size();
    while (ind < n)
    {
        TreeNode *node = new TreeNode(preorder[ind]);
        if (prev->val > preorder[ind])
        {
            prev->left = node;
        }
        else
        {
            while (!st.empty() && st.top()->val < preorder[ind])
            {
                prev = st.top();
                st.pop();
            }
            prev->right = node;
        }
        prev = node;
        st.push(node);
        ind++;
    }
    return root;
}

int main()
{
    return 0;
}