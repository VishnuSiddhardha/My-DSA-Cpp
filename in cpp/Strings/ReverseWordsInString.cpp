#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    string result = "";
    int end = s.length()-1;
    while (end >= 0) {
        string temp = "";
        while (end >= 0 && s[end]  != ' '){
            temp = s[end] + temp;
            end--;
        }
        result += temp;
        while (end >= 0 && s[end] == ' ')
            end--;
        if (result.length() == 0 || end == -1) 
            continue;
        result =  result + " ";
    }
    return result;
}

int main()
{
    string st = " i like this program very much ";
    string result = reverseWords(st);
    cout <<"result is: " << result << "*";
    return 0;
}