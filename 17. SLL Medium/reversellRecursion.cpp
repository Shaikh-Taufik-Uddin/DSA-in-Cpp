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
    node *reverse(node *head)
    {
        if (!head || !head->ptr)
        {
            return head;
        }
        node *newhead = reverse(head->ptr);
        node *front = head->ptr;
        front->ptr = head;
        head->ptr = nullptr;
        return newhead;
    }
};
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    sll list;
    node *head = list.create(arr, 6);
    list.print(head);
    head = list.reverse(head);
    list.print(head);
    return 0;
}