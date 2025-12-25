// You are given a sorted array of integers and a target, your task is to search for the target in the given array. Assume the given array does not contain any duplicate numbers.
// iterative
/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 4;
    int high = arr.size() - 1, low = 0;
    while(low<high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] ==target)
        {
            cout << mid;
            return 0;
        }
        else if (arr[mid]>target)
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
*/
// recursive method
#include <iostream>
#include <vector>
using namespace std;
int bs(vector<int> &arr, int low, int high, int target)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            return bs(arr, low, mid - 1, target);
        }
        else
        {
            return bs(arr, mid + 1, high, target);
        }
    }
    else
    {
        return -1;
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int high = arr.size() - 1, low = 0;
    int target = 3;
    cout << "index " << bs(arr, low, high, target);
    return 0;
}