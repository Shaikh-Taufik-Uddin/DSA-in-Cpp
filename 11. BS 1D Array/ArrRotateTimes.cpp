#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int low = 0, high = arr.size() - 1;
    int mini = INT_MAX, idx = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= mini)
            {
                mini = arr[low];
                idx = low;
            }
            low = mid + 1;
        }
        else
        {
            if (arr[mid] <= mini)
            {
                mini = arr[mid];
                idx = mid;
            }
            high = mid - 1;
        }
    }
    cout << "Array has been rotated " << idx << " times";
    return 0;
}