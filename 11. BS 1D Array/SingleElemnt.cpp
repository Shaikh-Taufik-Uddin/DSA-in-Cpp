#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int low = 1, high = arr.size() - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
        {
            cout << arr[mid];
            return 0;
        }
        if((mid % 2 != 0 && arr[mid] == arr[mid-1]) || mid%2 == 0 && arr[mid]==arr[mid+1]) // we are in the left of the single element
        {
            low = mid + 1; // eleminate left half
        }
        else
        {
            high = mid - 1; // eleminate right half 
        }
    }
    return 0;
}