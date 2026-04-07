#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    vector<vector<int>> vec = {
        {0, 0, 0},
        {0, 0, 0},
    };
    int row = vec.size();
    int col = vec[0].size();
    pair<int, int> ans = {0, INT_MIN};
    for (int i = 0; i < row; i++)
    {
        int low = 0, high = col - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (vec[i][mid] == 1)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        int no1 = col - low;
        if (no1 > ans.second)
        {
            ans.first = i;
            ans.second = no1;
        }
    }
    if (ans.second == 0)
    {
        cout << -1;
        return -1;
    }
    cout << ans.first << " index has the most no of 1's : " << ans.second;
    return 0;
}