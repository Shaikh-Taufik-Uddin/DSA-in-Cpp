#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {4, 7, 9, 10};
    int k = 3;
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << k + high + 1; // low+1
    return 0;
}