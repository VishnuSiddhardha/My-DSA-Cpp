#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

vector<Node *> findPreSuc(Node *root, int key)
{
    // code here
    vector<Node*> res;
    Node *prec = NULL;
    Node *succ = NULL;
    // for finding predecessor
    Node *temp = root;
    while (temp != NULL)
    {
        if (temp->data < key){
            prec = temp;
            temp = temp->right;
        }
        else
            temp = temp->left;  

    }
    temp = root;
    while (temp != NULL)
    {
        if (temp->data > key)
        {
            succ = temp;
            temp = temp->left;
        }
        else
            temp = temp->right;
    }
    
    res[0] = prec;
    res[1] = succ;
    return res;
}

int main()
{
    return 0;
}