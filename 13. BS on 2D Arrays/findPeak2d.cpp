#include <iostream>
#include <vector>
using namespace std;
int maxval(vector<vector<int>> &arr, int col, int row)
{
    int max = -1;
    int idx = -1;
    for (int i = 0; i < row; i++)
    {
        if (arr[i][col] > max)
        {
            idx = i;
            max = arr[i][col];
        }
    }
    return idx;
}
int main()
{
    vector<vector<int>> arr = {{1, 4, 7, 11}, {2, 5, 8, 12}, {3, 6, 9, 16}, {10, 13, 14, 17}};
    int row = arr.size();
    int col = arr[0].size();
    int low = 0, high = col - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int maxridx = maxval(arr, mid, row);
        int left, right;
        if (mid - 1 >= 0)
        {
            left = arr[maxridx][mid - 1];
        }
        else
        {
            left = -1;
        }
        if (mid + 1 < col)
        {
            right = arr[maxridx][mid + 1];
        }
        else
        {
            right = -1;
        }
        if (arr[maxridx][mid] > left && arr[maxridx][mid] > right)
        {
            cout << "[" << maxridx << "," << mid << "]";
            return 0;
        }
        else if (left > arr[maxridx][mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}