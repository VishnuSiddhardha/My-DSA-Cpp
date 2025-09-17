#include <bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>> &MATRIX)
{
    // Write your code here.
    int n = MATRIX.size() - 1, m = MATRIX[0].size() - 1;
    int ind = 0;
    vector<int> result;
    while (ind <= n / 2)
    {
        for (int i = ind; i <= m - ind; i++)
        {
            result.push_back(MATRIX[ind][i]);
        }
        for (int j = 1 + ind; j <= n - ind; j++)
        {
            result.push_back(MATRIX[j][m - ind]);
        }
        for (int k = m - 1 - ind; k >= ind; k--)
        {
            if (MATRIX[n - ind][k] == 6)
                cout << "one " << ind << endl;
            ;
            result.push_back(MATRIX[n - ind][k]);
        }
        for (int l = n - 1 - ind; l > ind; l--)
        {
            result.push_back(MATRIX[l][ind]);
        }
        ind++;
    }
    return result;
}

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        if (matrix.empty())
            return res;

        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while (top <= bottom && left <= right)
        {
            // Traverse from left → right
            for (int j = left; j <= right; j++)
                res.push_back(matrix[top][j]);
            top++;

            // Traverse from top → bottom
            for (int i = top; i <= bottom; i++)
                res.push_back(matrix[i][right]);
            right--;

            // Traverse from right → left
            if (top <= bottom)
            {
                for (int j = right; j >= left; j--)
                    res.push_back(matrix[bottom][j]);
                bottom--;
            }

            // Traverse from bottom → top
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                    res.push_back(matrix[i][left]);
                left++;
            }
        }

        return res;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    cout << "Matrix:\n";
    for (vector<int> arr : matrix)
    {
        for (int ele : arr)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    vector<int> res = spiralMatrix(matrix);

    for (int ele : res)
        cout << ele << " ";
    return 0;
}