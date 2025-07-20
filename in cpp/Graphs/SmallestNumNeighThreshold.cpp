#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int findThresholdNeigbours(int src, int thres, vector<vector<pair<int, int>>> &graph)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        vector<int> distance(graph.size(), INT_MAX);
        distance[src] = 0;
        // perfor dijkstras algorithm
        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto x : graph[node])
            {
                int adj = x.first;
                int w = x.second;
                int curDist = dist + w;
                if (curDist > thres || curDist > distance[adj]) continue;
                distance[adj] = curDist;
                pq.push({curDist, adj});
            }
        }
        int count = 0;
        for (int x : distance) {
            if (x != INT_MAX)
                count++;
        }
        return count;
    }
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<pair<int, int>>> graph(n);
        for (auto edge : edges)
        {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<int> countArr(n, 0);
        for (int i = 0; i < n; i++)
        {
            countArr[i] = findThresholdNeigbours(i, distanceThreshold, graph);
        }
        int res = 0, minCount = countArr[0];
        for (int i = 1; i < n; i++) {
            if (countArr[i] <= minCount) {
                res = i;
                minCount = countArr[i];
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}