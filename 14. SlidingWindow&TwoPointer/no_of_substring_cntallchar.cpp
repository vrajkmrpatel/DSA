#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

int numberOfSubstrings(string s)
{

      /* // Brute Force
       int n = s.size();
       int cnt = 0;
       for (int i = 0; i < n; i++)
       {
             int hash[3] = {0};
             for (int j = i; j < n; j++)
             {
                   hash[s[j] - 'a'] = 1;
                   if (hash[0] + hash[1] + hash[2] == 3)
                   {
                         cnt = cnt + (n - j);
                         break;
                   }
             }
       }
       return cnt;*/

      // Optimal Solution
      // TC:O(N)
      // SC: O(1)
      int n = s.size();
      vector<int> lastSeen(3, -1);
      int cnt = 0;
      for (int i = 0; i < n; i++)
      {
            lastSeen[s[i] - 'a'] = i;
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
            {
                  cnt += (1 + *min_element(lastSeen.begin(), lastSeen.end()));
            }
      }
      return cnt;
}

int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      string s = "abcabc";
      cout << numberOfSubstrings(s);

      return 0;
}