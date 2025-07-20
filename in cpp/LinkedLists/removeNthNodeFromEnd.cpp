#include<bits/stdc++.h>
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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int count = 1;
    ListNode *forBack = head, *forFront = head;
    while (forBack->next != NULL) 
    {
        if (count > n) {
            forFront = forFront->next;
        }
        forBack = forBack->next;
        count++;
    }
    ListNode *temp;
    if (n == count) {
        temp = head;
        head = head->next;
    }
    else {
        temp = forFront->next;
        forFront->next = forFront->next->next;
    }
    free(temp);
    return head;

}

int main()
{
    vector<int> arr = {1,2,3,4,5,6};
    ListNode *head = convertArr2LL(arr);
    cout << "before:\n";
    traversal(head);

    head = removeNthFromEnd(head,2);

    cout << "after:\n";
    traversal(head);
    return 0;
}