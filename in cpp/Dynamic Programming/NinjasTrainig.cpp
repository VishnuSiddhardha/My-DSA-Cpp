#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int solve(int day, int prev, vector<vector<int>> &arr, vector<vector<int>> &dp)
    {
        // if already exists
        if (dp[day][prev] != -1) return dp[day][prev];

        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i == prev) continue;
            // base case
            if (day == 0) {
                maxi = max(maxi, arr[0][i]);
            }
            else {
                maxi = max(maxi, arr[day][i] + solve(day-1, i, arr, dp));
            }
        }
        return dp[day][prev] = maxi;
    }
public:
    int maximumPoints(vector<vector<int>> &arr)
    {
        // Code here
        int n = arr.size();
        vector<int> dp(3, -1);
        // return solve(n-1, 3, arr, dp);

        // defining the base cases
        dp[0] = max(arr[0][1], arr[0][2]);
        dp[1] = max(arr[0][0], arr[0][2]);
        dp[2] = max(arr[0][0], arr[0][1]);
        for (int day = 1; day < n; day++)
        {
            vector<int> temp(3, 0);
            for (int last = 0; last < 3; last++)
            {
                for (int i = 0; i < 3; i++)
                {
                    if (i == last) continue;
                    temp[last] = max(temp[last], arr[day][i] + dp[i]);
                }
            }
            dp = temp;
        }
        int res = 0;
        for (int i = 0; i < 3; i++)
            res = max(res, dp[i]);
        return res;
    }
};

int main()
{

    return 0;
}  