// Given an integer array nums, sorted in ascending order (with distinct values) and a target value k. The array is rotated at some pivot point that is unknown. Find the index at which k is present and if k is not present return -1.
/*
#include <iostream>
#include <vector>
using namespace std;
int binarysearch(vector<int> &arr, int low, int high, int target)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int breakpoint(vector<int> &arr, int low, int high)
{
    int n = arr.size();
    for (int i = 0; i < (n - 1); i++) // linear search to find break point
    {
        if (arr[i] > arr[i + 1])
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int low = 0, high = arr.size() - 1;
    int target = 0;
    int bp = breakpoint(arr, low, high);
    int low1 = bp + 1, high1 = arr.size() - 1, find1;
    int low2 = 0, high2 = bp, find2;
    if (bp == -1) // array is already in sorted manner
    {
        // normal binary search
        cout << "Index " << binarysearch(arr, low, high, target);
        return 0;
    }
    else
    {
        // dual binary search for both parts
        find1 = binarysearch(arr, low1, high1, target);
        find2 = binarysearch(arr, low2, high2, target);
    }
    // checking who found the target
    if (find1 == -1 && find2 == -1)
    {
        cout << "No occurences found";
    }
    else if (find1 != -1)
    {
        cout << "Index " << find1;
    }
    else
    {
        cout << "Index " << find2;
    }
    return 0;
} */

// optimal

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