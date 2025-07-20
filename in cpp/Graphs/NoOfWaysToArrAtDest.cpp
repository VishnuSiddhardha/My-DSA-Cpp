#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        // build the graph
        vector<vector<pair<int, int>>> graph(n);
        for (auto edge : roads) 
        {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<long long> dist_arr(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0,0});
        dist_arr[0] = 0;
        ways[0] = 1;
        int mod = 1e9 + 7;
        // perfor the logic
        while (!pq.empty())
        {
            long long dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto p : graph[node])
            {
                int adjNode = p.first;
                int w = p.second;
                if (dist_arr[adjNode] > dist + w) 
                {
                    dist_arr[adjNode] = dist + w;
                    pq.push({dist + w, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if (dist_arr[adjNode] == dist + w) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};

int main()
{
        vector<vector<int>> roads = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},\
        {3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    
    return 0;
}