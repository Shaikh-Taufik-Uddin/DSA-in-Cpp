// You are given a sorted array arr of distinct values and a target value x. You need to search for the index of the target value in the array.

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 4, 7};
    int low = 0, high = arr.size() - 1, target = 6, answer = arr.size();
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            answer = mid;
            break;
        }
        else if (arr[mid] > target)
        {
            answer = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << answer;
    return 0;
}