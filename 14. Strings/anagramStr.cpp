#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    string s1 = "cat";
    string s2 = "act";
    unordered_map<char, int> h1;
    unordered_map<char, int> h2;
    for (int i = 0; i < s1.size(); i++)
    {
        h1[s1[i]]++;
        h2[s2[i]]++;
    }
    if (h1 == h2)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}