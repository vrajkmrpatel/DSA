#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

int longestKSubstr(string &s, int k)
{

      // Brute Force
      // int n = s.size();
      // int maxlen = 0;
      // unordered_map<char, int> hash;
      // for (int i = 0; i < n; i++)
      // {
      //       hash.clear();
      //       for (int j = i; j < n; j++)
      //       {
      //             hash[s[j]]++;
      //             if (hash.size() == k)
      //             {
      //                   maxlen = max(maxlen, j - i + 1);
      //             }
      //       }
      // }
      // return maxlen ? maxlen : -1;

      // Sliding Window Approach
      int n = s.size();
      int maxlen = 0;
      int l = 0, r = 0;
      unordered_map<char, int> hash;
      while (r < n)
      {
            hash[s[r]]++;
            if (hash.size() > k)
            {
                  hash[s[l]]--;
                  if (hash[s[l]] == 0)
                  {
                        hash.erase(s[l]);
                  }
                  l++;
            }
            if (hash.size() <= k)
                  maxlen = max(maxlen, r - l + 1);
            r++;
      }
      return maxlen ? maxlen : -1;
}

int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      string s = "aabaaab";
      int k = 2;
      cout << longestKSubstr(s, k);

      return 0;
}