#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head->next == NULL) return head;

        ListNode *prev = head, *cur = head->next;
        head = head->next;
        ListNode *lastLinked = NULL;

        while (cur)
        {
            prev->next = cur->next;
            cur->next = prev;
            if (lastLinked) lastLinked->next = cur;
            lastLinked = prev;
            prev = prev->next;
            cur = prev->next;
        }
        return head;
    }
};

int main()
{

    return 0;
}