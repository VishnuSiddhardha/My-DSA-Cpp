#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int getLengthOfDigits(int n){
        return log10(n)+1;
    }
public:
    int findNthDigit(int n)
    {
        if (n < 10) return n;
        int low = 1, high = 9;
        int digitLen = 1;
        while (n > digitLen * high)
        {
            n -= digitLen * high;
            low *= 10;
            high *= 10;
            digitLen++;
        }
        int number = low + (n-1)/digitLen;
        
        string s = to_string(number);
        return s[(n - 1) % digitLen] - '0';
    } 

};

int main()
{
    Solution obj;
    cout << obj.findNthDigit(1000);
    return 0;
}