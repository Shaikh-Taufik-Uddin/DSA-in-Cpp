// find the square root of a number in log n 

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number ";
    cin >> n;
    int low = 1, high = n;
    int ans;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if ((mid * mid) == n) // answer found
        {
            cout << mid;
            return 0;
        }
        else if ((mid * mid) > n)
        {
            high = mid - 1;
        }
        else
        {
            ans = mid; // probable floor 
            low = mid + 1;   
        }
    }
    cout << ans; 
    return 0;
}