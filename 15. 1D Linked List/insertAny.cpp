#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *ptr;

public:
    node(int newdata, node *newptr)
    {
        data = newdata;
        ptr = newptr;
    }

public:
    node(int dataonly)
    {
        data = dataonly;
        ptr = nullptr;
    }
};
class ll
{
public:
    node *create(int arr[], int size)
    {
        if (size != 0)
        {
            node *head = new node(arr[0]);
            node *mover = head;
            for (int i = 1; i < size; i++)
            {
                node *temp = new node(arr[i]);
                mover->ptr = temp;
                mover = temp;
            }
            return head;
        }
        else
            return nullptr;
    }

public:
    void print(node *h)
    {
        if (h)
        {
            node *temp = h;
            while (temp)
            {
                cout << " " << temp->data;
                temp = temp->ptr;
            }
            cout << endl;
        }
        else
            cout << "List doesnt exist" << endl;
    }

private:
    void inserthead(node *&h, int ins)
    {
        node *newhead = new node(ins, h);
        h = newhead;
    }

    /*private:
    void inserttail(node *h, int ins)
    {
        node *newtail = new node(ins);
        while (h->ptr)
        {
            h = h->ptr;
        }
        h->ptr = newtail;
    }*/

public:
    void insert(node *&h, int ins, int pos)
    {
        if (pos < 1)
        {
            cout << "Enter a valid (+ve) position" << endl;
            return;
        }
        if (!h)
        {
            node *newnode = new node(ins);
            h = newnode;
            return;
        }
        int cnt = 1;
        if (pos == 1)
        {
            inserthead(h, ins);
            return;
        }
        node *curr = h;
        while ((cnt < pos) && curr->ptr)
        {
            if (cnt == pos - 1)
            {
                node *newnode = new node(ins);
                newnode->ptr = curr->ptr;
                curr->ptr = newnode;
                return;
            }
            cnt++;
            curr = curr->ptr;
        }
        if ((cnt + 1) == pos)
        {
            node *newtail = new node(ins);
            curr->ptr = newtail;
            return;
        }
        else
        {
            cout << "postion out of bound" << endl;
            return;
        }
    }
};
int main()
{
    int arr[] = {};
    int size = sizeof(arr) / sizeof(int);
    int val = 69;
    int pos = 7;
    ll list;
    node *head = list.create(arr, size);
    list.insert(head, val, pos);
    list.print(head);
}