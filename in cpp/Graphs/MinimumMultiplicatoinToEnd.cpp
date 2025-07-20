#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        // code here
        vector<int> distance(100000, INT_MAX);
        distance[start] = 0;
        queue<pair<int, int>> q;
        q.push({0, start});
        int mod = 100000;

        while (!q.empty()) 
        {
            int level = q.front().first;
            int node = q.front().second;
            q.pop();
            if (node == end) return level;
            for (int x : arr)
            {
                int newNode = (x * node) % mod;
                if (distance[newNode] == INT_MAX)
                {
                    distance[newNode] = newNode;
                    q.push({level+1, newNode});
                }
            }
        }
        return -1;
    }
};

int main()
{

    return 0;
}