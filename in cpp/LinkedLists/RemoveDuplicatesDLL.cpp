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

Node *removeDuplicates(struct Node *head)
{
    // Your code here
    Node *temp = head->next;
    while (temp != NULL)
    {
        if (temp->data == temp->prev->data)
        {
            Node *remove = temp;
            temp->prev->next = temp->next;
            if (temp->next != NULL) temp->next->prev = temp->prev;
            temp = temp->next;
            delete remove;
        }
        else temp = temp->next;
    }
    return head;
}

int main()
{
    return 0;
}