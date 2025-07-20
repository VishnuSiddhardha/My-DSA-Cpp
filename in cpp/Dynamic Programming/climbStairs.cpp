#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        int by1 = 0, by2 = 1;
        for (int i = 1; i <= n; i++)
        {
            int curWays = by1 + by2;
            by1 = by2;
            by2 = curWays;
        }
        return by2;
    }
};

int main()
{

    return 0;
}