#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int possible(vector<int> &arr, int m, int k, int mid)
{
    int cnt = 0;
    int bq = 0;
    for (int i = 0; i < arr.size(); i++)
    {

        if (arr[i] <= mid)
        {
            cnt++;
        }
        else
        {
            bq += (cnt / k); // this is to calculate the prior bouquets formed
            cnt = 0;
        }
    }
    bq += (cnt / k); // this is to calculate the last bouquet formed
    if (bq >= m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int m = 2, k = 3;
    int low = *min_element(arr.begin(), arr.end()), high = *max_element(arr.begin(), arr.end());
    int ans = high;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int yes = possible(arr, m, k, mid);
        if (yes)
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