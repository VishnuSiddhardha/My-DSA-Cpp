#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverseBits(int n)
    {
        unsigned int res = 0;
        for (int i = 0; i < 32; i++)
        {
            int lastBit = n&1;
            int setBit = 1 << (31-i);
            if (lastBit) res = (res | setBit);
            n = n >> 1;
        }
        return res;
    }
};

int main()
{
    // int num = 1;
    // for (int i = 0; i < 4; i++)
    // {   
    //     int setBit = 1 << (i);
    //     num = (num | setBit);
    //     cout << "setBit: " << setBit << endl;
    //     cout << "num: " << num << endl;
    // }
    Solution obj;
    cout << obj.reverseBits(43261596);
    
    return 0;
}