#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr) {
    int low = 0, high = arr.size();

    while (low <= high) {
        int mid = (low+high) / 2;
        if (arr[mid] >= 1) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

int rowWithMax1s(vector<vector<int>> &arr) {
    // code here
    int count = 0, index = -1;
    for (int i = 0; i < arr.size(); i++) {
        int temp = arr[0].size() - lowerBound(arr[i]);
        if (temp > count){
            count = temp;
            index = i;
        }
    }
    return index;
}

int main()
{
    vector<int> arr = {0,0,0,0};
    cout << lowerBound(arr);
    return 0;
}