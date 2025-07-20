#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &coins, int key)
{
    int low = 0, high = coins.size() - 1;
    while (low <= high)
    {
        int mid = (low+high)/2;
        if (coins[mid] <= key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}

vector<int> minPartition(int N)
{
    // code here
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int count = 0, value = N;
    vector<int> result;
    while (value > 0)
    {  
        int ind = upperBound(coins, value);
        int temp = value/coins[ind];
        count += temp;
        value = value % coins[ind];
        cout << value << endl;
        while (temp > 0)
        {
            result.push_back(coins[ind]);
            temp--;
        }
    }
    return result;
}


int main()
{
    int n = 6950;
    vector<int> res = minPartition(n);
    for (int x : res)
        cout << x << " ";
    
    return 0;
}