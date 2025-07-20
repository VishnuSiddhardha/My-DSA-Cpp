#include <bits/stdc++.h>
using namespace std;

void combinationalSum(int ind, vector<int> vc,vector<int> temp, int sum, vector<vector<int>> &result)
{
    if (ind == vc.size())
    {
        if (sum == 0)
        {
            result.push_back(temp);
        }
            return;
    }
    if (vc[ind] <= sum)
    {
        temp.push_back(vc[ind]);
        combinationalSum(ind, vc,temp, sum - vc[ind], result);
        temp.pop_back();
    }
    combinationalSum(ind + 1, vc,temp, sum, result);
}

int main()
{
    vector<int> arr = {2,3,6,7};
    vector<vector<int>> result;
    vector<int> temp;
    combinationalSum(0, arr,temp, 7, result);
    cout << "The sets are:\n";
    for (auto ele : result)
    {
        for (int x : ele)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}