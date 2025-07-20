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

ListNode *oddEvenList(ListNode *head)
{
    ListNode *curNode = head->next->next;
    if (!curNode) return head;
    ListNode *oddNode = head;
    ListNode *evenNode = head->next;

    while (curNode != NULL)
    {
        evenNode->next = curNode->next;
        evenNode = evenNode->next;
        curNode->next = oddNode->next;
        oddNode->next = curNode;
        oddNode = oddNode->next;
        curNode = evenNode == NULL ? NULL : evenNode->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8};
    ListNode *head = convertArr2LL(arr);
    cout << "before:\n";
    traversal(head);
    head = oddEvenList(head);
    cout << "after:\n";
    traversal(head);
    return 0;
}