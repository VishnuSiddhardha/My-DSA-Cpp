#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

void traversal(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *convertArr2LL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    head->prev = NULL;

    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        temp->prev = mover;
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    // code here
    vector<pair<int, int>> result;
    Node *start = head, *end = head;
    // assign pointer to the end of the list
    while (end->next != NULL)
    {
        end = end->next;
    }
    // 2 pointer approch for finding pairs
    while (start != end && start->prev != end)
    {
        int sum = start->data + end->data;
        if (sum == target)
        {
            result.push_back({start->data, end->data});
            start = start->next;
            end = end->prev;
        }
        else if (sum > target)
        {
            end = end->prev;
        }
        else
        {
            start = start->next;
        }
    }
    return result;
}

int main()
{
    return 0;
}