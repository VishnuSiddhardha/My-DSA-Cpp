#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int LongestBitonicSequence(int n, vector<int> &nums)
    {
        // code here
        vector<int> dp1(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && dp1[i] < 1 + dp1[j]) {
                    dp1[i] = 1 + dp1[j];
                }
            }
        }
        vector<int> dp2(n, 1);
        int maxLength = 0;
        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j > i; j--) 
            {
                if (nums[i] > nums[j] && dp2[i] < 1 + dp2[j]) {
                    dp2[j] = 1 + dp2[j];
                }
            }
            if (dp1[i] != 1 && dp2[i] != 1) // excludinng the only inc or dec subsequence
                maxLength = max(maxLength, dp1[i] + dp2[n-1] - 1);
        }
        
        return maxLength;
    }
};

int main()
{

    return 0;
}
