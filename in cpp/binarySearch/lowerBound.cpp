#include<bits/stdc++.h>
using namespace std;

int searchInseartPosition(vector<int> arr, int m)
{
    int low = 0, high = arr.size()-1;
    while (low <= high){
        int mid = (low+high)/2;
        if (arr[mid] == m) return mid;
        if (arr[mid] > m) {
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return high+1;
}

int lowerBound(vector<int> arr, int n, int x){
    int low = 0, high = n-1;
    int lb = n;
    while (low <= high){
        int mid = (low+high)/2;
        if (arr[mid] >= x) {
            lb = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return lb;
}

int main()
{
    vector<int> arr = {1 ,2 ,2 ,3 ,3 ,5};
    int lbound = lowerBound(arr,arr.size(),2);
    cout << lbound;
    return 0;
}