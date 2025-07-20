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

TreeNode *getBinaryTree(vector<int> preorder, int pre_start, int pre_end,
                        map<int, int> inorder, int in_start, int in_end)
{
    if (pre_start > pre_end)
        return nullptr;
    TreeNode *node = new TreeNode(preorder[pre_start]);
    int rootIdx = inorder[node->val];
    int left_length = rootIdx - in_start;
    node->left = getBinaryTree(preorder, pre_start + 1, pre_start + left_length, inorder, in_start, rootIdx - 1);
    node->right = getBinaryTree(preorder, pre_start + 1 + left_length, pre_end, inorder, rootIdx + 1, in_end);
    return node;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    map<int, int> inorderArr;
    for (int i = 0; i < inorder.size(); i++)
    {
        inorderArr[inorder[i]] = i;
    }

    TreeNode *head = getBinaryTree(preorder, 0, preorder.size() - 1, inorderArr, 0, inorder.size() - 1);
    return head;
}

int main()
{
    return 0;
}