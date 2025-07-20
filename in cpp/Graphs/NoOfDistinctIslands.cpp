#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int r, int c,char pos, vector<vector<int>> &grid, vector<vector<int>> &visited, vector<char> &order)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (r < 0 || r >= n || c < 0 || c >= m || visited[r][c] || grid[r][c] == 0) return;

        visited[r][c] = 1;
        order.push_back(pos);

        dfs(r-1, c, 'u', grid, visited, order); // up
        dfs(r, c+1, 'r', grid, visited, order); // right
        dfs (r+1, c, 'd', grid, visited, order); // down
        dfs(r, c-1, 'l', grid, visited, order); // left
    }
public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<char>> st;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    vector<char> curOrder;
                    dfs(i, j, 's', grid, vis, curOrder); // start
                    st.insert(curOrder);
                }
            }
        }
        return st.size();
    }
};

int main()
{

    return 0;
}