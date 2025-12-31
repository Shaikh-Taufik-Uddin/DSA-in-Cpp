#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Left half is sorted
        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        // Right half is unsorted (rotation point here)
        else
        {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }

    cout << ans;
    return 0;
}