#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int node, vector<vector<pair<int,int>>> &graph, vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;
        for (pair<int,int> p : graph[node]) {
            if (!vis[p.first])
                dfs(p.first, graph, vis, st);
        }
        st.push(node);
    }
    public:
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        // code here
        vector<vector<pair<int, int>>> graph(V);
        for (auto x : edges) {
            graph[x[0]].push_back({x[1], x[2]});
        }
        stack<int> st;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i])
                dfs(i, graph, vis, st);
        }

        // now calculate the distance matrix
        vector<int> distance(V, INT_MAX);
        while (st.top() != 0) {
            distance[st.top()] = -1;
            st.pop();
        }
        distance[0] = 0;
        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            for (auto p : graph[top])
            {
                int node = p.first;
                int dist = p.second;
                distance[node] = min(distance[node], distance[top]+dist);
            }
        }
        return distance;
    }
};

int main()
{

    return 0;
}