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
    for (int i = 1; i < 5; i++)
    {
        node *temp = new node(arr[i]);
        m->ptr = temp;
        m = temp;
    }
    node *temp = h;
    int cnt = 0; // counter to keep track of nodes visited
    while (temp != nullptr)
    {
        temp = temp->ptr;
        cnt++;
    }
    cout << cnt;
    return 0;
}