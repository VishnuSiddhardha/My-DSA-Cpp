#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bfs(int node, vector<vector<int>> &edges, int *visited)
    {
        vector<int> arr;
        queue<int> q;
        q.push(node);
        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            visited[top] = 1;
            arr.push_back(top);
            for (int x : edges[top])
            {
                if (!visited[x]) {
                    visited[x] = 1;
                    q.push(x);
                }
            }
        }
        return arr;
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>> &edges)
    {
        // code here
        int visited[V] = {0};
        vector<vector<int>> ans;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                vector<int> arr = bfs(i, edges, visited);
                ans.push_back(arr);
            }
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}