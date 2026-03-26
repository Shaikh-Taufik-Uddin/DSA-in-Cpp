#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool possible(vector<int> &arr, int n, int mid, int k)
{
    int sum = 0;
    int no = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
        {
            return false;
        }
        if (sum + arr[i] <= mid)
        {
            sum += arr[i];
        }
        else
        {
            sum = arr[i];
            no++;
        }
    }
    if (no <= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int k = 3;
    int low = *max_element(arr.begin(), arr.end());
    int high = 0;
    for (int i = 0; i < n; i++)
    {
        high += arr[i];
    }
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (possible(arr, n, mid, k) == true)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << low;
    return 0;
}