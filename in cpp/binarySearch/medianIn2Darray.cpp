#include<bits/stdc++.h>
using namespace std;

int countSmallerEquals(vector<vector<int>> arr, int k) {
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        int low = 0, high = arr[i].size()-1;
        while (low <= high) {
            int mid = (low+high)/2;
            if (arr[i][mid] <= k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        count += low;
    }
    return count;
}

int median(vector<vector<int>> &mat) {
    
    int n = mat.size();
    int m = mat[0].size();
    int req = (n*m) / 2;

    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < n; i++) {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m-1]);
    }

    while (low <= high) {
        int mid = (low+high) / 2;
        int smallEqulas = countSmallerEquals(mat, mid);
        if (smallEqulas <= req) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<vector<int>> arr = {{1,3,4}, {2,6,9}, {3,6,9}};
    int med = median(arr);
    cout << "median is: " << med;
    return 0;
}