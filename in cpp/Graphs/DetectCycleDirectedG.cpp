#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(int start, vector<vector<int>> &graph, vector<int> &visited)
    {
        visited[start] = 2;
        for (int x : graph[start])
        {
            if (!visited[x]) {
                if (dfs(x, graph, visited))
                    return true;
            }
            else if (visited[x] == 2)
                return true;
        }
        visited[start] = 1;
        return false;
    }
public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        // code here
        vector<vector<int>> graph(V);
        for (auto x : edges) {
            graph[x[0]].push_back(x[1]);
        }
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, graph, vis))
                    return true;
            }
        }
        return false;
    }
};

int main()
{

    return 0;
}