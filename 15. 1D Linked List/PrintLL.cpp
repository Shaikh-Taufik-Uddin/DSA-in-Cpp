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
    // printing loop
    node *temp = h;
    while (temp != nullptr) // or simply while(temp) can also be written
    {
        cout << temp->data << endl;
        temp = temp->ptr; // we can assign temp to temp->ptr because its also an node type pointer to another node
    }
    return 0;
}