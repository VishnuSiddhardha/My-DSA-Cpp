#include<bits/stdc++.h>
using namespace std;

int longestSubArraySum(vector<int> arr, int k)
{
    unordered_map<long long, int> mp;
    long long sum = 0;
    int length = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            length = i+1;
        }
        else if (mp.count(sum-k) == 1) 
        {
            length = max(length,i - mp[sum-k]);
        }
        if (mp.count(sum) == 0)
        {
            mp[sum] = i;
        }
    }
    return length;
}

int main()
{
    return 0;
}