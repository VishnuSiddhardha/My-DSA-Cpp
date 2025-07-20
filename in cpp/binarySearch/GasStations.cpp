#include<bits/stdc++.h>
using namespace std;

// double minimiseMaxDistance(vector<int> &arr, int k){
// 	// Write your code here.	
//     vector<int> howMany(arr.size()-1, 0);
//     for (int j = 0; j < k; j++) {
// 		long double maxDist = -1;
//     	int index = -1;
//         for (int i = 1; i < arr.size(); i++)
//         {
//             long double curDist = arr[i] - arr[i-1];
//             long double sectionLength = curDist/(long double)(howMany[i]+1);
//             if (sectionLength > maxDist) {
//                 index = i;
//                 maxDist = sectionLength;
//             }
//         }
//         howMany[index]++;
//     }
//     long double ans = -1;
//     for (int i = 1; i < arr.size(); i++){
//         long double distance = (arr[i] - arr[i-1]);
//         long double sectionLen = distance/(long double)(howMany[i]+1);
//         ans = max(ans,sectionLen);
//     }
//     return ans;
// }


// double minimiseMaxDistance(vector<int> &arr, int k) {
//     priority_queue<pair<long double, int>> pq;
//     int n = arr.size();
//     vector<int> howMany(n-1, 0);
//     for (int i = 0; i < n-1; i++) {
//         pq.push({arr[i+1] - arr[i], i});
//     }
//     for (int gasStation = 1; gasStation <= k; gasStation++) {
//         auto temp = pq.top();
//         pq.pop();
//         int secInd = temp.second;
//         howMany[secInd]++;
//         long double iniDiff = arr[secInd + 1] - arr[secInd];
//         long double secLength = iniDiff / (long double)(howMany[secInd] + 1);
//         pq.push({secLength, secInd});
//     }

//     return pq.top().first;
// }

int noOfStations(vector<int> arr, long double distance) {
    int stations = 0;
    
}

double minimiseMaxDistance(vector<int> &arr, int k) {
    int low = 0;
    int high = arr[arr.size()-1] - arr[0];
    
    while (high - low >= 1e-6) 
    {
        long double mid = (low+high)/2;
        if (noOfStations(arr, mid) > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
}


int main()
{
    double test = 1e-2;
    cout << test;
    return 0;
}