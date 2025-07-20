#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj)
    {
        // Code here
        int n = adj.size();
        int visited[n] = {0};
        vector<int> ans;
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            ans.push_back(top);
            visited[top] = 1;
            for (int x : adj[top]) {
                if (visited[x] == 0)
                {
                    visited[x] = 1;
                    q.push(x);
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}