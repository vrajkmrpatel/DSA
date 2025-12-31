#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str = "SSSRRCCRSSSCCCRRH";

    unordered_map<char, int> freq;

    for (int i = 0; i < str.size(); i++)
    {
        if (freq.find(str[i]) == freq.end())
        {
            freq[str[i]] = 0;
        }
        freq[str[i]]++;
    }

    vector<pair<char, int>> res;

    for (auto it : freq)
    {
        res.push_back({it.first, it.second});
    }

    for (auto it : res)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}