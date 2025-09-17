#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int num, vector<int> &dp) {
        if (num == 1) return 0;
        if (dp[num] != -1) return dp[num];
        
        if (!(num&1)) return 1 + solve(num>>1, dp);
        int plus = solve(num+1, dp);
        int minus = solve(num-1, dp);
        return dp[num] = min(plus, minus);
    }
public:

    int integerReplacement(int n)
    {   
        // bfs
        // queue<int> q;
        // int count = 0;
        // q.push(n);
        // while (true) 
        // {
        //     int size = q.size();
        //     while (size) {
        //         int nums = q.front();
        //         q.pop();
        //         if (nums == 1) return count+1;
        //         if (nums&1) {
        //             q.push(nums-1);
        //             q.push(nums+1);
        //         }
        //         else q.push(nums/2);
        //         size--;
        //     }
        //     count++;
        // }
        // return 0;

        // memoization
        vector<int> dp(n+1, -1);
        return solve(n, dp);
        

        // bit manipulation
        long long num = n;
        int count = 0;
        while (num != 1)
        {
            if (num&1) {
                if (num!= 3 && num&2) num += 1;
                else num -= 1;
            }
            else num = num >> 1;
            count++;
        }
        return count;
    }
};

int main()
{

    return 0;
}