#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int low = 0, high = n-1;
    int row = -1;

    while (low <= high) {
        int mid = (low+high) / 2;
        if (matrix[mid][0] > target) {
            high = mid - 1;
        }
        else if (matrix[mid][0] <= target && matrix[mid][m-1] >= target) {
            row = mid;
            break;
        } 
        else {
            low = mid + 1;
        }
    }
    if (row == -1) return false;

    low = 0, high = m-1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (matrix[row][mid] == target){ return true; }
        else if (matrix[row][mid] > target) { high = mid - 1;}
        else {low = mid + 1; }
    }
    return false;
}

int main()
{
    vector<vector<int>> arr = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    if (searchMatrix(arr, 23))
        cout << "Found";
    else
        cout << "not Found";
    return 0;
}