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
        node *temp = new node(arr[i]); // a temporary node is created with data and a nullpointer
        m->ptr = temp;                 // as temp itself is a pointer so it can be readily stored in m->ptr
        // now m's pointer address has only been changed to the next node , m is still itself pointed to h , so we need to change it
        m = temp; // moves the pointer
        // so for the head node head->next = temp would have established the same connection as mover->next = temp does because they are basically the same at first then from next on temp->next would have same effects if temp wasnt being continuously overriden to take a new value , so we take help of the mover to connect them togather .
    }
    return 0;
}