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
node *linkedlist(int arr[], int size)
{
    node *head = new node(arr[0]);
    node *mover = head;
    for (int i = 1; i < size; i++)
    {
        node *temp = new node(arr[i]);
        mover->ptr = temp;
        mover = temp;
    }
    return head;
}
void printll(node *h)
{
    node *temp = h;
    while (temp)
    {
        cout << temp->data;
        temp = temp->ptr;
    }
    cout << endl;
}
node *deletehead(node *h) // if we want to do pass by reference function we need to do (node*&h) & is a reference operator here that creates a referecne to h
{
    node *newhead = h->ptr;
    delete (h); // Objects created with new must be destroyed using delete not free
    return newhead;
}
void deletetail(node *h)
{
    node *temp = h;
    while (temp->ptr->ptr)
    {
        temp = temp->ptr;
    }
    delete (temp->ptr); // so temp->ptr when used under delete it deletes the node its pointed to and when used temp->ptr = then it assigns a new values in the ptr section of this node
    temp->ptr = nullptr;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    node *head = linkedlist(arr, 5);
    printll(head);
    node *newhead = deletehead(head);
    printll(newhead);
    deletetail(newhead);
    printll(newhead);
}