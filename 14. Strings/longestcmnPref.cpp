/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    vector<string> str = {"flower", "flow", "flight"};
    string pref = str[0];
    int len = pref.size();
    for (int i = 1; i < str.size(); i++)
    {
        int j = min(len, (int)str[i].size());
        while (str[i].substr(0, j) != pref.substr(0, j))
        {
            j--;
        }
        len = j ;
    }
    cout << pref.substr(0, len);
    return 0;
}
*/
// optimal solution
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    vector<string> str = {"flower", "flow", "flight"};
    string pref = str[0];
    int len = pref.size();
    for (int i = 1; i < str.size(); i++)
    {
        int j = 0;
        while (j < len && j < str[i].size() && pref[j] == str[i][j])
        {
            j++;
        }
        len = j;
    }
    cout << pref.substr(0, len);
    return 0;
}