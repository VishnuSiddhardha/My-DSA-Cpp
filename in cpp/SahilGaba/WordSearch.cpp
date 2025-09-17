#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n, m, sLen;
    bool dfs(int r, int c, int idx, vector<vector<char>> &board, string &s, vector<vector<bool>> &vis) {
        if (idx == sLen) return true;
        if (r < 0 || r >= n || c < 0 || c >= m || vis[r][c] || board[r][c] != s[idx]) return false;  

        vis[r][c] = true;
        bool up = dfs(r-1, c, idx+1, board, s, vis); // up
        bool right = dfs(r, c+1, idx+1, board, s, vis); // right
        bool down = dfs (r+1, c, idx+1, board, s, vis); // down
        bool left = dfs(r, c-1, idx+1, board, s, vis); // left

        if (up || right || down || left) return true;
        vis[r][c] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        n = board.size();
        m = board[0].size();
        sLen = word.length();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 0, board, word, visited))
                        return true;
                }
            }
        }
        return false;
    }
};

int main()
{

    return 0;
}