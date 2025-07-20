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

// bool myComp(pair<int, pair<int,int>> a, pair<int, pair<int,int>> b)
// {
//     if (a.second.second < b.second.second)
//         return true;
//     // else if (a.second.first < b.second.first)
//     //     return true;
//     else if (a.second.second == b.second.second)
//         return a.second.first < b.second.first;
//     return false;
// }

// vector<vector<int>> result;
// if (root == NULL) return result;
// vector<pair<int, pair<int,int>>> arr;
// stack<pair<TreeNode*, pair<int,int>>> st;
// st.push({root, {0,0}});
// while (!st.empty())
// {
//     auto top = st.top();
//     st.pop();
//     arr.push_back({top.first->val, {top.second.first, top.second.second}});
//     if (top.first->right) st.push({top.first->right, {top.second.first+1, top.second.second+1}});
//     if (top.first->left) st.push({top.first->left, {top.second.first+1, top.second.second-1}});
// }
// sort(arr.begin(), arr.end(), myComp);

// for (auto x : arr)
// {
//     cout << "( " << x.first << " , ( " << x.second.first << " , " << x.second.second << " )\n";
// }

// int col = INT_MIN;
// vector<int> temp;
// for (int i = 0; i < arr.size(); i++)
// {
//     if (arr[i].second.second == col)
//     {
//         temp.push_back(arr[i].first);
//     }
//     else
//     {
//         if(!result.empty()) result.push_back(temp);
//         temp = {};
//         col = arr[i].second.second;
//         temp.push_back(arr[i].first);
//     }
// }
// return result;
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> res;
    if (root == NULL) return res;

    map<int, map<int, multiset<int>>> nodes;
    stack<pair<TreeNode*, pair<int, int>>> st;
    st.push({root, {0,0}});
    while (!st.empty())
    {
        auto top = st.top();
        st.pop();
        int x = top.second.first, y = top.second.second;
        TreeNode *node = top.first;
        nodes[x][y].insert(node->val);
        if (node->left) st.push({node->left, {x-1, y+1}});
        if (node->right) st.push({node->right, {x+1, y+1}});
    }

    for (auto x : nodes)
    {
        vector<int> col;
        for (auto y : x.second)
            col.insert(col.end(), y.second.begin(), y.second.end());
        res.push_back(col);
    }
    return res;
}

int main()
{
    return 0;
}