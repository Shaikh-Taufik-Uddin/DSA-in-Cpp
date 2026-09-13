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

private:
    node *merge(node *left, node *right)
    {
        node *templl = new node(-1); // a new list created to be the merged list
        node *mover = templl;
        while (left && right)
        {
            if (left->data <= right->data)
            {
                mover->ptr = left;
                mover = mover->ptr;
                left = left->ptr;
            }
            else
            {
                mover->ptr = right;
                mover = mover->ptr;
                right = right->ptr;
            }
        }
        while (left)
        {
            mover->ptr = left;
            mover = mover->ptr;
            left = left->ptr;
        }
        while (right)
        {
            mover->ptr = right;
            mover = mover->ptr;
            right = right->ptr;
        }
        return templl->ptr; // as we stored -1 to initiate the list we need to skip it
    }

private:
    node *divide(node *head)
    {
        if (!head || !head->ptr)
        {
            return head;
        }
        // finding middle
        node *fast = head->ptr;
        node *slow = head;
        while (fast && fast->ptr)
        {
            fast = fast->ptr->ptr;
            slow = slow->ptr;
        }
        node *left = head;       // head for the left half
        node *right = slow->ptr; // head for the right half
        slow->ptr = nullptr;     // link is broken to actually split the halves

        left = divide(left);       // recursive call on the left half
        right = divide(right);     // recursive call on the right half
        return merge(left, right); // merging both the halves
    }

public:
    void sortll(node *&head)
    {
        head = divide(head);
    }
};
int main()
{
    int arr[] = {6, 4, 4, 5, 1, 3, 2, 1};
    sll list;
    node *head = list.create(arr, 8);
    list.print(head);
    list.sortll(head);
    list.print(head);
    return 0;
}