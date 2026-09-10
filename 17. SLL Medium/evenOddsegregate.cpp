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
class sll
{
public:
    node *create(int arr[], int size)
    {
        node *h = new node(arr[0]);
        node *m = h;
        for (int i = 1; i < size; i++)
        {
            node *temp = new node(arr[i]);
            m->ptr = temp;
            m = temp;
        }
        return h;
    }

public:
    void print(node *head)
    {
        if (!head)
        {
            cout << "List doesn't exist" << endl;
            return;
        }
        while (head)
        {
            cout << head->data << " ";
            head = head->ptr;
        }
        cout << endl;
        return;
    }

public:
    void segregate(node *&head)
    {
        node *even = head;
        node *odd = head;
        node *he = nullptr;
        node *ho = nullptr;
        node *mover = head;
        if (!head)
        {
            cout << "Empty list";
            return;
        }
        while (mover)
        {
            if (mover->data % 2 == 0)
            {
                if (!he)
                {
                    he = mover;
                    even = he;
                }
                else
                {
                    even->ptr = mover;
                    even = even->ptr;
                }
            }
            else if (mover->data % 2 != 0)
            {
                if (!ho)
                {
                    ho = mover;
                    odd = ho;
                }
                else
                {
                    odd->ptr = mover;
                    odd = odd->ptr;
                }
            }
            mover = mover->ptr;
        }
        if (ho)
        {
            odd->ptr = nullptr;
        }
        if (he)
        {
            even->ptr = ho;
            head = he;
        }
        return;
    }
};
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    sll list;
    node *head = list.create(arr, 6);
    list.print(head);
    list.segregate(head);
    list.print(head);
    return 0;
}