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
    void sort012(node *&head)
    {
        // creating three distinct lists
        node *l0 = new node(0);
        node *newhead = l0;
        node *l1 = new node(1);
        node *l1head = l1;
        node *l2 = new node(2);
        node *l2head = l2;
        node *mover = head;
        while (mover)
        {
            if (mover->data == 0)
            {
                l0->ptr = mover;
                l0 = l0->ptr;
                mover = mover->ptr;
            }
            else if (mover->data == 1)
            {
                l1->ptr = mover;
                l1 = l1->ptr;
                mover = mover->ptr;
            }
            else
            {
                l2->ptr = mover;
                l2 = l2->ptr;
                mover = mover->ptr;
            }
        }
        // connecting three lists togather
        l0->ptr = l1head->ptr;
        l1->ptr = l2head->ptr;
        l2->ptr = nullptr;
        head = newhead->ptr; // pointing to the new head
    }
};
int main()
{
    int arr[] = {1, 2, 0, 0, 2, 1};
    sll list;
    node *head = list.create(arr, 6);
    list.print(head);
    list.sort012(head);
    list.print(head);
    return 0;
}