#include<bits/stdc++.h>
using namespace std;

int longestSuccessiveElements(vector<int>&a) {
    // Write your code here.
    unordered_map<int,int> mp;
    int maxLen = 0;
    int ele;
    for (int i = 0; i < a.size(); i++)
        mp[a[i]]++;
    
    for (int i = 0; i < a.size(); i++)
    {
        if (mp.count(a[i]-1))
            continue;
        else
        {
            ele = a[i];
            while (mp.count(ele))
            {
                ele++;
                maxLen++;
            }
        }
    }   
    return maxLen;
}

int main()
{
    vector<int> arr = {5, 8, 3, 2, 1, 4};
    int result = longestSuccessiveElements(arr);
    cout << result;
    return 0;
}


