// Given a sorted array of N integers, write a program to find the index of the last occurrence of the target key. If the target is not found then return -1. Note: Consider 0 based indexing
/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {3, 4, 13, 13, 13, 20, 40};
    int low = 0, high = arr.size() - 1, target = 40;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            while (mid < high && arr[mid + 1] == arr[mid]) // this case boils down to linear search for worst case
            {
                mid++;
            }
            cout << mid;
            return 0;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
} */

// optimal way

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {3, 4, 13, 13, 13, 20, 40};
    int low = 0, high = arr.size() - 1, target = 13;
    int answer = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            answer = mid;  // maybe the possible answer
            low = mid + 1; // go to right to find more possible answers
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << answer;
    return 0;
}

// using STL we can do this too (with upper bound and lower bound) but with 2x the time complexity 