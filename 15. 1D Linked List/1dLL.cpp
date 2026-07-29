#include <iostream>
using namespace std;
class node
{ // could also have used struct but class gives us readymade objects to work with so its better to use
public:
    int data;
    node *ptr; // here node* ptr is a node type pointer , this works because pointer is of fixed size always and node is a different datatype that we need a pointer of , so normal existing pointers like int* or char* cant store them , and we need this because in each node we need to store the address of the next node ;
public:
    node(int newdata, node *newptr) // created a constructor for a new node
    {
        data = newdata;
        ptr = newptr;
    }
};
int main()
{
    // node n = node(5, nullptr); although this method is absolutely fine but here we only create a object and dont have the pointer to i t, so we need to write node* y = &n to get the address
    // now there exixts a better method of doing these in a single line that is
    node *n = new node(5, nullptr); // this creates a pointer n pointed to the node and also creates a new node (using new keyowrd)
    // to access both data from it we can use -> not . ( because . is used when we have an object itself but -> is used when we have a pointer to that object)
    cout << n->data << "--->" << n->ptr;
    return 0;
}