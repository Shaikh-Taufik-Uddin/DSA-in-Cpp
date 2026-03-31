#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int k = 4;
    vector<int> count(n - 1, 0);               // to keep count of placed gas station at an index
    priority_queue<pair<long double, int>> pq; // to keep track of distance b/w two gas stations and the index
    for (int i = 0; i < n - 1; i++)            // Initialize with original gaps
    {
        pq.push({(long double)(arr[i + 1] - arr[i]), i});
    }
    for (int i = 1; i <= k; i++) // Add k gas stations
    {
        auto tp = pq.top();
        pq.pop();
        long double currlen = tp.first;
        int sectionInd = tp.second;
        count[sectionInd]++;                                         // Increase split count for this gap
        long double iniDiff = arr[sectionInd + 1] - arr[sectionInd]; // Original gap
        long double newSecLen = iniDiff / (count[sectionInd] + 1);   // New max segment length after splitting
        pq.push({newSecLen, sectionInd});
    }
    cout <<  pq.top().first;
    return 0;
}