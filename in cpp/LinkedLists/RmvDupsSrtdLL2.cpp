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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy= new ListNode(-1);
        ListNode *res=dummy;
        ListNode *temp=head;
        // ListNode *front,*back=NULL;
        // while(temp!=NULL)
        // {
        //     front=temp->next;
        //     // backNode != curNode != frontNode
        //     if((back==NULL||back->val!=temp->val)&&(front==NULL||front->val!=temp->val)){
        //         res->next=new ListNode(temp->val);
        //         res=res->next;
            
        //     }
        //     back=temp;
        //     temp=temp->next;
        // }
        // return dummy->next;
        while(temp)
        {
            if(temp->next&&temp->val==temp->next->val){ //is duplicate?
                int dup=temp->val;
                while(temp&&temp->val!=dup){ // skip all duplicates
                    temp=temp->next;
                }
            }
            else{
                res->next=temp;
                res=res->next;
                temp=temp->next;
            } // check is there a small bug 
        }
        return dummy->next;
    }
};

int main()
{

    return 0;
}