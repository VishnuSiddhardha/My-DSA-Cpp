#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int n = cost.size();
        int rem = n%3;
        int sum = 0;
        for (int i = n-1; i >= rem; i-=3)
            sum += cost[i] + cost[i-1];
        for (int i = rem-1; i >= 0; i--)
            sum += cost[i];
        return sum;

    }
};

int main() {
    
    return 0;
}