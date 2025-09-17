#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

public:
    vector<int> replaceNonCoprimes(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        for (int x : nums)
        {
            ans.push_back(x);
            while (ans.size() > 1)
            {
                int a = ans.back();
                ans.pop_back();
                int b = ans.back();
                ans.pop_back();
                int g = gcd(a, b);
                if (g > 1)
                { // non-coprime
                    long long lcm = (1LL * a * b) / g;
                    ans.push_back(lcm);
                }
                else
                {
                    ans.push_back(b);
                    ans.push_back(a);
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}