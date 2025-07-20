#include <bits/stdc++.h>
using namespace std;

struct Node
{
    pair<int, int> data;
    Node *next;
    Node(pair<int, int> t)
    {
        next = NULL;
        data = t;
    }
};

class MinStack
{
    Node *myStack;

public:
    MinStack()
    {
        myStack = NULL;
    }

    void push(int val)
    {
        if (myStack == NULL)
        {
            myStack = new Node({val, val});
        }
        else
        {
            Node *newNode = new Node({val, min(val, myStack->data.second)});
            newNode->next = myStack;
            myStack = newNode;
        }
    }

    void pop()
    {
        if (myStack == NULL)
            return;
        Node *temp = myStack;
        myStack = myStack->next;
        free(temp);
    }

    int top()
    {
        return myStack->data.first;
    }

    int getMin()
    {
        return myStack->data.second;
    }
};

int main()
{
    MinStack obj;

    return 0;
}