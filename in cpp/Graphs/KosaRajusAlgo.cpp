#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;
        for (int x : adj[node]) 
            if (!vis[x])
                dfs(x, adj, vis, st);
        st.push(node);
    }
    void dfsNormal(int node, vector<vector<int>> &adj, vector<int> &vis) 
    {
        vis[node] = 1;
        for (int x : adj[node]) 
            if (!vis[x])
                dfsNormal(x, adj, vis);
    }
public:
    int kosaraju(vector<vector<int>> &adj)
    {
        // code here
        int n = adj.size();
        vector<int> vis(n, 0);
        stack<int> st;
        // step 1: perform the dfs and save the nodes
        // in the order of visiting them
        for (int i = 0; i < n; i++)
            if (!vis[i])
                dfs(i, adj, vis, st);
        // step 2: now reverse the edges
        vector<vector<int>> adjT(n);
        for (int i = 0; i < n; i++) {
            vis[i] = 0;
            for (int x : adj[i]) 
                adjT[x].push_back(i);
        }
        // now do the dfs again from the result
        // obtained from the step 1
        int count = 0;
        while (!st.empty())
        {
            if (!vis[st.top()]) {
                count++;
                dfsNormal(st.top(), adjT, vis);
            }
            st.pop();
        }
        return count;
    }
};

int main()
{

    return 0;
}