#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string s = "0005347";
    string temp;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if ((s[i] - '0') % 2 != 0)
        {
            temp = s.substr(0, i + 1);
            break;
        }
    }
    int i =0;
    while (i < temp.size() && temp[i] == '0')
    {
        i++;
    }
    cout << temp.substr(i,temp.size());
    return 0;
}