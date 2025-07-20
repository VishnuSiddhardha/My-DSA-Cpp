#include<bits/stdc++.h>
using namespace std;

bool isPossbile(vector<int> arr, int days, int capacity) {
    cout << "For capacity is : " << capacity << endl;
    int curCap = arr[0], totalDays = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] + curCap > capacity) {
            cout << "i: " << i << " arr[i]: " << arr[i] << " curCap: " << curCap << endl;
            curCap = 0;
            totalDays++;
        }
        curCap += arr[i];
    }
    cout << "totalDays <= days: " << totalDays << " " << days << endl;
    return totalDays <= days;
}

int totalSum(vector<int> arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i ++)
        sum += arr[i];
    return sum;
}

int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = totalSum(weights);

    while (low <= high) {
        int mid = (low+high)/2;
        if (isPossbile(weights, days, mid)) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {3,2,2,4,1,4};
    int capacity = shipWithinDays(arr, 3);
    cout << "capacity: " << capacity;

    return 0;
}