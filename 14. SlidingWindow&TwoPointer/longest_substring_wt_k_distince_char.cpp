#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

int characterReplacement(string s, int k)
{

      int n = s.size();
      int l = 0, r = 0;
      int maxlen = 0;
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
                  l = l + 1;
            }
            if (hash.size() <= k)
            {
                  maxlen = max(maxlen, r - l + 1);
            }
            r = r + 1;
      }
      return maxlen;
}
int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      string s = "AABABBA";
      int k = 1;
      cout << characterReplacement(s, k);

      return 0;
}