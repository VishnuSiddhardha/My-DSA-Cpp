#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> size;
    vector<int> parent;
public:
    DisjointSet(int n) {
        size.resize(n+1, 0);
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
};

class Solution
{
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        // code here
        DisjointSet ds(n*m);
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> deltaRow = {-1, 0, 1, 0};
        vector<int> deltaCol = {0, 1, 0, -1};
        int count = 0;
        vector<int> arr;
        // perform the algorithm
        for (vector<int> step : operators)
        {
            int i = step[0];
            int j = step[1];
            if (vis[i][j]) continue;
            vis[i][j] = 1;
            count++;
            int curNodeValue = m*i + j;
            for (int k = 0; k < 4; k++) {
                int neighI = i + deltaRow[k];
                int neighJ = j + deltaCol[k];
                if (neighI < 0 || neighI >= n || neighJ < 0 || neighJ >= m || !vis[neighI][neighJ]) continue;
                int neighNodeValue = m*neighI + neighJ;
                if (ds.findUParent(curNodeValue) != ds.findUParent(neighNodeValue))
                {
                    count--;
                    ds.unionBySize(curNodeValue, neighNodeValue);
                }
            }
            arr.push_back(count);
        }
        return arr;
    }
};

int main()
{

    return 0;
}