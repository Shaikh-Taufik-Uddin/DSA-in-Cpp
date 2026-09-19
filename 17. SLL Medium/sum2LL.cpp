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
    void sumll(node *&head1, node *&head2)
    {
        node *temp1 = head1;
        node *temp2 = head2;
        node *ans = new node(-1);
        node *mover = ans;
        int dig1 = 0;
        int dig2 = 0;
        int sum = 0;
        while (temp1 || temp2)
        {
            if (temp1)
            {
                dig1 = dig1 * 10 + temp1->data;
                temp1 = temp1->ptr;
            }
            if (temp2)
            {
                dig2 = dig2 * 10 + temp2->data;
                temp2 = temp2->ptr;
            }
        }
        sum = dig1 + dig2;
        while (sum > 0)
        {
            int digit = sum % 10;
            node *temp = new node(digit);
            temp->ptr = mover;
            mover = temp;
            sum = sum / 10;
        }
        ans = mover;
        while (ans->ptr)
        {
            cout << ans->data;
            ans = ans->ptr;
        }
        ans = mover;
        return;
    }
};
int main()
{
    int arr[] = {1, 2, 9, 0, 2, 9};
    int brr[] = {1, 3, 9, 0, 0, 1};
    sll list;
    node *head1 = list.create(arr, 6);
    node *head2 = list.create(brr, 6);
    list.sumll(head1, head2);
    return 0;
}