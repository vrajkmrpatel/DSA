#include <bits/stdc++.h>

using namespace std;

string findKthDistinctString(vector<string> &str, int k)
{

      unordered_map<string, int> mp;

      for (string &s : str)
      {
            mp[s]++;
      }
      for (string &s : str)
      {
            if (mp[s] == 1)
            {
                  k--;

                  if (k == 0)
                  {
                        return s;
                  }
            }
      }
      return "";
}
int main()
{

      vector<string> arr = {"d", "b", "c", "b", "c", "a"};

      string ans = findKthDistinctString(arr, 2);

      for (auto s : ans)
      {
            cout << s;
      }
      return 0;
}