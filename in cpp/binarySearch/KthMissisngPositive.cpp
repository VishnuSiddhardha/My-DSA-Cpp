#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int> &arr, int k)
{
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] - 1 - mid < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high + 1 + k;
}

int main()
{
    vector<int> arr = {2};
    int ele = findKthPositive(arr, 2);
    cout << ele;
    return 0;
}