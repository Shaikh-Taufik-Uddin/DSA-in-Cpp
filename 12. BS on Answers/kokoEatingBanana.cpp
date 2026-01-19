#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int timetaken(vector<int> &arr, int k)
{
    int time = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        time += ceil((double)arr[i] / k);
    }
    return time;
}
int main()
{
    vector<int> arr = {7, 15, 6, 3};
    int h = 8;
    int low = 1, high = *max_element(arr.begin(), arr.end());
    int ans = high;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int t = timetaken(arr, mid);
        if (t <= h)
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
    return 0;
}