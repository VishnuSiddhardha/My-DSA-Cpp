#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
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
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node * temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}
Node *segregate(Node *head)
{

    // Add code here
    vector<int> arr;
    Node* temp = head;
    while (temp == NULL) {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    int low = 0, mid = 0, high = arr.size()-1;
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 2) {
            swap(arr[mid],arr[high]);
            high--;
        }
        else mid++;
    }

    temp = head;
    int i = 0;
    while (temp != NULL) {
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }
    return head;
}

int main()
{
    return 0;
}