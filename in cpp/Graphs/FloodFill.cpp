#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(vector<vector<int>> &image, int r, int c, int row, int col, int old_clr, int new_clr)
    {
        if (r < 0 || r >= row || c < 0 || c >= col || image[r][c] != old_clr) return;
        image[r][c] = new_clr;
        dfs(image, r - 1, c, row, col, old_clr, new_clr);
        dfs(image, r + 1, c, row, col, old_clr, new_clr);
        dfs(image, r, c - 1, row, col, old_clr, new_clr);
        dfs(image, r, c + 1, row, col, old_clr, new_clr);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int n = image.size();
        int m = image[0].size();
        int old_colour = image[sr][sc];
        dfs(image, sr, sc, n, m, old_colour, color);
        return image;
    }
};

int main()
{

    return 0;
}