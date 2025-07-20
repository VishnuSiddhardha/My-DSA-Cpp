#include <bits/stdc++.h>
using namespace std;

vector<int> AllPrimeFactors(int n)
{
    vector<int> result;
    int i = 2;
    while (i <= n)
    {
        if (n % i == 0)
        {
            result.push_back(i);
            while (n % i == 0)
            {
                n /= i;
            }
        }
        i++;
    }
    return result;
}

void print_divisors(int n)
{
    // Code here.
    int i;
    for (i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
            cout << i << " ";
    }
    cout << endl
         << i << endl;
    for (i = i - 1; i >= 1; i--)
    {
        if (n % i == 0)
            cout << n / i << " ";
    }
}

double myPow(double x, int n)
{
    double result = 1;
    bool isnegative = n < 0 ? true : false;
    long p = abs((long)n);

    while (p)
    {
        // for odd
        if (p & 1)
        {
            result *= x;
            p--;
        }
        else // for even
        {
            x = x * x;
            p = p >> 1;
        }
    }
    if (isnegative)
        return 1.0 / result;
    return result;
}

vector<int> sieve(int n) {
    vector<int> arr(n+1);
    // mark with their index numbers
    for (int i = 2; i <= n; i++)
        arr[i] = i;
    // apply the algorithm
    for (int i = 2; i*i <= n; i++)
    {
        if (arr[i] != i) continue; 
        for (int j = i*i; j <= n; j+=i)
        {
            if (arr[j] == j && j%i == 0)
                arr[j] = i;
        }
    }
    return arr;
}
vector<int> findPrimeFactors(int n) {
    // Write your code here
    vector<int> arr = sieve(n);
    vector<int> result;
    while (n != 1)
    {
        int num = arr[n];
        result.push_back(num);
        n = n / num;
    }
    return result;
}
int main()
{
    // print_divisors(36);
    // vector<int> res = AllPrimeFactors(35);
    // for (int x : res)
    //     cout << x << " ";
    // double answer = myPow(2, -10);
    // cout << answer << endl;
    vector<int> arr = findPrimeFactors(30);
    for (auto x : arr)
        cout << x << " ";
    return 0;
}