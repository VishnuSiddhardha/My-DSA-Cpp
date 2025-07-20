#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> graph(n);
        for (auto edge : flights) 
        {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<int> distance(n, INT_MAX);
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src,0}});
        distance[src] = 0;
        while (!q.empty())
        {
            int steps = q.front().first;
            int node = q.front().second.first;
            int dist = q.front().second.second;
            q.pop();

            if (steps > k) continue;
            for (auto p : graph[node])
            {
                int adjNode = p.first;
                int w = p.second;
                if (dist+w < distance[adjNode] && steps <= k) {
                    distance[adjNode] = dist+w;
                    q.push({steps+1, {adjNode, dist+w}});
                }
            }
        }
        if (distance[dst] == INT_MAX) return -1;
        return distance[dst];
    }
};

int main()
{

    return 0;
}