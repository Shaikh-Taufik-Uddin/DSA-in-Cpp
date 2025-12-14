// Find the repeating and missing numbers
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 6, 7, 5, 7};
    sort(arr.begin(), arr.end());
    vector<int> ans;
    int n = arr.size();
    int isum = (n * (n + 1)) / 2;
    int asum = 0;
    int duplicate, missing;
    for (int i = 0; i < n; i++)
    {
        asum += arr[i];
        if (i < n - 1 && arr[i] == arr[i + 1]) // i<n-1 to avoid out of bound error
        {
            duplicate = arr[i];
            ans.push_back(duplicate);
        }
    }
    // derived from the equation Actualsum = Idealsum + Duplicate - Missing
    missing = isum + duplicate - asum;
    ans.push_back(missing);
    for (int i = 0; i < 2; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
*/
// optimal

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 6, 7, 5, 7};
    vector<int> ans;
    int n = arr.size();
    int s1 = 0, s2 = 0, s1n = (n * (n + 1)) / 2, s2n = (n * (n + 1) * (2 * n + 1)) / 6;
    for (int i = 0; i < n; i++)
    {
        s1 += arr[i];
        s2 += (arr[i] * arr[i]);
    }
    // we do x+y and x2+y2 , and then solve for the two equations to get the value of x and y
    int val1 = s1 - s1n, val2 = s2 - s2n, val3 = val2 / val1;
    int repeating = (val1 + val3) / 2, missing = val3 - repeating;
    ans.push_back(repeating);
    ans.push_back(missing);
    cout << ans[0];
    cout << ans[1];
    return 0;
}