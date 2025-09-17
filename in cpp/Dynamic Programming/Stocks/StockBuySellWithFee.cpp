#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = -1e9;
        int sell = 0;
        for (int i = 0; i < prices.size(); i++){
            buy = std::max(buy, sell - prices[i]);
            sell = std::max(sell, buy + prices[i] - fee);
        }
        return sell;
    }
};

int main()
{

    return 0;
}