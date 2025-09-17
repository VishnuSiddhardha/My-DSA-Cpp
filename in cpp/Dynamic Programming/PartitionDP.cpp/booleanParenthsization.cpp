#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int i, int j, int isTrue, string &s, vector<vector<vector<int>>> &dp)
    {
        if (i > j) return 0;
        if (i == j) 
        {
            if (isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }
        if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        int ways = 0;
        for (int ind = i + 1; ind <= j-1; ind += 2)
        {
            int leftTrue = solve(i, ind-1, 1, s, dp);
            int leftFalse = solve(i, ind-1, 0, s, dp);
            int rightTrue = solve(ind + 1, j, 1, s, dp);
            int rightFalse = solve(ind + 1, j, 0, s, dp);

            if (s[ind] == '&') {
                if (isTrue) ways += leftTrue * rightTrue;
                else ways += (leftTrue*rightFalse) + (leftFalse*rightTrue) + (leftFalse*rightFalse);
            }
            else if(s[ind] == '|') {
                if (isTrue) ways += (leftTrue * rightTrue) + (leftTrue*rightFalse) + (leftFalse*rightTrue);
                else ways += (leftFalse*rightFalse);
            }
            else {
                if (isTrue) ways += (leftFalse*rightTrue) + (leftTrue * rightFalse);
                else ways += (leftTrue*rightTrue) + (leftFalse*rightFalse);
            }
        }
        return dp[i][j][isTrue] = ways;
    }
public:
    int countWays(string &s)
    {
        // code here
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));

        return solve(0, n-1, 1, s, dp);
    }
};

int main()
{

    return 0;
}