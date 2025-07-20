#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool detectCycle(int start, int parent, vector<vector<int>> &adj, vector<int> &visited)
    {
        visited[start] = 1;
        for (int x : adj[start]) {
            if (!visited[x])
            {
                if (detectCycle(x, start, adj, visited))
                    return true;
            }
            else if (x != parent)
                return true;
        }
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
                if (detectCycle(i, -1, adj, visited)) return true;
        }
        return false;
        
    }
};

int main()
{

    return 0;
}