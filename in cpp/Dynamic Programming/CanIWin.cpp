#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<long long, int> dp;
    bool playGame(int mask, int rem, int n) {

        if (rem <= 0) return false;
        if (dp.count(mask)) return dp[mask];

        for (int num = 1; num <= n; num++) {
            if (!(mask & (1 << num))) { // not picked
                if (!playGame(mask | (1 << num), rem- num, n))
                    dp[mask] = true;
            }
        }
        return false;
    }
public:
    bool canIWin(int n, int desiredTotal)
    {
        int totalSum = (n*(n+1))/2;
        if (totalSum < desiredTotal) return false;
        
        return playGame(0, desiredTotal, desiredTotal);

    }
};

int main()
{

    return 0;
}