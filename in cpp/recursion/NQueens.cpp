#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<vector<bool>> arr, int col, int row)
{
    for (int i = col - 1; i >= 0; --i)
    {
        if (arr[row][i])
            return false;
    }
    for (int i = row - 1, j = col - 1; (i >= 0 && j >= 0); --i, --j)
    {
        if (arr[i][j])
            return false;
    }
    for (int i = row + 1, j = col - 1; (i < arr.size() && j >= 0); ++i, --j)
    {
        if (arr[i][j])
            return false;
    }

    return true;
}

void NQueens(int col, vector<vector<bool>> table, vector<vector<vector<bool>>> &result)
{
    if (col == table.size())
    {
        result.push_back(table);
        return;
    }
    for (int j = 0; j < table.size(); j++)
    {
        if (isPossible(table, col, j))
        {
            table[j][col] = true;
            NQueens(col + 1, table, result);
            table[j][col] = false;
        }
    }
    return;
}

int main()
{
    vector<vector<vector<bool>>> result;
    int nQueens = 5;
    vector<vector<bool>> table(nQueens, vector<bool>(nQueens));
    for (vector<bool> &vc : table)
    {
        fill(vc.begin(), vc.end(), false);
    }

    NQueens(0, table, result);
    for (vector<vector<bool>> table : result)
    {
        for (vector<bool> row : table)
        {
            for (bool element : row)
            {
                if (element)
                    cout << "Q  ";
                else
                    cout << "-  ";
            }
            cout << endl;
        }
        cout << endl
             << endl;
    }
    return 0;
}