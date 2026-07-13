#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main()
{
    string s = "paper";
    string t = "title";
    map<char, char> mpp;
    map<char, char> mp;
    if (s.size() != t.size())
    {
        cout << "non-isomorphic";
        return 0;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (mpp.count(s[i]) != 0)
        {
            if (mpp[s[i]] != t[i])
            {
                cout << "non-isomorphic";
                return 0;
            }
        }
        else
        {
            mpp[s[i]] = t[i];
        }
        if (mp.count(t[i]) != 0)
        {
            if (mp[t[i]] != s[i])
            {
                cout << "non-isomorphic";
                return 0;
            }
        }
        else
        {
            mp[t[i]] = s[i];
        }
    }
    cout << "isomorphic";
    return 0;
}