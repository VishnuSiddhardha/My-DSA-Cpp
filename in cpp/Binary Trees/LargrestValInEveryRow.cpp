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
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            int maxVal = INT_MIN;
            while (size) {
                TreeNode *top = q.front();
                q.pop();
                if (maxVal < top->val) maxVal = top->val;
                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
                size--;
            }
            res.push_back(maxVal);
        }
        return res;
    }
};

int main()
{

    return 0;
}