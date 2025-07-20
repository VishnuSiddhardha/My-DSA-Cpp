#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> min_diff(n, vector<int> (m, INT_MAX));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, 
        greater<pair<int, pair<int, int>>>> pq;

        vector<int> deltaRow = {-1, 0, 1, 0};
        vector<int> deltaCol = {0, 1, 0, -1};

        pq.push({0, {0,0}});
        min_diff[0][0] = 0;

        while (!pq.empty())
        {
            int r = pq.top().second.first;
            int c = pq.top().second.second; 
            int dif = pq.top().first;
            pq.pop();

            if (r == n-1 && c == m-1) {
                return dif;
            }
            for (int i = 0; i < 4; i++)
            {
                int row = r + deltaRow[i];
                int col = c + deltaCol[i];
                if (row < 0 || col < 0 || row >= n || col >= m) continue;
                int curDif = max(abs(heights[r][c] - heights[row][col]), dif);
                if (curDif < min_diff[row][col]) {
                    min_diff[row][col] = curDif;
                    pq.push({curDif, {row, col}});
                }
            }
        }
        // dummy
        return -1;
    }
};

int main()
{

    return 0;
}