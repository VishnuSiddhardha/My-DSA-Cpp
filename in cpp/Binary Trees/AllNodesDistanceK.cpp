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

void getNearestNodes(TreeNode *root, int k, int curDist, vector<int> &ans, unordered_set<TreeNode*> &visited,
                    unordered_map<TreeNode*, TreeNode*> &parents)
{
    if (root == NULL) return;
    if (k == curDist)
    {
        ans.push_back(root->val);
        return;
    }
    if ((parents.find(root) != parents.end()) && visited.find(parents[root]) == visited.end())
    {
        visited.insert(parents[root]);
        getNearestNodes(parents[root], k, curDist+1, ans, visited, parents);
    }
    if ((root->left != NULL) && visited.find(root->left) == visited.end())
    {
        visited.insert(root->left);
        getNearestNodes(root->left, k, curDist+1, ans, visited, parents);
    }
    if ((root->right != NULL) && visited.find(root->right) == visited.end()) 
    {
        visited.insert(root->right);
        getNearestNodes(root->right, k, curDist+1, ans, visited, parents);
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<TreeNode*, TreeNode*> parentNode;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* parent = q.front();
            q.pop();
            if (parent->left) {
                q.push(parent->left);
                parentNode[parent->left] = parent;
            }
            if (parent->right) {
                q.push(parent->right);
                parentNode[parent->right] = parent;
            }
        }
    }
    vector<int> ans;
    unordered_set<TreeNode*> s;
    s.insert(target);
    getNearestNodes(target, k, 0, ans, s, parentNode);
    return ans;
}

// iterative

// queue<TreeNode *>q;
//         q.push(root);
//         unordered_map<int,TreeNode *> m;
//         while(!q.empty()){
//             int size = q.size();

//             while(size--){
//                 TreeNode* temp = q.front();
//                 q.pop();

//                 if(temp->left){
//                     m[temp->left->val] = temp;
//                     q.push(temp->left);
//                 }

//                 if(temp->right){
//                     m[temp->right->val] = temp;
//                     q.push(temp->right);
//                 }
//             }
//         }
//             q.push(target);
//             unordered_map<int,int>visited;
//             while(k-- && !q.empty()){
//                 int size = q.size();
//                 while(size--){

//                 TreeNode *temp = q.front();
//                 q.pop();
//                 visited[temp->val] = 1;
//                 if(temp->left && !visited[temp->left->val]){
//                     q.push(temp->left);
//                 }

//                 if(temp->right && !visited[temp->right->val]){
//                     q.push(temp->right);
//                 }
//                 TreeNode *l = m[temp->val];
//                 if(m[temp->val]!=NULL && !visited[l->val]){
//                     q.push(m[temp->val]);
//                 } 
//             }
//          }
        

//         vector<int>ans;
//         while(!q.empty()){
//             TreeNode* x = q.front();
//             ans.push_back(x->val);
//             q.pop();
//         }

//         return ans;

int main()
{
    return 0;
}