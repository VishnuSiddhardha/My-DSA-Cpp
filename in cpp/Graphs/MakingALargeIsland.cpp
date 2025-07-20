#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> size;
    vector<int> parent;
public:
    DisjointSet(int n) {
        size.resize(n+1, 1);
        parent.resize(n+1, 0);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u), ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return;

        if (size[ulp_u] >= size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
    int getSize(int node){
        return size[node];
    }
};

class Solution
{
    int deltRow[4] = {-1, 0, 1, 0};
    int deltCol[4] = {0, 1, 0, -1};
    int n;
    void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis, DisjointSet &ds)
    {
        vis[r][c] = 1;
        for (int i = 0; i < 4; i++)
        {
            int newR = r + deltRow[i];
            int newC = c + deltCol[i];
            if (newR < 0 || newC < 0 || newR >= n || newC >= n || vis[newR][newC] || !grid[newR][newC]) continue;
            ds.unionBySize(r * n + c, newR * n + newC);
            dfs(newR, newC, grid, vis, ds);
        }
    }
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        n = grid.size();
        DisjointSet ds(n*n);
        vector<vector<int>> vis(n, vector<int>(n, 0));
        // perform dfs and group every island
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j])
                    dfs(i, j, grid, vis, ds);
            }
        }

        int maxSize = 1;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) continue;
                int curSize = 1;
                for (int k = 0; k < 4; k++) {
                    int adjR = i + deltRow[k];
                    int adjC = j + deltCol[k];
                    if (adjR < 0 || adjC < 0 || adjR >= n || adjC >= n || !grid[adjR][adjC]) continue;
                    int node = ds.findUParent(adjR * n + adjC);
                    if (st.find(node) == st.end())
                        curSize += ds.getSize(node);
                    st.insert(node);
                }
                maxSize = max(maxSize, curSize);
                st.clear();
            }
        }
        for (int i = 0; i < n*n; i++)
            maxSize = max(maxSize, ds.getSize(i));
        return maxSize;
    }
};

int main()
{

    return 0;
}