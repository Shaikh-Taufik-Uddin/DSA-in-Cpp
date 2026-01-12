#include <iostream>
using namespace std;
int power(int n, int m)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= m;
    }
    return ans;
}
int main()
{
    int n, m;
    cout << "Enter _ th root :  ";
    cin >> n;
    cout << "Enter root of _ : ";
    cin >> m;
    int low = 0, high = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (m == power(n, mid))
        {
            cout << mid;
            return 0;
        }
        else if (m > power(n, mid))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << n << " th root doesn't exists for " << m;
    return 0;
}