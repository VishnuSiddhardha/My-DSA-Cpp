#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1;
        int maxArea = 0;
        while (i < j)
        {
            int maxHeight = min(height[i],height[j]);
            maxArea = max(maxArea, maxHeight * (j-i));
            
            if (height[i] < height[j]) i++;
            else j--;
        }
        return maxArea;
    }
};

int main()
{

    return 0;
}