/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "MCMXCIV";
    int num = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'I')
        {
            if ((i + 1) != s.size() && s[i + 1] == 'V')
            {
                num += 4;
            }
            else if ((i + 1) != s.size() && s[i + 1] == 'X')
            {
                num += 9;
            }
            else
            {
                num++;
            }
        }
        else if (s[i] == 'V' && (i == 0 || s[i - 1] != 'I'))
        {
            num += 5;
        }
        else if (s[i] == 'X' && (i == 0 || s[i - 1] != 'I'))
        {
            if ((i + 1) != s.size() && s[i + 1] == 'L')
            {
                num += 40;
            }
            else if ((i + 1) != s.size() && s[i + 1] == 'C')
            {
                num += 90;
            }
            else
            {
                num += 10;
            }
        }
        else if (s[i] == 'L' && (i == 0 || s[i - 1] != 'X'))
        {
            num += 50;
        }
        else if (s[i] == 'C' && (i == 0 || s[i - 1] != 'X'))
        {
            if ((i + 1) != s.size() && s[i + 1] == 'D')
            {
                num += 400;
            }
            else if ((i + 1) != s.size() && s[i + 1] == 'M')
            {
                num += 900;
            }
            else
            {
                num += 100;
            }
        }
        else if (s[i] == 'D' && (i == 0 || s[i - 1] != 'C'))
        {
            num += 500;
        }
        else if (s[i] == 'M' && (i == 0 || s[i - 1] != 'C'))
        {
            num += 1000;
        }
    }

    cout << num;
    return 0;
}
*/

// optimal process

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    string s = "MCMXCIV";

    unordered_map<char, int> value = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

    int num = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (i + 1 < s.size() && value[s[i]] < value[s[i + 1]])
        {
            num -= value[s[i]];
        }
        else
        {
            num += value[s[i]];
        }
    }

    cout << num;

    return 0;
}