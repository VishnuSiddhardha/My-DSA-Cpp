#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        int trans = 2 * k;
        vector<int> next(trans+1,0), cur(trans+1,0);

        for (int ind = n-1; ind >= 0; ind--)
        {
            for (int canBuy = trans-1; canBuy >= 0; canBuy--)
            {
                if (!(canBuy & 1))
                    cur[canBuy] = max(-prices[ind]+next[canBuy+1], next[canBuy]);
                else
                    cur[canBuy] = max(prices[ind]+next[canBuy+1], next[canBuy]);
            }
            next = cur;
        }
        return next[0];
    }
};

int main()
{

    return 0;
}