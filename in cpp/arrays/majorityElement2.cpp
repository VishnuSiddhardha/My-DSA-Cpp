#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int ele1 = 0, ele2 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (count1 == 0 && nums[i] != ele2) {
            ele1 = nums[i];
            count1++;
        }
        else if (count2 == 0 && nums[i] != ele1) {
            ele2 = nums[i];
            count2++;
        }
        else if (nums[i] == ele1) count1++;
        else if (nums[i] == ele2) count2++;
        else {
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for(auto x : nums) {
        if (x == ele1) count1++;
        else if (x == ele2) count2++;
    }
    int mini = nums.size()/3;
    vector<int> res;
    if (count1 > mini) res.push_back(ele1);
    if (count2 > mini) res.push_back(ele2);
    return res;
}

int main()
{
    return 0;
}