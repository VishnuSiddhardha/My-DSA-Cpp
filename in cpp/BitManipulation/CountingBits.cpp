#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n+1, 0);
        for (int i = 1; i <= n; i++)
        {
            if (i&1) { // odd number
                ans[i] = 1 + ans[i/2];
            }
            else ans[i] = ans[i/2];
        }
        return ans;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};

int main()
{

    return 0;
}