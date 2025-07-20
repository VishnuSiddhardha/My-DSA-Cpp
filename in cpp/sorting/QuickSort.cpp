#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr,int low, int high)
{
    int pivot = arr[low], i = low+1, j = high;
    while (i <= j)
    {
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;
        if (i < j) swap(arr[i],arr[j]);
    }
    swap(arr[j],arr[low]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low >= high) return;
    int j = partition(arr, low, high);
    quickSort(arr,low,j-1);
    quickSort(arr,j+1,high);
}

int main()
{
    vector<int> arr = {5,4,3,2,1,7,8,92,42,3};

    for (int x : arr)
        cout << x << " ";
    cout << endl;

    quickSort(arr,0,arr.size()-1);

    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}