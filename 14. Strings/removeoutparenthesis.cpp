/*
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s = "()(()())(())";
    string temp;
    string ans;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (temp.size() == 0 && c == '(')
        {
            temp.push_back('(');
        }
        else if (temp.size() != 0 && c == '(')
        {
            ans.push_back('(');
            temp.push_back('(');
        }
        else if (temp.size() == 1 && c == ')')
        {
            temp.pop_back();
        }
        else if (temp.size() != 0 && c == ')')
        {
            ans.push_back(')');
            temp.pop_back();
        }
    }
  cout << ans;
}
*/
// without using temp string
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s = "()(()())(())";
    int cnt = 0; 
    string ans;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (cnt == 0 && c == '(')
        {
            cnt++;
        }
        else if (cnt != 0 && c == '(')
        {
            ans.push_back('(');
            cnt++;
        }
        else if (cnt == 1 && c == ')')
        {
            cnt--;
        }
        else if (cnt != 0 && c == ')')
        {
            ans.push_back(')');
            cnt--;
        }
    }
    cout << ans;
}