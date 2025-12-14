// Merge two Sorted Arrays Without Extra Space

// 1st optimal solution

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> arr1 = {-5, -2, 4, 5};
    vector<int> arr2 = {-3, 1, 8};
    int m = arr1.size();
    int n = arr2.size();
    int left = m - 1;
    int right = 0;
    while (left >= 0 && right < m)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    for (int i = 0; i < m; i++)
    {
        cout << arr1[i] << " ";
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
    }
    return 0;
}