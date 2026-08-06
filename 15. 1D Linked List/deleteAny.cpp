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
                cout << temp->data;
                temp = temp->ptr;
            }
            cout << endl;
        }
        else
            cout << "List doesnt exist";
    }

private:
    void deletehead(node *&h)
    {
        if (h->ptr)
        {
            node *temp = h;
            h = h->ptr;
            delete (temp);
        }
        else
        {
            node *temp = h;
            h = nullptr;
            delete (temp);
        }
    }

private:
    void deletetail(node *h)
    {
        node *temp = h;
        while (temp->ptr && temp->ptr->ptr)
        {
            temp = temp->ptr;
        }
        delete (temp->ptr);
        temp->ptr = nullptr;
    }

public:
    void del(node *&h, int deln)
    {
        if (deln < 1)
        {
            cout << "enter a valid index of node";
            return;
        }
        if (!h)
        {
            return;
        }
        if (deln == 1)
        {
            deletehead(h);
        }
        else
        {
            node *temp = h;
            int cnt = 1;
            while (temp->ptr != nullptr && temp->ptr->ptr != nullptr)
            {
                if ((deln - cnt) == 1)
                {
                    node *temp1 = temp->ptr->ptr;
                    delete (temp->ptr);
                    temp->ptr = temp1;
                    return;
                }
                cnt++;
                temp = temp->ptr;
            }
            if ((deln > cnt + 1))
            {
                cout << "index out of bound" << endl;
                return;
            }
            deletetail(h);
        }
    }
};
int main()
{
    int arr[5] = {};
    int deln = 2;
    ll list;
    node *head = list.create(arr, 0);
    list.del(head, deln);
    list.print(head);
}