#include <bits/stdc++.h>
using namespace std;

bool isPossbile(vector<int> arr, int cows, int distance) {
    int ind = 0;
    cows--;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] - arr[ind] >= distance) {
            cows--;
            ind = i;
        }
    }
    return cows <= 0;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls[stalls.size()-1] - stalls[0];

    while (low <= high) {
        int mid = (low+high)/2;
        if (isPossbile(stalls, k, mid)) {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return high;
}

int main()
{
    vector<int> arr = {10, 1, 2, 7, 5};
    int distance = aggressiveCows(arr, 3);
    cout << distance;
    return 0;
}