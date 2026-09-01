/* brute force

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
    int arr[] = {1, 2, 3, 4, 5, 6};
    node *h = new node(arr[0]);
    node *m = h;
    for (int i = 1; i < 6; i++)
    {
        node *temp = new node(arr[i]);
        m->ptr = temp;
        m = temp;
    }
    node *temp = h;
    int cnt = 0;
    while (temp != nullptr)
    {
        temp = temp->ptr;
        cnt++;
    }
    if (cnt % 2 == 0) // even
    {
        node *mover = h;
        for (int i = 1; i <= cnt / 2; i++)
        {
            mover = mover->ptr;
        }
        cout << mover->data;
        return 0;
    }
    else
    {
        node *mover = h;
        for (int i = 1; i <= cnt / 2; i++)
        {
            mover = mover->ptr;
        }
        cout << mover->data;
        return 0;
    }
    return 0;
}
*/
// tortoise hare method (slow pointer & first pointer)

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
    int arr[] = {1, 2, 3, 4, 5, 6};
    node *h = new node(arr[0]);
    node *m = h;
    for (int i = 1; i < 6; i++)
    {
        node *temp = new node(arr[i]);
        m->ptr = temp;
        m = temp;
    }
    node *slow = h;
    node *fast = h;
    while (fast && fast->ptr) // this logic ensures that for even noded lists we move the fast pointer to a nullptr so the next iteration stops after reaching the second middle and in case of odd noded lists we move fas pointer to last node and stop in the exact middle
    {
        fast = fast->ptr->ptr;
        slow = slow->ptr;
    }
    cout << slow->data;
    return 0;
}
