#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
};

void traversal(Node *head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* convertArr2LL(vector<int> arr) {
    Node *head = new Node(arr[0]);
    head->prev = NULL;

    Node *mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node * temp = new Node(arr[i]);
        temp->prev = mover;
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}
void deleteAllOccurOfX(struct Node** head_ref, int x) {
    // Write your code here
    Node *temp = *head_ref;
    while (temp != NULL) {
        if (temp->data == x) {
            Node* remove = temp;
            if (temp->prev == NULL) {
                temp = temp->next;
                if (temp != NULL) temp->prev = NULL;
                *head_ref = temp;
                delete remove;
            }
            else if (temp->next == NULL) {
                temp->prev->next = NULL;
                temp = NULL; 
                delete remove;    
            }
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp = temp->next;
            }
        }
        else {
            temp = temp->next;
        }
    }
    cout << "After deletion\n";
    traversal(*head_ref);
    cout << "end\n";
}



int main()
{
    vector<int> arr = {2,10,2,2,8,2,4,5,6,2,4,5,2};
    Node *head = convertArr2LL(arr);
    deleteAllOccurOfX(&head,2);
    return 0;
}