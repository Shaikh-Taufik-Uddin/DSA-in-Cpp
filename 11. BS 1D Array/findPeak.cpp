#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int n = arr.size();
    int low = 1, high = n - 2;
    if (n == 1) // if array has only 1 element 
    {
        cout << arr[0];
        return 0;
    }
    if (arr[0] > arr[1]) // if 1st element is peak
    {
        cout << arr[0];
        return 0;
    }
    if (arr[n - 1] > arr[n - 2]) // if last element is peak 
    {
        cout << arr[n - 1];
        return 0;
    }
    while (low <= high) // finding peak 
    {
        int mid = (low + high) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) // if mid is peak 
        {
            cout << arr[mid] << endl;
            return 0;
        }
        else if (arr[mid] > arr[mid - 1]) // we are on the incrasing curve , means left side of the peak
        {
            low = mid + 1;
        }
        else // we are on the decreasing curve , means righ side of the peak
        {
            high = mid - 1;
        }
    }
    return 0;
}