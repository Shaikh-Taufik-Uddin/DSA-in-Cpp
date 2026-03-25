#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool possible(vector<int> &arr, int m, int mid)
{
    int student = 1;
    int sum = 0;
    for (int i = 0; i <= arr.size() - 1; i++)
    {
        if (arr[i] > mid)
        {
            return false;
        }
        if (sum + arr[i] > mid)
        {
            student++;
            sum = arr[i];
        }
        else
        {
            sum += arr[i];
        }
    }
    if (student > m)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    vector<int> arr = {12, 34, 67, 90};
    int n = arr.size();
    int m = 2;
    int low = *max_element(arr.begin(), arr.end()); // minimum possible
    int high = 0;
    for (int i = 0; i < n; i++)
    {
        high += arr[i];
    }
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (possible(arr, m, mid) == true)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << low ;
    return 0;
}