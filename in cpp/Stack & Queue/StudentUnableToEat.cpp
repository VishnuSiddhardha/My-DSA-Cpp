#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int n = students.size();
        queue<int> qu;
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (students[j] == sandwiches[i])
                i++;
            else
                qu.push(j);
        }
        int size = qu.size();
        int checkSize = size;
        while(!qu.empty())
        {
            int idx = qu.front();
            qu.pop();
            if (students[idx] == sandwiches[i])
                i++;
            else 
                qu.push(idx);
            
            size--;
            if (size == 0){ // a kind of one complete iteration is completed
                if(checkSize == qu.size()) // if the size doesn't change
                    return qu.size();
                size = qu.size();
                checkSize = size;
            }
        }
        return qu.size();
    }
};

int main()
{

    return 0;
}