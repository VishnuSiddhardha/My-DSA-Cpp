#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> incoming(numCourses, 0);
        for (auto i : prerequisites) {
            graph[i[1]].push_back(i[0]);
            incoming[i[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (incoming[i] == 0)
                q.push(i);
        }
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for (int x : graph[node]) {
                incoming[x]--;
                if (incoming[x] == 0)
                    q.push(x);
            }
        }
        return cnt == numCourses;
    }
};

int main()
{

    return 0;
}