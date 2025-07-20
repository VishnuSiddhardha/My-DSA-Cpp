#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(int start, vector<vector<int>> &graph, vector<int> &visited, vector<int> &check)
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
        check[start] = 1;
        visited[start] = 1;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int v = graph.size();
        vector<int> vis(v, 0);
        vector<int> check(v, 0);

        for (int i = 0; i < v; i++)
        {
            if (!vis[i]) {
                dfs(i, graph, vis, check);
            }
        }
        vector<int> safeNodes;
        for (int i = 0; i < v; i++) {
            if (check[i])
                safeNodes.push_back(i);
        }
        return safeNodes;
    }
};

int main()
{

    return 0;
}