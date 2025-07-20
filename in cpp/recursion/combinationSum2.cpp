#include <bits/stdc++.h>
using namespace std;

// void combinationSumTwo(int ind,int target,vector<int> arr,vector<int> temp,vector<vector<int>> &result)
// {
//     if (ind == arr.size()) {
//         if (target == 0) {
//             result.push_back(temp);
//         }
//         return;
//     }
//     temp.push_back(arr[ind]);
//     combinationSumTwo(ind+1,target-arr[ind],arr,temp,result);
//     temp.pop_back();
//     combinationSumTwo(ind+1,target,arr,temp,result);
// }

void combinationSumTwo(int ind, int sum, vector<int> arr, vector<int> temp, vector<vector<int>> &result)
{
    
    if (sum == 0)
    {
        result.push_back(temp);
        return;
    }
    for (int i = ind; i < arr.size(); i++)
    {
        if (arr[i] > sum) break;
        if (i == ind || arr[i] != arr[i-1])
        {
            temp.push_back(arr[i]);
            combinationSumTwo(i + 1, sum - arr[i], arr, temp, result);
            temp.pop_back();
        }
    }
}

int main()
{
    vector<int> arr = {2,5,2,1,2};
    vector<vector<int>> result;
    vector<int> temp;
    sort(arr.begin(), arr.end());
    combinationSumTwo(0, 5, arr, temp, result);
    cout << "The sets are:\n";
    for (vector<int> ele : result)
    {
        for (int x : ele)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}