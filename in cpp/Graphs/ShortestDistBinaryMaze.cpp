#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        // code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        set<pair<int, pair<int,int>>> st;
        st.insert({0, source});

        vector<int> deltaRow = {-1, 0, 1, 0};
        vector<int> deltaCol = {0, 1, 0, -1};
        int destRow = destination.first, destCol = destination.second;
        while (!st.empty())
        {
            auto it = *(st.begin());
            int dist = it.first;
            int r = it.second.first;
            int c = it.second.second;
            st.erase(it);
            if (r == destRow && c == destCol) {
                cout << r << " " << c << endl;
                return dist;
            }
            for (int i = 0; i < 4; i++)
            {
                int row = r + deltaRow[i];
                int col = c + deltaCol[i];
                if (row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 0) continue;
                if (distance[row][col] > dist+1) {
                    if (distance[row][col] != INT_MAX)
                    st.erase({distance[row][col], {row, col}});
                    distance[row][col] = dist + 1;
                    st.insert({dist+1, {row, col}}); 
                }
            }
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;
        q.push({0,0});
        distance[0][0] = 1;
        int dest = n-1;
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            int dist = distance[r][c];
            q.pop();
            if (r == dest && c == dest) {
                return dist;
            }
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if(i == 0 && j == 0) continue;
                    int row = r + i;
                    int col = c + j;
                    if (row < 0 || col < 0 || row >= n || col >= n || grid[row][col] == 1) continue;
                    if (distance[row][col] > dist+1) {
                    distance[row][col] = dist + 1;
                    q.push({row, col}); 
                }
                }
            }
        }
        return -1;
    }
};

int main()
{
    pair<int, int> source = {0,2}, dest ={0,0};
    vector<vector<int>> grid = {{1,1,1,0,0}};
    Solution obj;
    obj.shortestPath(grid, source, dest);
    return 0;
}