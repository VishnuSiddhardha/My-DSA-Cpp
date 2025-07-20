#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // Code here
        // build the adjacency list
        vector<vector<pair<int, int>>> graph(V);
        for (auto x : edges)
        {
            graph[x[0]].push_back({x[1], x[2]});
            graph[x[1]].push_back({x[0], x[2]});
        }
        vector<int> distance(V, INT_MAX);
        distance[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, src});
        while (!minHeap.empty())
        {
            int node = minHeap.top().second;
            int dist = minHeap.top().first;
            minHeap.pop();

            for (auto x : graph[node])
            {
                int adj = x.first;
                int w = x.second;
                if (distance[adj] > w + dist)
                {
                    distance[adj] = w + dist;
                    minHeap.push({distance[adj], adj});
                } 
            }
        }
        return distance;
    }
};

int main()
{

    return 0;
}