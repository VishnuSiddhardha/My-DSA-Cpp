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
    unordered_set<int> visited;
    bool dfs(TreeNode* node, int destValue, string &path,
             unordered_map<int, TreeNode*>& parent) {
        if (!node || visited.count(node->val)) return false;
        if (node->val == destValue) return true;

        visited.insert(node->val);

        path.push_back('U');
        if (parent.count(node->val) && dfs(parent[node->val], destValue, path, parent)) return true;
        path.pop_back();

        path.push_back('L');
        if (dfs(node->left, destValue, path, parent)) return true;
        path.pop_back();

        path.push_back('R');
        if (dfs(node->right, destValue, path, parent)) return true;
        path.pop_back();

        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {

        unordered_map<int, TreeNode*> parentNodes;
        // bfs -> for constructing parent links
        queue<TreeNode*> q;
        TreeNode * startNode;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            if (node->val == startValue) startNode = node;
            if (node->left) {
                parentNodes[node->left->val] = node;
                q.push(node->left);
            }
            if (node->right) {
                parentNodes[node->right->val] = node;
                q.push(node->right);
            }
        }
        string res;
        dfs(startNode, destValue, res, parentNodes);
        return res;
    }
};

int main() {
    
    return 0;
}