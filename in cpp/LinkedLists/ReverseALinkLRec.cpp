#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void traversal(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode *convertArr2LL(vector<int> arr)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

ListNode *reverseALinkedListRec(ListNode *head) 
{
    if (head == NULL || head->next == NULL)
        return head;
    else {
        ListNode *newHead = reverseALinkedListRec(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6};
    ListNode *head = convertArr2LL(arr);
    
    head = reverseALinkedListRec(head);
    traversal(head);

    
    return 0;
}