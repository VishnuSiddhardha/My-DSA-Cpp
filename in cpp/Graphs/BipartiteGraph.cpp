#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool colorGraph(int node, int clr, vector<vector<int>> &graph, vector<int> &color)
    {
        queue<pair<int, int>> q;
        q.push({node, clr});
        color[node] = clr;

        while (!q.empty())
        {
            int node = q.front().first;
            int clr = q.front().second;
            q.pop();

            for (int x : graph[node]) {
                if (color[x] == -1) {
                    color[x] = !clr;
                    q.push({x, !clr});
                }
                else if (color[x] == clr){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int v = graph.size();
        vector<int> color(v, -1);
        
        for (int i = 0; i < v; i++) {
            if (color[i] != -1) continue;
            if (!colorGraph(i, 0, graph, color))
                return false;
        }
        return true;
    }

};

int main()
{

    return 0;
}