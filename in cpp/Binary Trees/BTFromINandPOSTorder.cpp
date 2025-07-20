#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *getBinaryTree(vector<int> &postorder,int post_start, int post_end,
                 map<int,int> &inorder, int in_start, int in_end)
{
    if (post_start > post_end) return nullptr;
    TreeNode *node = new TreeNode(postorder[post_start]);
    int rootIdx = inorder[node->val];

    int right_length = in_end - rootIdx;
    node->right = getBinaryTree(postorder, post_start+1, post_start+right_length, inorder, rootIdx+1 , in_end);
    node->left = getBinaryTree(postorder, post_start+1+right_length, post_end, inorder, in_start, rootIdx-1);
    return node;
}


TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    map<int,int> inodrInd;
    int n = inorder.size();
    for (int i = 0; i < n; i++)
    {
        swap(postorder[i], postorder[n-1-i]);
        inodrInd[inorder[i]] = i;
    }

    TreeNode *head = getBinaryTree(postorder,0, n-1, inodrInd, 0, n-1);
    return head;
}