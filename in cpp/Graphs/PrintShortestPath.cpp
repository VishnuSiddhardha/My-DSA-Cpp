#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Code here
        // build the graph
        vector<vector<pair<int, int>>> graph(n+1);
        for (auto x : edges)
        {
            graph[x[0]].push_back({x[1], x[2]});
            graph[x[1]].push_back({x[0], x[2]});
        }
        vector<int> distance(n+1, INT_MAX);
        distance[1] = 0;
        vector<int> parent(n+1, -1);
        parent[1] = -1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, 1});
        // perfor dijkstras algorithm
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
                    parent[adj] = node;
                } 
            }
        }
        if (parent[n] == -1) return {-1};
        // backtrack
        vector<int> ans;
        int node = n;
        while (node != -1)
        {
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(distance[n]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    return 0;
}