#include<bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat){
	// Write your code here.
    int size = mat.size()-1,ind = 0;
    int i = 0 , j = size, k = 0, l = size;
	while (ind < size/2)
    {
        if (i == size-ind)
        {
            ind++;
            i = ind;
            j = size-ind;
            k = ind;
            l = size-ind;
        }
        swap(mat[i][ind],mat[ind][j]);
        swap(mat[i][ind],mat[size-ind][k]);
        swap(mat[size-ind][k],mat[l][size-ind]);
        i++;
        j--;
        k++;
        l--;
    }
    
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    cout << "Before manipulation:\n";
    for (vector<int> arr : matrix)
    {
        for (int ele : arr)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    
    rotateMatrix(matrix);

    cout << "After manipulation:\n";
    for (vector<int> arr : matrix)
    {
        for (int ele : arr)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}