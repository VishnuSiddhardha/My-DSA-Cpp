#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int> a, int low, int mid, int high)
{
    int count = 0;
    int right = mid+1;
    for (int i = low; i <= mid; i++) {
        while (right <= high && a[i] > 2*a[right]) right++;
        count += (right - mid -1);
    }
    return count;
}

void merge(vector<int> &a, int low, int mid, int high)
{
    vector<int> result;
    int i = low, j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            result.push_back(a[i++]);
        }
        else
        {
            result.push_back(a[j++]);
        }
    }
    while (i <= mid)
    {
        result.push_back(a[i++]);
    }
    while (j <= high)
    {
        result.push_back(a[j++]);
    }

    for (int i = low; i <= high; i++)
    {
        a[i] = result[i - low];
    }
}

int mergeSort(vector<int> &a, int low, int high)
{
    int count = 0;
    if (low >= high)
        return count;
    int mid = (low + high) / 2;
    count += mergeSort(a, low, mid);
    count += mergeSort(a, mid + 1, high);
    count += countPairs(a, low, mid, high);
    merge(a, low, mid, high);
    return count;
}

int reversePairs(vector<int> &nums)
{
    int res = mergeSort(nums, 0, nums.size() - 1);
    return res;
}

// cout << "low: " << low << " mid: " << mid << " high: " << high << " count: " << count << endl;
int main()
{
    vector<int> arr = {2, 4, 3, 5, 1};
    int result = reversePairs(arr);
    cout << "Array:\n";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    cout << "result: " << result;
    return 0;
}