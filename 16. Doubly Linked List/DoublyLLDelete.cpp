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
    void deletehead(node *&h)
    {
        node *temp = h;
        h->next->prev = nullptr;
        h = h->next;
        delete (temp);
        return;
    }

public:
    void deletenode(node *&h, int pos)
    {
        if (pos < 1)
        {
            cout << "Enter a positive index" << endl;
            return;
        }
        if (!h)
        {
            cout << "list underflow" << endl;
            return;
        }
        if (!h->next)
        {
            delete (h);
            h = nullptr;
            return;
        }
        if (pos == 1)
        {
            deletehead(h);
            return;
        }
        int cnt = 1;
        node *curr = h;
        while (curr->next && curr->next->next && cnt < pos)
        {
            if (pos - cnt == 1)
            {
                node *temp = curr->next;
                curr->next->next->prev = curr;
                curr->next = curr->next->next;
                delete (temp);
                return;
            }
            curr = curr->next;
            cnt++;
        }
        if (pos - cnt == 1)
        {
            node *temp = curr->next;
            curr->next = nullptr;
            delete (temp);
            return;
        }
        if (pos - cnt > 1)
        {
            cout << "Position out of bound" << endl;
            return;
        }
    }
};
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int del = 1;
    dll list;
    node *head = list.create(arr);
    list.print(head);
    list.deletenode(head, del);
    list.print(head);
    list.deletenode(head, 4);
    list.print(head);
}