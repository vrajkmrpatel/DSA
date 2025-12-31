#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &arr)
{
    unordered_map<int, int> mp;
    for (int x : arr)
    {
        mp[x]++;
    }

    // vector<int> freq;
    // for (auto &p : mp)
    //     freq.push_back(p.second);

    // sort(freq.rbegin(), freq.rend());

    // unordered_set<int> used;
    // int total = 0;

    // for (int f : freq)
    // {
    //     while (f > 0 && used.count(f))
    //     {
    //         f--;
    //     }
    //     if (f > 0)
    //     {
    //         used.insert(f);
    //         total += f;
    //     }
    // }
    // return total;

    // Using maxheap

    priority_queue<int> pq;
    for (auto &p : mp)
        pq.push(p.second);

    unordered_set<int> used;

    long long total = 0;

    while (!pq.empty())
    {
        int f = pq.top();
        pq.pop();

        while (f > 0 && used.count(f))
        {
            f--;
        }
        if (f > 0)
        {
            used.insert(f);
            total += f;
        }
    }
    return (int)total;
}
int main()
{

    // vector<int> arr = {4, 1, 6, 3, 6, 5};
    // cout << solve(arr) << endl;

    vector<int> arr2 = {3, 7, 1, 1, 3, 1, 7};
    cout << solve(arr2) << endl; // Output: 6
    return 0;
}