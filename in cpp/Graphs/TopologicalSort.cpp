#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int node, vector<vector<int>> &graph, vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;
        for (int x : graph[node]) {
            if (!vis[x]) {
                dfs(x, graph, vis, st);
            }
        }   
        st.push(node);
    }
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // code here
        vector<int> vis(V, 0);
        vector<vector<int>> graph(V);
        for (auto i : edges) {
            graph[i[0]].push_back(i[1]);
        }
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) 
                dfs(i, graph, vis, st);
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

int main()
{

    return 0;
}