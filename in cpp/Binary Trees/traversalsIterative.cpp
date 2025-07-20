#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

vector<int> inOrder(Node *root)
{
    // Your code here
    vector<int> inorder;
    stack<Node*> st;
    Node* node = root;
    while (true)
    {
        if (node) 
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty()) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    return inorder;
}

vector<int> preorder(Node *root)
{
    // write code here
    vector<int> ans;
    if (root == NULL)
        return ans;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *top = st.top();
        st.pop();
        if (top->right)
            st.push(top->right);
        if (top->left)
            st.push(top->left);
        ans.push_back(top->data);
    }
    return ans;
}

vector<int> postOrder2Stack(Node *root)
{
    stack<Node*> st1;
    stack<int> st2;
    st1.push(root);
    while (!st1.empty())
    {
        Node *temp = st1.top();
        st1.pop();
        st2.push(temp->data);
        if (temp->left) st1.push(temp->left);
        if (temp->right) st1.push(temp->right);
    }
    vector<int> ans;
    while (!st2.empty())
    {
        ans.push_back(st2.top());
        st2.pop();
    }
    return ans;
}

// This is one approch
// can also have different approch with
// same time and space complexity and also easy to understand
// it is > postOrder-> left, right, root
// reverse it root, right, left
// solve it, reverse it again and get the final answer
vector<int> postOrder1Stack(Node* root)
{
    vector<int> ans;
    stack<Node*> st;
    Node* cur = root;

    while (cur != NULL || !st.empty())
    {
        if (cur)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            Node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else
            {
                cur = temp;
            }
        }
    }
}

int main()
{
    return 0;
}