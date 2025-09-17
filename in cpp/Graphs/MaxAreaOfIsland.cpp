#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n, m;
    int dfs(int r, int c, vector<vector<int>> &grid)
    {
        if (r<0||c<0||r>=n||c>=m||!grid[r][c]) return 0;
        grid[r][c] = 0;
        int up = dfs(r-1,c,grid);
        int right = dfs(r,c+1,grid);
        int down = dfs(r+1,c,grid);
        int left = dfs(r,c-1,grid);

        return 1+up+right+down+left;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j])
                    maxi = max(maxi, dfs(i,j,grid));
            }
        }
        return maxi;
    }
};

int main() {
    
    return 0;
}