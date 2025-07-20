#include<bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
    if (divisor == dividend) return 1;
    bool check;
    if ((dividend < 0 && divisor > 0) || ( dividend > 0 && divisor < 0)) check = true;
    long sum = 0;
    long n = abs(dividend);
    divisor = abs(divisor);
    long d = divisor;
    while (n >= d)
    {
        int count = 0;
        while (n >= (d << (count+1)))
        {
            count++;
        }
        sum += 1<<count;
        n -= (d << count);
    }
    cout << sum << endl;
    if (sum == (1 << 31) && check) {
        return INT_MIN;
    }
    else if (sum == (1<<31)) {
        return INT_MAX;
    }
    return check ? -sum : sum;
}

int main()
{
    int res = divide(10,+3);
    cout << res;
    return 0;
}