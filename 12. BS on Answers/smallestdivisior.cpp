#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int sum(vector<int> &arr, int mid)
{
    int n = arr.size();
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += (arr[i] / mid);
    }
    return s;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int low = 1;
    int high = *max_element(arr.begin(), arr.end());
    int ans;
    while (low < high)
    {
        int mid = (low + high) / 2;
        int s = sum(arr, mid);
        if (s <= limit)
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