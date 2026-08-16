#include <iostream>
#include <vector>
using namespace std;
class node
{
public:
    node *prev;
    int data;
    node *next;

public:
    node(node *previous, int value, node *nextp)
    {
        prev = previous;
        data = value;
        next = nextp;
    }

public:
    node(node *previous, int value)
    {
        prev = previous;
        data = value;
        next = nullptr;
    }

public:
    node(int value, node *nextp)
    {
        prev = nullptr;
        data = value;
        next = nextp;
    }

public:
    node(int value)
    {
        prev = nullptr;
        data = value;
        next = nullptr;
    }
};
class dll
{
public:
    node *create(vector<int> &arr)
    {
        int size = arr.size();
        if (size != 0)
        {
            node *head = new node(arr[0]);
            node *copy = head;
            for (int i = 1; i < size; i++)
            {
                node *temp = new node(arr[i]);
                temp->prev = copy;
                copy->next = temp;
                copy = temp;
            }
            return head;
        }
        return nullptr;
    }

public:
    void print(node *head)
    {
        if (head)
        {
            while (head)
            {
                cout << head->data << " ";
                head = head->next;
            }
            cout << endl;
            return;
        }
        cout << "List doesn't exits" << endl;
        return;
    }

private:
    void inserthead(node *&h, int val)
    {
        node *newhead = new node(val, h);
        newhead->next->prev = newhead;
        h = newhead;
        return;
    }

public:
    void insertnode(node *&h, int val, int pos)
    {
        if (pos < 1)
        {
            cout << "Enter a positive index" <<endl;
            return;
        }
        if (!h)
        {
            node *newnode = new node(val);
            h = newnode;
            return;
        }
        if (h && pos == 1) // ony pass if head exists
        {
            inserthead(h, val);
            return;
        }
        if (!h->next && pos >= 2) // out of bounds default to tail insertion
        {
            node *newnode = new node(h, val);
            h->next = newnode;
            return;
        }
        int cnt = 1;
        node *curr = h;
        while (curr->next && cnt < pos)
        {
            if (pos - cnt == 1)
            {
                node *newnode = new node(curr, val, curr->next);
                curr->next->next->prev = newnode;
                curr->next = newnode;
                return;
            }
            curr = curr->next;
            cnt++;
        }
        if (pos - cnt >= 1) // out of bounds default to tail insertion
        {
            node *newnode = new node(curr, val);
            curr->next = newnode;
            return;
        }
    }
};
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int val = 2;
    int pos = 1;
    dll list;
    node *head = list.create(arr);
    list.print(head);
    list.insertnode(head, 34, 0);
    list.print(head);
    list.insertnode(head, 0, 1);
    list.print(head);
    list.insertnode(head, 69, 3);
    list.print(head);
    list.insertnode(head, 99, 8);
    list.print(head);
    list.insertnode(head, 99, 1000);
    list.print(head);
}