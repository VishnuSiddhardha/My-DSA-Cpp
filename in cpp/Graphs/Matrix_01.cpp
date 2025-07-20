#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> result(n, vector<int>(m, 0));
        queue<pair<pair<int,int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                if (!mat[i][j]) {
                    q.push({{i,j}, 0});
                    visited[i][j] = 1;
                }
        }

        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};
        while (!q.empty())
        {
            int dist = q.front().second;
            int r = q.front().first.first;
            int c = q.front().first.second;
            q.pop();
            result[r][c] = dist;
      
            
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + deltaRow[i];
                int ncol = c + deltaCol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol]) {
                    visited[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, dist+1});
                }
            }
        }
        return result;
    }
};

int main()
{

    return 0;
}