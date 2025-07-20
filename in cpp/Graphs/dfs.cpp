#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfsOfGraph(int node, vector<vector<int>> &adj, int *visited, vector<int> &ans)
    {
        visited[node] = 1;
        ans.push_back(node);
        for (int x : adj[node])
        {
            if (visited[x] == 0) {
                dfsOfGraph(x, adj, visited, ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>> &adj)
    {
        // Code here
        vector<int> ans;
        int visited[adj.size()] = {0};
        dfsOfGraph(0, adj, visited, ans);
        return ans;
    }
};

int main()
{

    return 0;
}