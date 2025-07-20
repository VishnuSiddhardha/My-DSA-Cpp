#include<bits/stdc++.h>
using namespace std;

int getMaxElementRow(vector<vector<int>> arr, int col)
{
    int ind = 0, ele = arr[0][col];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i][col] > ele) {
            ele = arr[i][col];
            ind = i;
        }
    } 
    return ind;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int low = 0, high = mat[0].size()-1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = getMaxElementRow(mat, mid);
        
        int left = mid == 0 ? -1 : mat[row][mid-1];
        int right = mid == mat[0].size()-1 ? -1 : mat[row][mid+1];

        if (mat[row][mid] > left && mat[row][mid] > right){
            return {row,mid};
        }
        else if (mat[row][mid] < left) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return {-1,-1};
}

int main()
{
    return 0;
}