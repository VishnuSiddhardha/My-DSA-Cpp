#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<vector<pair<int, int>>> graph(V);
        for (int u = 0; u < V; ++u) {
            for (auto &nbr : adj[u]) {
                int v = nbr[0];
                int wt = nbr[1];
                graph[u].push_back({v, wt});
                graph[v].push_back({u, wt}); 
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
        pq.push({0,0});
        vector<int> visited(V, 0);

        int cost = 0;
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            if (!visited[node]) cost += dist;
            for (auto p : graph[node])
            {
                int adj = p.first;
                int w = p.second;
                if (visited[adj]) continue;
                pq.push({w, adj});
            }
        }
        return cost;
    }
};

int main()
{

    return 0;
}