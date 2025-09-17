#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int integerBreak(int n)
    {
        if (n == 2 || n == 3) return n-1;
        int count = 1;
        while (n > 4) {
            count *= 3;
            n -= 3;
        }
        return count * n;
    }
};

int main()
{

    return 0;
}