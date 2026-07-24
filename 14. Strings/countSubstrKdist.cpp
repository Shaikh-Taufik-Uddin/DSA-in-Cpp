#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    string s = "pqpqs";
    int k = 2;

    int atMostK = 0;
    int atMostKMinus1 = 0;

    // ---------- At Most K ----------
    {
        unordered_map<char, int> freq;
        int left = 0;

        for (int right = 0; right < s.size(); right++)
        {
            freq[s[right]]++;

            while (freq.size() > k)
            {
                freq[s[left]]--;

                if (freq[s[left]] == 0)
                    freq.erase(s[left]);

                left++;
            }

            atMostK += (right - left + 1);
        }
    }

    // ---------- At Most (K-1) ----------
    {
        unordered_map<char, int> freq;
        int left = 0;

        for (int right = 0; right < s.size(); right++)
        {
            freq[s[right]]++;

            while (freq.size() > k - 1)
            {
                freq[s[left]]--;

                if (freq[s[left]] == 0)
                    freq.erase(s[left]);

                left++;
            }

            atMostKMinus1 += (right - left + 1);
        }
    }

    int answer = atMostK - atMostKMinus1;

    cout << "Answer = " << answer << endl;

    return 0;
}