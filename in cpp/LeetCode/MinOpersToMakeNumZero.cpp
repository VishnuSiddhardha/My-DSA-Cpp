#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int makeTheIntegerZero(int num1, int num2)
    {
        for (int ops = 1; ops <= 60; ops++) { // 60 is safe (2^60 > 1e18)
            long long val = 1LL * num1 - 1LL * ops * num2;
            if (val < 0) break; // can't go below zero
            if (__builtin_popcountll(val) <= ops && ops <= val)
                return ops;
        }
        return -1;
    }
};

int main()
{

    return 0;
}