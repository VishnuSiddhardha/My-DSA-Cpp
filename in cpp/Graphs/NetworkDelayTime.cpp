#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> graph(n);
        for (auto &edge : times) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<int> distance(n, INT_MAX);
        distance[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for (auto p : graph[node])
            {
                int adj = p.first;
                int w = p.second;
                int newDist = dist + w;
                if (distance[adj] <= newDist) continue;
                distance[adj] = newDist;
                pq.push({newDist, adj}); 
            }
        }
        int ans = -1;
        for (int x : distance)
            ans = max(x, ans);
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{

    return 0;
}