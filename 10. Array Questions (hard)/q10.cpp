#include <iostream>
#include <vector>
using namespace std;
int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int begin = low;
    int low2nd = mid + 1;
    int count = 0;
    while (low <= mid && low2nd <= high)
    {
        if (arr[low] > arr[low2nd]) // this is the condition for inversion
        {
            count += (mid - low) + 1;
            temp.push_back(arr[low2nd]);
            low2nd++;
        }
        else
        {
            temp.push_back(arr[low]);
            low++;
        }
    }
    while (mid >= low)
    {
        temp.push_back(arr[low]);
        low++;
    }
    while (high >= low2nd)
    {
        temp.push_back(arr[low2nd]);
        low2nd++;
    }
    for (int i = 0; i < temp.size(); i++)
    {
        arr[begin + i] = temp[i];
    }
    return count;
}
int mergesort(vector<int> &arr, int low, int high)
{
    int count = 0;
    if (high > low)
    {
        int mid = (low + high) / 2;
        count += mergesort(arr, low, mid);      // merge sort for left side that will return count for leftside inversions
        count += mergesort(arr, mid + 1, high); // merge sort for right side that will return count for rightside inversions
        count += merge(arr, low, mid, high);    // merge sort for cross inversion that will return count for cross inversions
    }
    return count;
}
int main()
{
    int count = 0;
    vector<int> arr = {5, 4, 3, 2, 1};
    int low = 0, high = arr.size() - 1;
    count += mergesort(arr, low, high);
    cout << count;
    return 0;
}