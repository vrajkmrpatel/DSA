#include <bits/stdc++.h>

using namespace std;

int main()
{
      int n = 5;
      vector<int> arr = {1, 2, 3, 1, 2};

      unordered_map<int, pair<int, int>> mp;
      for (int i = 0; i < n; i++)
      {
            if (mp.find(arr[i]) != mp.end())
            {
                  mp[arr[i]] = {i, i};
            }
            else
            {
                  mp[arr[i]].second = i;
            }
      }

      for (const auto &entry : mp)
      {
            cout << "Element: " << entry.first << ", "
                 << "First Index: " << entry.second.first << ", "
                 << "Last Index: " << entry.second.second << endl;
      }
      return 0;
}