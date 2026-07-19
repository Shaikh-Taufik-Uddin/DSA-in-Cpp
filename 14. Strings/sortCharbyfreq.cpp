#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    string s = "tree";
    map<char, int> hash;
    for (auto it : s)
    {
        hash[it]++;
    }
    for (auto it : hash)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}