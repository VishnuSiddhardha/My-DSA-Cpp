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
    int getSize(int node)
    {
        return size[node];
    }
};

class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int maxRow = 0, maxCol = 0;
        for (auto stone : stones)
        {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        for (auto stone : stones)
        {
            ds.unionBySize(stone[0], stone[1] + maxRow + 1);
        }
        int count = 0;
        for (int i = 0; i <= maxRow + maxCol + 1; i++) {
            if (ds.findUParent(i) == i && ds.getSize(i) > 1)
                count++;
        }
        return stones.size()-count;
    }
};

int main()
{

    return 0;
}