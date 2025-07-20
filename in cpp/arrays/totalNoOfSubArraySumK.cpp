#include<bits/stdc++.h>
using namespace std;

int totalSubArraysSumK(vector<int> arr, int k)
{
    unordered_map<int,int> mp;
    int result = 0,sum = 0;
    mp[0] = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        mp[sum]++;
        if (mp.count(sum-k)){
            result += mp[sum-k];
        }
    }
    return result;
}

int main()
{
    vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};
    int res = totalSubArraysSumK(arr,3);
    cout << res;
    return 0;
}