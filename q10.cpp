// Given an array of N integers, count the inversion of the array(using merge - sort).
/*
#include <bits/stdc++.h>
using namespace std;
int numberOfInversions(vector<int> &a, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                cnt++;
        }
    }
    return cnt;
}
int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    int n = a.size();
    int cnt = numberOfInversions(a, n);
    cout << "The number of inversions is: " << cnt << endl;
    return 0;
}
*/

// optimal

#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high)
{
    int cnt = 0;
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = 0; i < temp.size(); i++)
    {
        arr[low + i] = temp[i];
    }

    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return 0;

    int mid = (low + high) / 2;
    int cnt = 0;

    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);

    return cnt;
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    int cnt = mergeSort(arr, 0, arr.size() - 1);
    cout << cnt;
    return 0;
}
