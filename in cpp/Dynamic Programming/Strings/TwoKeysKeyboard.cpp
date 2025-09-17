#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int screen, int val, int dest, vector<vector<int>> &dp) 
    {
        if (screen == dest) return 0;
        if (screen > dest) return 1e5;
        if (dp[screen][val] != -1) return dp[screen][val];
        // need to copy
        int paste = 1e5;
        if (val+screen <= dest) paste = 1 + solve(screen+val, val, dest, dp);
        int copy = 1 + solve(screen, screen, dest, dp);
        return dp[screen][val] = min(copy, paste);
    }
public:
    int minSteps(int n) {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(1, 0, n, dp);
    }
};

int main() {
    
    return 0;
}