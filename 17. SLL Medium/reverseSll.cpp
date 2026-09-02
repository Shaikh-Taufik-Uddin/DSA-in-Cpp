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
    void reverse(node *&head)
    {
        if (!head)
        {
            return;
        }
        node *m = head;
        node *copy = nullptr; // this is used to point the starting head to nullptr and also works in case of a single noded list
        node *temp;
        while (m)
        {
            temp = m->ptr; // stores the next nodes address
            m->ptr = copy; // links current node with previous node
            copy = m;      // stores the current node address
            m = temp;      // moves forward to the next node
        }
        head = copy; // point head to the last node that is currently stored in copy
        return;
    }
};
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    sll list;
    node *head = list.create(arr, 6);
    list.print(head);
    list.reverse(head);
    list.print(head);
    return 0;
}