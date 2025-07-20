#include<bits/stdc++.h>
using namespace std;

int longestSubArrayWithSumK(vector<int> arr, int n, int k)
{
    int start = 0, end = 0, len = 0, sum = 0;
    while (end < n)
    {
        sum += arr[end++];
        while (sum > k) {
            sum -= arr[start++];
        }
        if (sum == k)
        {
            len = max(len,end-start);
            // sum = arr[end];
        }
    }
    return len;
}

int main()
{
    vector<int> arr = {2,0,0,3};
    int n = arr.size();
    int length = longestSubArrayWithSumK(arr, n, 3);
    cout << length;
    return 0;
}