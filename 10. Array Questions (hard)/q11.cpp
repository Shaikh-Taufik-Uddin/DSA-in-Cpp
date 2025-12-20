// Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].
/*
// (this code is flagged wrong still gives right results)
#include <iostream>
#include <vector>
using namespace std;
int count = 0;
int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int begin = low;
    int low2nd = mid + 1;
    while (low <= mid && low2nd <= high)
    {
        if (arr[low] > arr[low2nd])
        {
            if (arr[low] > 2 * arr[low2nd])
            {
                count += mid - low + 1;
            }
            else
            {
                int i;
                for (i = low + 1; i <= mid; i++)
                {
                    if (arr[i] > 2 * arr[low2nd])
                    {
                        break;
                    }
                }
                count += mid - i + 1;
            }
            temp.push_back(arr[low2nd]);
            low2nd++;
        }
        else
        {
            temp.push_back(arr[low]);
            low++;
        }
    }
    while (mid >= low)
    {
        temp.push_back(arr[low]);
        low++;
    }
    while (high >= low2nd)
    {
        temp.push_back(arr[low2nd]);
        low2nd++;
    }
    for (int i = 0; i < temp.size(); i++)
    {
        arr[begin + i] = temp[i];
    }
    return 0;
}
int mergesort(vector<int> &arr, int low, int high)
{
    if (high > low)
    {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
    return count;
}
int main()
{
    vector<int> arr = {3, 2, 5, 1, 3, 4};
    int low = 0, high = arr.size() - 1;
    mergesort(arr, low, high);
    cout << count;
    return 0;
}
*/

#include <iostream>
#include <vector>
using namespace std;
int countpair(vector<int> &arr, int low, int mid, int high)
{
    int count = 0;
    int right = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > (2 * arr[right]))
        {
            right++;
        }
        count += (right - (mid + 1));
    }
    return count;
}
int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int begin = low;
    int low2nd = mid + 1;
    int count = 0;
    while (low <= mid && low2nd <= high)
    {
        if (arr[low] > arr[low2nd])
        {
            temp.push_back(arr[low2nd]);
            low2nd++;
        }
        else
        {
            temp.push_back(arr[low]);
            low++;
        }
    }
    while (mid >= low)
    {
        temp.push_back(arr[low]);
        low++;
    }
    while (high >= low2nd)
    {
        temp.push_back(arr[low2nd]);
        low2nd++;
    }
    for (int i = 0; i < temp.size(); i++)
    {
        arr[begin + i] = temp[i];
    }
    return 0;
}
int mergesort(vector<int> &arr, int low, int high)
{
    int count = 0;
    if (high > low)
    {
        int mid = (low + high) / 2;
        count += mergesort(arr, low, mid);
        count += mergesort(arr, mid + 1, high);
        count += countpair(arr, low, mid, high);
        merge(arr, low, mid, high);
    }
    return count;
}
int main()
{
    int count = 0;
    vector<int> arr = {5, 4, 3, 2, 1};
    int low = 0, high = arr.size() - 1;
    count += mergesort(arr, low, high);
    cout << count;
    return 0;
}