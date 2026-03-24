#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool possible(vector<int> &arr, int n, int dist, int k)
{
    int cn = 1, last = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - last >= dist)
        {
            cn++;
            last = arr[i];
        }
        if (cn >= k) // returning fast if target number is reached
        {
            return true;
        }
    }
    return false;
}
int main()
{
    vector<int> arr = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int low = arr[0], high = arr[n - 1];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (possible(arr, n, mid, k) == true)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << high; // no extra is needed bcz high is already pointing to the answer
    return 0;
}