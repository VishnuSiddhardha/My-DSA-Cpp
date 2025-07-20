#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // code here
        vector<vector<int>> graph(V);
        vector<int> incoming(V, 0);
        for (auto i : edges) {
            graph[i[0]].push_back(i[1]);
            incoming[i[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (incoming[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (int x : graph[node]) {
                incoming[x]--;
                if (incoming[x] == 0)
                    q.push(x);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}