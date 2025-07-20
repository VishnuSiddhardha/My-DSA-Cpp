#include <bits/stdc++.h>
using namespace std;

class Solution {
    
public:
    int minCost(vector<int> &height)
    {
        // Code here
        int n = height.size();

        int byTwo = 0; 
        int byOne = abs(height[0] - height[1]);
        for (int i = 2; i < n; i++) 
        {
            int by2 = byTwo + abs(height[i] - height[i-2]);
            int by1 = byOne + abs(height[i] - height[i-1]);
            byTwo = byOne;
            byOne = min(by2, by1);
        }
        return byOne;
    }
};

int main()
{
    Solution obj;
    vector<int> heights = {20,30,40,20};
    cout << obj.minCost(heights);
    return 0;
}