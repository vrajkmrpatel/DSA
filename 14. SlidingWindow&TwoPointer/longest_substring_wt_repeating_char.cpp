#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

int lengthOfLongestSubstring(string s)
{

      // Brute Force
      // int maxlen = 0, len = 0;
      // int n = s.length();
      // for (int i = 0; i < n; i++)
      // {
      //       int hash[256] = {0};
      //       for (int j = i; j < n; j++)
      //       {
      //             if (hash[s[j]] == 1)
      //             {
      //                   break;
      //             }
      //             len = j - i + 1;
      //             maxlen = max(maxlen, len);
      //             hash[s[j]] = 1;
      //       }
      // }
      // return maxlen;

      // Optimal Approach
      int n = s.length();
      int l = 0, r = 0;
      int maxlen = 0, len = 0;

      int hash[256] = {-1};
      while (r < n)
      {
            if (hash[s[r]] != -1) // char is in the hash
            {
                  if (hash[s[r]] >= l) // char must be within the range within (l,r)
                  {
                        l = hash[s[r]] + 1;
                  }
            }
            len = r - l + 1;
            maxlen = max(len, maxlen);
            hash[s[r]] = r;
            r++;
      }
      return maxlen;
}
int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      string s = "cadbzabcd";
      cout << lengthOfLongestSubstring(s) << endl;
      return 0;
}