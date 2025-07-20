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
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int edges = connections.size();
        if (edges < n-1) return -1;
        DisjointSet st(n);
        for (auto x : connections) {
            st.unionBySize(x[0], x[1]);
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == st.findUParent(i))
                count++;
        }
        return count-1;
    }
};

int main()
{

    return 0;
}