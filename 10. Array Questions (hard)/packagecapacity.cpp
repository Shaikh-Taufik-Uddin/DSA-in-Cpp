#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int loaddist(vector<int> &arr, int cap)
{
    int n = arr.size();
    int days = 1, load = 0;
    for (int i = 0; i < n; i++)
    {

        if (load + arr[i] <= cap)
        {
            load += arr[i];
        }
        else
        {
            days++;
            load = arr[i];
        }
    }
    return days;
}
int main()
{
    vector<int> arr = {
        5,
        4,
        5,
        2,
        3,
        4,
        5,
        6,
    };
    int n = arr.size();
    int d;
    cout << "Enter the number of days : ";
    cin >> d;
    int low = *max_element(arr.begin(), arr.end());
    int high = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        high += arr[i];
    }
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (loaddist(arr, mid) <= d)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans;
}