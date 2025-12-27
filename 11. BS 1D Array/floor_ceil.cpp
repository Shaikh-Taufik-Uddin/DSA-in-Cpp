// you're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1]. The floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    int target = 5;

    int low = 0, high = arr.size() - 1;
    int floor = -1, ceil = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            floor = ceil = arr[mid];
            break;
        }
        else if (arr[mid] < target)
        {
            floor = arr[mid]; // maybe a valid floor
            low = mid + 1;
        }
        else
        {
            ceil = arr[mid]; // maybe a valid ceil
            high = mid - 1;
        }
    }

    cout << "Floor: ";
    if (floor == -1)
        cout << "Not exist";
    else
        cout << floor;

    cout << "\nCeil: ";
    if (ceil == -1)
        cout << "Not exist";
    else
        cout << ceil;

    return 0;
}
