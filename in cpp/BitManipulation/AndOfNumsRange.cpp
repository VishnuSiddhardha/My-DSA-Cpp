#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int shift = 0;
        while (left < right)
        {
            left = left>>1;
            right = right>>1;
            shift++;
        }
        return left<<shift;
    }
};

int main()
{

    return 0;
}