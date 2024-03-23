#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Map

    int arr[] = {2, 2, 1, 3, 2, 1, 3, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for (auto it : mp)
    {
        // cout << it.first << " ";
        // cout << it.second << " ";
        // cout << endl;

        if (it.second > (n / 2))
        {
            cout << it.first;
            // break;
        }
    }
    return 0;
}