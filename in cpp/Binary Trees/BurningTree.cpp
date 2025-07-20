#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

int minTime(Node *root, int target)
{
    // code here
    unordered_map<int, Node*> mp;
    Node *targetNode;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *top = q.front();
            q.pop();
            if (top->data == target) targetNode = top;
            if (top->left) {
                mp[top->left->data] = top;
                q.push(top->left);
            }
            if (top->right) {
                mp[top->right->data] = top;
                q.push(top->right);
            }
        }
    }
    int time = 0;
    unordered_set<int> visited;
    q.push(targetNode);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *top = q.front();
            q.pop();
            visited.insert(top->data);
            Node *left = top->left, *right = top->right;
            if (left && (visited.find(left->data) == visited.end()))
            {
                q.push(left);
            } 
            if (right && (visited.find(right->data) == visited.end()))
            {
                q.push(right);
            }
            if ((mp.find(top->data) != mp.end()) && (visited.find(mp[top->data]->data) == visited.end()))
            {
                q.push(mp[top->data]);
            }
        }
        time++;
    }
    return time;
}

int main()
{
    return 0;
}