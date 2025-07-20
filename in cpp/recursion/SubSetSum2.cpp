#include <bits/stdc++.h>
using namespace std;

// void subSetsWithOutDup(int ind, vector<int> arr, vector<int> temp, vector<vector<int>> &result,bool check)
// {
//     if (ind == arr.size())
//     {
//         result.push_back(temp);
//         return;
//     }

//     if (check &&  arr[ind] == arr[ind-1]) {
//         subSetsWithOutDup(ind+1,arr,temp,result,true);
//     }
//     else
//     {
//         temp.push_back(arr[ind]);
//         subSetsWithOutDup(ind+1,arr,temp,result,false);
//         temp.pop_back();
//         subSetsWithOutDup(ind+1,arr,temp,result,true);
//     }
// }

void subSetsWithOutDup(int ind, vector<int> arr, vector<int> temp, vector<vector<int>> &result)
{   
    result.push_back(temp);

    for (int i = ind; i < arr.size(); i++)
    {
        if (i > ind && arr[i] == arr[i-1]) {
            continue;
        }
        temp.push_back(arr[i]);
        subSetsWithOutDup(i+1, arr, temp, result);
        temp.pop_back();
    }
}

int main()
{
    vector<int> arr = {1, 2, 2};
    vector<vector<int>> res;
    vector<int> temp;
    subSetsWithOutDup(0, arr, temp, res);
    for (vector<int> x : res)
    {
        for (int ele : x)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}