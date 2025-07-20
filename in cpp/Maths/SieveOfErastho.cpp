#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n)
{
    bool arr[n+1] = {false};
    for (int i = 2; i <= n/2; i++)
    {
        if (!arr[i]) continue; 
        for (int j = i*2; j <= n; j=j++)
        {
            if (j%i == 0)
                arr[j] = false;
        }
    }
    int count = 0;
    for (int i = 2; i <= n; i++)
        if (arr[i])
            count++;
    return count;
}

int main()
{
    return 0;
}