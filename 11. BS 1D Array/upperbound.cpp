
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {2, 4, 10, 20};
    int low = 0, high = arr.size() - 1, target = 5;
    int ans = arr.size();
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans;
    return 0;
}

// using STL
// upper_bound(arr.begin(), arr.end(), target); // we get an iterator pointing to that index .. to get the index we need to substract arr.begin() with it