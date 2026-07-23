#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string s = "- 87";
    int i = 0;
    int num = 0;
    bool flag = false;
    vector<int> sign;
    for (auto it : s)
    {
        if (sign.empty())
        {
            if (it == 43)
            {
                sign.push_back(1);
                continue;
            }
            else if (it == 45)
            {
                sign.push_back(-1);
                continue;
            }
        }
        if (it >= 48 && it <= 57)
        {
            flag = true;
            num = num * 10 + (it - 48);
            if (sign.empty())
                sign.push_back(1);
        }
        else
        {
            if (flag == true)
            {
                break;
            }
            else if (it != 32)
            {
                break;
            }
            else if (it == 32 && (!sign.empty()))
            {
                break;
            }
        }
    }
    if (sign.empty())
    {
        cout << 0;
    }
    else if ((sign[0] * num) < -2147483647)
    {
        cout << "-2147483648";
    }
    else if ((sign[0] * num) > 2147483647)
    {
        cout << "2147483647";
    }
    else
    {
        cout << sign[0] * num;
    }
    return 0;
}