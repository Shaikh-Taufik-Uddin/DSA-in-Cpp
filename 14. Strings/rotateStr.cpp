/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string s = "rotation";
    string g = "tionrota";
    if (s.size() != g.size())
    {
        cout << "false";
        return 0;
    }
    char f = g[0];
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == f)
        {
            if (s.substr(i) + s.substr(0, i) == g)
            {
                cout << "true";
                return 0;
            }
        }
    }
    return 0;
}
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string s = "rotation";
    string g = "tionrota";
    if (s.size() != g.size())
    {
        cout << "false";
        return 0;
    }
    string dbl = s + s;
    if (dbl.find(g) == string::npos) // string::npos means string not found
    {
        cout << "false";
    }
    cout << "true";
    return 0;
}