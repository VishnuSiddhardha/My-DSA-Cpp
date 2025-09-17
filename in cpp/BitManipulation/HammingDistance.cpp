#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int num = x ^ y;
        int count = 0;
        while (num) {
            if (num&1) count++;
            num = num >> 1;
        }
        return count;
    }
};

int main()
{

    return 0;
}