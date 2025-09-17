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

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool seenNull = false;

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            if (!cur) {
                seenNull = true;
            } else {
                if (seenNull) return false; // found node after null → not complete
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}