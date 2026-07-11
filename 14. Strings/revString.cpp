#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string s = "    welcome to    the jungle    ";
    vector<string> vec;
    string temp;
    int i = 0;
    for (i; i < s.size(); i++)
    {
        char c = s[i];
        if (c != ' ')
        {
            temp.push_back(c);
        }
        else
        {
            vec.push_back(temp);
            temp.clear();
        }
    }
    vec.push_back(temp); // for the last word
    string ans;
    for (int j = vec.size() - 1; j >= 0; j--)
    {
        if (vec[j] != "") // doesnt append empty strings
        {
            if (ans.empty()) // doesnt add extra space before 1st word of a reversed string
                ans += vec[j];
            else
                ans += " " + vec[j];
        }
    }
    cout << ans;
}