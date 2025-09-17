#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n;
    void helper(int r, int c, vector<vector<int>> &maze, string &s, vector<string> &res)
    {
        if (r == n-1 && c == n-1) {
            res.push_back(s);
            return;
        }
        if (r<0 || c<0 || r>=n || c>=n || !maze[r][c]) return;
        maze[r][c] = 0;
        //Down
        s.push_back('D');
        helper(r+1,c,maze,s,res);
        s.pop_back();
        //Left
        s.push_back('L');
        helper(r,c-1,maze,s,res);
        s.pop_back();
        //Right
        s.push_back('R');
        helper(r,c+1,maze,s,res);
        s.pop_back();
        //Up
        s.push_back('U');
        helper(r-1,c,maze,s,res);
        s.pop_back();
        maze[r][c] = 1;
    }
public:
    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        // code here
        string temp;
        vector<string> res;
        n = maze.size();
        helper(0, 0, maze, temp, res);
        return res;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> mat = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> res = obj.ratInMaze(mat);
    for (string &st:res)
        cout << st << endl;
    return 0;
}