#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<pair<int,int>, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
            }
        }
        
        int count = 0;
        int deltaRow[] = {-1, 0, 0, +1};
        int deltaCol[] = {0, -1, +1, 0};
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            count = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int newRow = r + deltaRow[i];
                int newCol = c + deltaCol[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && vis[newRow][newCol] != 2 && grid[newRow][newCol] != 0)
                {
                    vis[newRow][newCol] = 2;
                    q.push({{newRow, newCol}, count+1});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0)
                    return -1;
            }
        }
        return count;
    }
};

int main()
{

    return 0;
}