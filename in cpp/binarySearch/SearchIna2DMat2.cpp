#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = 0, col = arr[0].size()-1;
        while (row < arr.size() && col >= 0)
        {
            if (arr[row][col] == target)
                return true;
            else if (arr[row][col] > target)
                col--;
            else row++;
        }
        return false;
    }
}

int main(){
    return 0;
}