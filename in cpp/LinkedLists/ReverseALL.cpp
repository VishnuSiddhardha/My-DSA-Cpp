// ListNode* reverseList(ListNode* head) {
//     ListNode* prev = NULL;
//     ListNode* cur = head;
//     ListNode* front;

//     while (cur != NULL) {
//         front = cur->next;
//         cur->next = prev;
//         prev = cur;
//         cur = front;
//     }
//     return prev;
// }