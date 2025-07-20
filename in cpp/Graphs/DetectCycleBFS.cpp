#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool detectCycle(int start, vector<vector<int>> &adj, vector<int> &visited)
    {
        queue<pair<int, int>> q;
        q.push({start, -1});
        visited[start] = 1;

        while (!q.empty())
        {
            int curNode = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int x : adj[curNode]) {
                if (!visited[x])
                {
                    visited[x] = 1;
                    q.push({x, curNode});
                }
                else if (x != parent)
                    return true;
            }
        }
        return false;
    }
public:
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        // Code here
        vector<vector<int>> adj(V);
        for (auto i : edges) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(V);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                if (detectCycle(i, adj, visited)) return true;
        }
        return false;
        
    }
};

int main()
{

    return 0;
}