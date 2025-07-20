#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        // Code here
        vector<int> distance(V, 1e8);
        for (int i = 0; i < V - 1; i++)
        {
            for (auto edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int dist = edge[2];
                if (distance[u] != 1e8 && distance[u] + dist < distance[v])
                {
                    distance[v] = dist + distance[u];
                }
            }
        }

        for (int i = 0; i < V; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int dist = edges[i][2];
            if (distance[u] != 1e8 && distance[u] + dist < distance[v])
            {
                return {-1};
            }
        }
        return distance;
    }
};

int main()
{

    return 0;
}