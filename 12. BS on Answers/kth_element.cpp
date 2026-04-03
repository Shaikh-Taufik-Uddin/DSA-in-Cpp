#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int n1, int n2, int k)
{
    // Ensure binary search on smaller array
    if (n1 > n2)
    {
        return kthElement(b, a, n2, n1, k);
    }

    int low = max(0, k - n2); // because if k is 7 and we have only 5 elements in the other half of the array then we can never get awayu with taking 0 elements from the other half
    int high = min(k, n1);    // becasue we can take at max k elements to form a half so that we can get k th element

    while (low <= high)
    {
        int mid1 = (low + high) / 2; // how many elements to take from array 1
        int mid2 = k - mid1;         // how many elements left  to take from array 2

        int l1 = INT_MIN, l2 = INT_MIN; // initializing values in case we dont take any thing
        int r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n1) // if the elements that are calculated to be taken from array 1 is less than (NOT<=) the size of array 1 (handles edge case if all elements are taken from array1 only)
        {
            r1 = a[mid1]; // right 1 is assigned
        }
        if (mid2 < n2) // if the elements that are calculated to be taken from array 2 is less than (NOT<=) the size of array 2 (handles edge case if all elements are taken from array2 only)
        {
            r2 = b[mid2]; // right 2 is  assigned
        }
        if (mid1 - 1 >= 0) // handles edeg case if no element is taken from array1
        {
            l1 = a[mid1 - 1]; // left 1 is assigned
        }
        if (mid2 - 1 >= 0) // handles edeg case if no element is taken from array2
        {
            l2 = b[mid2 - 1]; // left 2 is assigned
        }

        if (l1 <= r2 && l2 <= r1) // if it is the correct partition
        {
            return max(l1, l2); // max of l1 & l2 means the last element of that half that is of index [k-1] and is actually the kth element
        }
        else if (l1 > r2) // if array 1 is on the greater side than array 2
        {
            high = mid1 - 1; // then try lower value for array 1
        }
        else // if array 1 is on the lower side than array 2
        {
            low = mid1 + 1; // try higher value for array 1
        }
    }

    return -1; // should never reach here
}

int main()
{
    vector<int> a = {1, 3, 5};
    vector<int> b = {2, 4, 6};

    int k = 4;

    int ans = kthElement(a, b, a.size(), b.size(), k);

    cout << "K-th element is: " << ans << endl;

    return 0;
}