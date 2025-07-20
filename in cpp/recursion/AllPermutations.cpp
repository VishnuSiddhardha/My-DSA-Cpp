#include<bits/stdc++.h>
using namespace std;

void printAllPermutations(int index, int toSwap, vector<int> arr, vector<vector<int>> &result)
{
    if (index == arr.size())
    {
        result.push_back(arr);
        return;
    }
    for (int i = index; i < arr.size(); i++)
    {
        swap(arr[toSwap],arr[i]);
        printAllPermutations(index+1,toSwap+1,arr,result);
        swap(arr[toSwap],arr[index]);
    }
}

int main()
{
    vector<int> arr = {1,2,3,4};
    vector<vector<int>> result;

    printAllPermutations(0,0,arr,result);

    for (vector<int> vc : result)
    {
        for (int x : vc)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}