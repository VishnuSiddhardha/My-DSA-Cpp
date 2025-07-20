#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> size;
    vector<int> parent;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 0);
        parent.resize(n + 1, 0);
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
        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] >= size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution
{
public:
    static bool mycomp(vector<int> a, vector<int> b)
    {
        return a[2] < b[2];
    }
    int kruskalsMST(int V, vector<vector<int>> &edges)
    {
        // code here
        int cost = 0;
        sort(edges.begin(), edges.end(), mycomp);
        DisjointSet st(V);
        for (auto edge : edges)
        {
            if (st.findUParent(edge[0]) != st.findUParent(edge[1]))
            {
                cost += edge[2];
                st.unionBySize(edge[0], edge[1]);
            }
        }
        return cost;
    }
};

int main()
{

    return 0;
}