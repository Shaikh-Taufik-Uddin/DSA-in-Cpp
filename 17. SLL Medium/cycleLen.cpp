#include <iostream>
#include <unordered_map>
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
    void cycle(node *head)
    {
        node *fast = head;
        node *slow = head;
        int cnt = 1;
        while (fast && fast->ptr)
        {
            slow = slow->ptr;
            fast = fast->ptr->ptr;
            if (fast == slow)
            {
                fast = fast->ptr;
                while (fast != slow)
                {
                    cnt++;
                    fast = fast->ptr;
                }
                cout << cnt;
                return;
            }
        }
        cout << "false";
        return;
    }
};
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    sll list;
    node *head = list.create(arr, 6);
    list.print(head);
    list.cycle(head);
    return 0;
}