#include <iostream>
#include <vector>
using namespace std;
class node
{
public:
    node *prev;
    int data;
    node *next;

public:
    node(node *previous, int value, node *nextp)
    {
        prev = previous;
        data = value;
        next = nextp;
    }

public:
    node(node *previous, int value)
    {
        prev = previous;
        data = value;
        next = nullptr;
    }

public:
    node(int value, node *nextp)
    {
        prev = nullptr;
        data = value;
        next = nextp;
    }

public:
    node(int value)
    {
        prev = nullptr;
        data = value;
        next = nullptr;
    }
};
class dll
{
public:
    node *create(vector<int> &arr)
    {
        int size = arr.size();
        if (size != 0)
        {
            node *head = new node(arr[0]);
            node *copy = head;
            for (int i = 1; i < size; i++)
            {
                node *temp = new node(arr[i]);
                temp->prev = copy;
                copy->next = temp;
                copy = temp;
            }
            return head;
        }
        return nullptr;
    }

public:
    void print(node *head)
    {
        if (head)
        {
            while (head)
            {
                cout << head->data << " ";
                head = head->next;
            }
            cout << endl;
            return;
        }
        cout << "List doesn't exits" << endl;
        return;
    }
};
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    dll list;
    node *head = list.create(arr);
    list.print(head);
}