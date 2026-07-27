#include <iostream>
#include <string>
#include <map>
using namespace std;
int beauty(string s)
{
    int max = 0, min = s.size();
    map<char, int> hash;
    for (auto it : s)
    {
        hash[it]++;
    }
    for (auto it : hash)
    {
        if (it.second > max)
        {
            max = it.second;
        }
        if (it.second < min)
        {
            min = it.second;
        }
    }
    return max - min;
}
int main()
{
    string s = "xyx";
    int totalBeauty = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            string temp = s.substr(i, j - i + 1);
            totalBeauty += beauty(temp);
        }
    }
    cout << totalBeauty;
    return 0;
}