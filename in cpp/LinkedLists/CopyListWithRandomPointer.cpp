#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void traversal(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *convertArr2LL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

Node *copyRandomList(Node *head)
{
    if (head == NULL) return head;
    Node *temp = head;
    // insert new nodes in between the existing
    while (temp != NULL)
    {
        Node *newNode = new Node(temp->val);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }
    // connect the random pointers properly 
    temp = head;
    while (temp != NULL)
    {
        temp->next->random = temp->random->next;
        temp = temp->next->next;
    }
    // connect the next links again properly
    temp = head;
    Node *newHead = head->next, *temp2 = newHead;
    while (temp != NULL)
    {
        temp->next = temp->next->next;
        temp = temp->next;
        if (temp != NULL) {
            temp2->next = temp->next;
            temp2 = temp2->next;
        }
    }
    return newHead;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,67};
    Node *head = convertArr2LL(arr);
    traversal(head);
    head = copyRandomList(head);
    return 0;
}