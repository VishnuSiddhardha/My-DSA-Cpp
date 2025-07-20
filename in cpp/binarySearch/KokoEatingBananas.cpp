#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int h, int k) {
    long long hours = 0;
    for (int i = 0; i < arr.size(); i++) {
        cout << "K value: " << k << endl;
        cout << "hours+= " << ceil((double)arr[i] / (double)k ) << endl;
        hours += ceil((double)arr[i] / (double)k );
    }
    cout << "hours final = " << hours << endl;
    return hours <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int mini = piles[0], maxi = piles[0];

    for (int i = 1; i < piles.size(); i++) {
        mini = min(mini,piles[i]);
        maxi = max(maxi,piles[i]);
    }

    int low = 1, high = maxi;
    int ans = maxi;
    while (low <= high) {
        int mid = (low+high)/2;
        if (isPossible(piles,h,mid)) {
            ans = mid;
            high = mid-1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main()
{
    vector<int> arr = {805306368,805306368,805306368};
    int k = minEatingSpeed(arr,1000000000);
    cout << "K is: " << k;
    return 0;
}