#include<bits/stdc++.h>
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

vector<vector<int>> preInPostTraversals(TreeNode *root)
{
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    vector<vector<int>> ans;
    vector<int> pre, in, post;
    if (root == NULL) return ans;
    while (!st.empty())
    {
        pair<TreeNode*, int> it = st.top();
        st.pop();
        // for 1, it is preorder
        // increment count fromt 1 to 2
        // check for the left and push it
        if (it.second == 1)
        {
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if (it.first->left) {
                st.push({it.first->left, 1});
            }
        }
        // for 2, it is inorder
        // increment count fro 2 to 3
        // check for the right and push it
        else if (it.second == 2)
        {
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            if (it.first->right) {
                st.push({it.first->right, 1});
            }
        }
        // for 3, it is postorder
        else
        {
            post.push_back(it.first->val);
        }
    }
    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);
    return ans;
}

int main()
{
    return 0;
}