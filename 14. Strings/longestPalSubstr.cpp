/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s = "babad";
    int maxlen = 0, ids = 0, ide = 0;
    for (int left = 0; left < s.size(); left++)
    {
        for (int right = s.size() - 1; right >= left; right--)
        {
            if (s[right] == s[left]) // minimum condition for palindrome
            {
                int len = right - left + 1;
                if (len > maxlen) // length check
                {                 // palindrome check
                    string rev = s.substr(left, right - left + 1);
                    reverse(rev.begin(), rev.end());
                    if (s.substr(left, right - left + 1) == rev)
                    {
                        ids = left;
                        ide = right;
                        maxlen = len;
                    }
                }
            }
        }
    }
    cout << maxlen << endl;
    cout << s.substr(ids, ide - ids + 1);
    return 0;
}
*/
// optimal - expand around center

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "babad";

    int start = 0;
    int maxLen = 1;

    for (int i = 0; i < s.size(); i++)
    {
        // Odd-length palindrome
        int left = i;
        int right = i;

        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            if (right - left + 1 > maxLen) // only update if the new len is larger
            {
                maxLen = right - left + 1;
                start = left;
            }

            left--;
            right++;
        }

        // Even-length palindrome
        left = i;
        right = i + 1;

        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            if (right - left + 1 > maxLen) // only update if the new len is larger
            {
                maxLen = right - left + 1;
                start = left;
            }

            left--;
            right++;
        }
    }

    cout << s.substr(start, maxLen);

    return 0;
}