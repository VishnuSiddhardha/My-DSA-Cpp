#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> st1, st2;
    public:
        MyQueue() {
            
        }
        
        void push(int x) {
            st1.push(x);
        }
        
        int pop() {
            if (st2.empty()) {
                while (!st1.empty()) {
                    st2.push(st1.top());
                    st1.pop();
                }
            }
            int ele = st2.top();
            st2.pop();
            return ele;
        }
        
        int peek() {
            if (st2.empty())
                while (!st1.empty()) {
                    st2.push(st1.top());
                    st1.pop();
                }
            return st2.top();
        }

        
        bool empty() {
            return st1.empty() && st2.empty();
        }
    };

int main()
{
    return 0;
}