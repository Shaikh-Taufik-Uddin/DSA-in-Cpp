#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool possible(vector<int> &arr, int k, int n, int mid)
{
    int painter = 1;
    int board = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid) // for edege cases
        {
            return false;
        }
        if (board + arr[i] <= mid)
        {
            board += arr[i];
        }
        else
        {
            painter++;
            board = arr[i];
        }
    }
    if (painter <= k) // possible value
    {
        return true;
    }
    else // impossible value
    {
        return false;
    }
}
using namespace std;
int main()
{
    vector<int> arr = {10, 20, 30, 40};
    int k = 2;
    int n = arr.size();
    int low = *max_element(arr.begin(), arr.end());
    int high = 0;
    for (int i = 0; i < n; i++)
    {
        high += arr[i];
    }
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (possible(arr, k, n, mid) == true) // we are in the possible range & values can still probably be lowerd
        {
            high = mid - 1; // try lower values
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << low; // because low ends up from a non possible range to possible range
    return 0;
}