// Maximum Product Subarray in an Array

// optimal 1 -> dual kadane's algo
/*
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int main()
{
    vector<int> arr = {-2, -3, -4};
    int n = arr.size();
    int product = 1;
    int maxproduct = INT_MIN;
    // kadan's algo 1st run from start
    for (int i = 0; i < n; i++)
    {
        product *= arr[i];
        if (product > maxproduct)
        {
            maxproduct = product;
        }
        else if (product == 0)
        {
            product = 1;
        }
    }
    product = 1;
    // kadan's algo 2nd run from behind
    for (int i = n - 1; i >= 0; i--)
    {
        product *= arr[i];
        if (product > maxproduct)
        {
            maxproduct = product;
        }
        else if (product == 0)
        {
            product = 1;
        }
    }
    cout << maxproduct;
    return 0;
}
*/
// optimal 2

#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, -3, 0, -4, -5};
    int n = arr.size();
    int preproduct = 1, sufproduct = 1, maxproduct = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (preproduct == 0)
        {
            preproduct = 1;
        }
        if (sufproduct == 0)
        {
            sufproduct = 1;
        }
        preproduct *= arr[i];
        sufproduct *= arr[n - i - 1];
        maxproduct = max(max(preproduct, sufproduct), maxproduct);
    }
    cout << maxproduct;
    return 0;
}