#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {7, 8, 9, 6, 1, 2, 3, 4, 5};
    int low = 0, high = arr.size() - 1, target = 8;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            cout << "Index " << mid;
            return 0;
        }
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) // means we are not sure which portion to eleminate 
        {
            // find till we are confimed about which to eleminate 
            low++; 
            high--;
            continue; // exits the whole loop for this iteration and start the next iteration
        }
        if (arr[low] <= arr[mid]) // means till here left half of array is sorted
        {
            if (target >= arr[low] && target <= arr[mid]) // this means target lies in this range
            {
                high = mid - 1; // trim the right search space
            }
            else // this means target does not lie in this range
            {
                low = mid + 1; // trim the left search space
            }
        }
        else // means till here right half of array is sorted
        {
            if (target >= arr[mid] && target <= arr[high]) // this means target lies in this range
            {
                low = mid + 1; // trim the left search space
            }
            else // this means target lies in this range
            {
                high = mid - 1; // trim the right search space
            }
        }
    }
    cout << "No such element found";
    return 0;
}