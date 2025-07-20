#include<bits/stdc++.h>
using namespace std;

void printSubSeq(vector<int> v,vector<int> temp,int len,int ind,int sum,int req)
{
    if (ind == len)
    {
        if (sum == req)
        {
            cout << "sum: "<< req << " subset : ";
            for (int x : temp)
            cout << x << " ";
            cout << endl;
        }
        return;
    }
    temp.push_back(v[ind]);
    printSubSeq(v,temp,len,ind+1,sum,req+v[ind]);
    temp.pop_back();
    printSubSeq(v,temp,len,ind+1,sum,req);

}

 void callSub(vector<int> v,int sum)
 {
    int len = v.size();
    vector<int> t;
    printSubSeq(v,t,len,0,sum,0);
 }

int main()
{
    vector<int> arr = {1,2,1};
    int sum = 2;
    callSub(arr,sum);
    return 0;
}