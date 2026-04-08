#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    int row = arr.size();
    int col = arr[0].size();
    int low = 0;
    int high = row * col - 1;
    int target = 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int r, c;
        r = mid / col;
        c = mid % col;
        if (arr[r][c] == target)
        {
            cout << "found";
            return 0;
        }
        else if (arr[r][c] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << "Not found";
    return 0;
}