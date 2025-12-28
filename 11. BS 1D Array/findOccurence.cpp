// You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {2, 2, 3, 3, 3, 3, 4};
    int low = 0, high = arr.size() - 1, target = 3;
    int foc = -1, loc = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            foc = mid;
            high = mid - 1;
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
    low = 0;
    high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            loc = mid;
            low = mid + 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (foc != -1 && loc != -1)
    {
        cout << "number of occurecnces are " << (loc - foc) + 1;
    }
    else
    {
        cout << "No occurences found";
    }

    return 0;
}