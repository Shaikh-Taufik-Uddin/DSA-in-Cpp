#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s = "(1)+((2))+(((3)))";
    int maxlen = 0;
    int cnt = 0;
    for (auto it : s)
    {
        if (it == '(')
        {
            cnt++;
            if (cnt > maxlen)
            {
                maxlen = cnt;
            }
        }
        else if (it == ')')
        {
            cnt--;
        }
    }
    cout << maxlen;
    return 0;
}