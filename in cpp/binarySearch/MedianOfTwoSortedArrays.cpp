#include<bits/stdc++.h>
using namespace std;

double medianOf2(vector<int>& a, vector<int>& b) {
    // Your code goes here
    int n1 = a.size(), n2 = b.size();
    if (n1 > n2) return medianOf2(b,a);

    int low = 0, high = n1;
    int left = (n1+n2+1)/2;

    while (low <= high) {
        int mid1 = (low+high)/2;
        int mid2 = left - mid1;

        int l1 = mid1 == 0 ? INT_MIN : a[mid1-1];
        int r1 = mid1 == n1 ? INT_MAX : a[mid1];

        int l2 = mid2 == 0 ? INT_MIN : b[mid2-1];
        int r2 = mid2 == n2 ? INT_MAX : b[mid2];

        if (l1 <= r2 && l2 <= r1){
            if ((n1+n2)%2 == 1) return max(l1,l2);
            return (double) (max(l1,l2) + min(r1,r2)) / 2.0;
        }
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
        
    }
    return 0;
}

// double medianOf2(vector<int> &a, vector<int> &b) {
//     int n = a.size(), m = b.size();
    
//       // If a[] has more elements, then call medianOf2 
//       // with reversed parameters
//     if (n > m)
//         return medianOf2(b, a);
  
//     int lo = 0, hi = n;
//     while (lo <= hi) {
//         int mid1 = (lo + hi) / 2;
//         int mid2 = (n + m + 1) / 2 - mid1;

//         // Find elements to the left and right of partition in a[]
//         int l1 = (mid1 == 0 ? INT_MIN : a[mid1 - 1]);
//         int r1 = (mid1 == n ? INT_MAX : a[mid1]);

//         // Find elements to the left and right of partition in b[]
//         int l2 = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);
//         int r2 = (mid2 == m ? INT_MAX : b[mid2]);

//         // If it is a valid partition
//         if (l1 <= r2 && l2 <= r1) {
          
//               // If the total elements are even, then median is 
//               // the average of two middle elements
//             if ((n + m) % 2 == 0)
//                 return (max(l1, l2) + min(r1, r2)) / 2.0;
          
//               // If the total elements are odd, then median is 
//              // the middle element
//             else
//                 return max(l1, l2);
//         }

//         // Check if we need to take lesser elements from a[]
//         if (l1 > r2)
//             hi = mid1 - 1;
      
//         // Check if we need to take more elements from a[]
//         else
//             lo = mid1 + 1;
//     }
//     return 0;
// }

int main()
{
    vector<int> a = {1,2};
    vector<int> b = {3,4};
    cout << medianOf2(a,b);
    return 0;
}