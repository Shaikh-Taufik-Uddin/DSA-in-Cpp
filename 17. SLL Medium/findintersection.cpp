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
    void findintersection(node *&head1, node *&head2)
    {
        node *temp1 = head1;
        node *temp2 = head2;
        while (temp1 != temp2)
        {
            temp1 = temp1->ptr;
            temp2 = temp2->ptr;
            if (temp1 == temp2)
            {
                cout << temp1;
                return;
            }
            if (temp1 == nullptr)
            {
                temp1 = head2;
            }
            if (temp2 == nullptr)
            {
                temp2 = head1;
            }
        }
        cout << temp1;
        return;
    }
};
int main()
{
    int arr[] = {1, 2, 0, 0, 2, 1};
    int brr[] = {1, 2, 0, 0, 2, 1};
    sll list;
    node *head1 = list.create(arr, 6);
    node *head2 = list.create(brr, 6);
    list.findintersection(head1, head2);
    return 0;
}