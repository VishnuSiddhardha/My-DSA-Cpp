#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        if (n < 10) return (n&n-1)==0;
        int len = log10(n)+1;
        int num = 8, curLen = 1;
        string mainCheck = to_string(n);
        sort(mainCheck.begin(), mainCheck.end());
        while (curLen <= len) // get all the numbers of the same length
        {
            num = num << 1;
            curLen = log10(num)+1;
            if (curLen == len) {
                string s = to_string(num);
                sort(s.begin(), s.end());
                if (s==mainCheck) return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution obj;
    obj.reorderedPowerOf2(16);
    return 0;
}