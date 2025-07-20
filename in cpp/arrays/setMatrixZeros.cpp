#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	// Write your code here.
    int col0 = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                if (j == 0) { col0 = 0;}
                else
                    matrix[0][j] = 0;

                matrix[i][0] = 0;
            }
        }
    }
    cout << "check point one: " << matrix[0][0] << endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    if (col0 == 0) {
        col0 = matrix[0][0];
        for (int i = 0; i < n; i++)
            matrix[i][0] = 0;
    }
    if (col0 == 0) {
        for (int i = 0; i < m; i++)
            matrix[0][i] = 0;
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = { {-4 ,9  ,1, 3 ,2 ,11, 6}, 
                                    {2, -8 , 7, 8, 10, -5, 5},
                                    {1,  8,  -4, 0, 9, 7, -4 },
                                    {1 ,-7,  11, 5, 0, -4, -6}, 
                                    {-7, 4 , 4, 4 ,2 ,1, 9} ,
                                    {5  ,11, -1 ,-8 ,-1, 6, -4} ,
                                    {11, -8, -6, 2, 3 ,10, 7}, 
                                    {0 , 1 , 6, 8 ,3, 9, 6 },
                                    {1 ,-5 ,0 ,2, 5, -6, 5 },
                                    {4,  1,  3, -6, 7 ,1, -4}};

    cout << "Before manipulation:\n";
    for (vector<int> arr : matrix)
    {
        for (int ele : arr)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    
    matrix = zeroMatrix(matrix,10,7);

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