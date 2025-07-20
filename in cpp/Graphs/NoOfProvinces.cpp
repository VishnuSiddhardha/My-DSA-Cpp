#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bfs(int node, vector<vector<int>> &isConnected, int *visited)
    {
        queue<int> q;
        q.push(node);
        int n = isConnected[0].size();
        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            visited[top] = 1;
            for (int i = 0; i <n; i++)
            {
                if (isConnected[top][i] && !visited[i])
                {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int V = isConnected.size();
        int visited[V] = {0};
        int count = 0;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bfs(i, isConnected, visited);
                count++;
            }
        }
        return count;
    }
};

int main()
{

    return 0;
}