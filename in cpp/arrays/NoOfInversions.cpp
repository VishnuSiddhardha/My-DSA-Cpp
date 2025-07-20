#include <bits/stdc++.h>
using namespace std;

int merge(vector<int>&a, int low, int mid, int high)
{
    vector<int> result;
    int i = low, j = mid+1;
    int count = 0;
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j]) {
            result.push_back(a[i++]);
        }
        else {
            count += (mid - i) + 1;
            result.push_back(a[j++]);
        }
    }

    while (i <= mid) {
        result.push_back(a[i++]);
    }
    while (j <= high) {
        result.push_back(a[j++]);
    }

    for (int i = low; i <= high; i++) {
        a[i] = result[i-low];
    }
    return count;
}

int mergeSort(vector<int> &a, int low, int high)
{
    int count = 0;
    if (low >= high) return count;
    int mid = (low+high)/2;
    count += mergeSort(a,low,mid);
    count += mergeSort(a,mid+1,high);
    count += merge(a,low,mid,high);
    return count;
}

int numberOfInversions(vector<int> &a, int n)
{
    int result = mergeSort(a,0,n-1);  
    return result;   
}

int main()
{
    vector<int> arr = {10, 10, 10};
    int count = numberOfInversions(arr,arr.size());
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    cout << count;
    return 0;
}