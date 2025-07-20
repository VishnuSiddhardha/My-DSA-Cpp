#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int node, vector<vector<int>> &graph, vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;
        for (int x : graph[node]) {
            if (!vis[x])
                dfs(x, graph, vis, st);
        }
        st.push(node);
    }
public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>> &adj, int src)
    {
        // code here
        int v = adj.size();
        queue<pair<int,int>> q;
        q.push({src,0});
        vector<int> distance(v, INT_MAX);
        while (!q.empty()) 
        {
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            distance[node] = min(distance[node], dist);
            for (int x : adj[node])
            {
                if (distance[x] > dist+1) 
                    q.push({x, dist+1});
            }
        }
        for (int i = 0; i < v; i++)
            if (distance[i] == INT_MAX)
                distance[i] = -1;
        return distance;
    }
};

int main()
{

    return 0;
}