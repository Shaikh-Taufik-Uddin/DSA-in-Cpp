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
    void add1(node *&head)
    {
        int num = 0;
        node *temp = head;
        while (temp)
        {
            num = num * 10 + temp->data;
            temp = temp->ptr;
        }
        cout << num + 1;
        return;
    }
};
int main()
{
    int arr[] = {1, 2, 0, 0, 2, 1};
    sll list;
    node *head = list.create(arr, 6);
    list.add1(head);
    return 0;
}