#include <bits/stdc++.h>
using namespace std;

int minCandy(vector<int> &arr)
{
    // code here
    int sum = 1, i = 1;
    int n = arr.size();
    while (i < n)
    {
        if (arr[i] == arr[i-1]) {
            i++;
            sum += 1;
            continue;
        }
        int peak = 1;
        while (i < n && arr[i] > arr[i-1]) {
            peak += 1;
            sum += peak;
            i++;
        }
        int down = 1;
        while (i < n && arr[i] < arr[i-1]) {
            sum += down;
            down++;
            i++;
        }
        if (down > peak)
            sum += down-peak;
    }
    return sum;
}

int main()
{
    vector<int> arr = {};
    int res = minCandy(arr);
    cout << "Candys required are: " << res << endl;
    return 0;
}