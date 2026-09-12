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
    void deleteMiddle(node *&head)
    {
        node *fast = head;
        node *slow = head;
        node *temp = head;
        if (!head)
        {
            return;
        }
        if (!head->ptr)
        {
            node *temp = head;
            head = nullptr;
            delete (temp);
            return;
        }
        while (fast && fast->ptr)
        {
            temp = slow;
            slow = slow->ptr;
            fast = fast->ptr->ptr;
        }
        node *tbd = temp->ptr;
        temp->ptr = temp->ptr->ptr;
        delete (tbd);
        return;
    }
};
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    sll list;
    node *head = list.create(arr, 6);
    list.print(head);
    int del = 3;
    list.deleteMiddle(head);
    list.print(head);
    return 0;
}