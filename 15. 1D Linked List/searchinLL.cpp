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
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    node *h = new node(arr[0]);
    node *m = h;
    int target = 3;
    for (int i = 1; i < 5; i++)
    {
        node *temp = new node(arr[i]);
        m->ptr = temp;
        m = temp;
    }
    int cnt = 1;
    node *temp = h;
    while (temp != nullptr)
    {
        if (temp->data == target)
        {
            cout << "found at node " << cnt;
            return 0;
        }
        temp = temp->ptr;
        cnt++;
    }
    cout << "Not found";
    return 0;
}