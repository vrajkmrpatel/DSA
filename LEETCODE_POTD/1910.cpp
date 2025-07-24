#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

bool check(string &part, int n, stack<char> &st)
{
      stack<char> tempst = st;
      for (int idx = n - 1; idx >= 0; idx--)
      {
            if (tempst.top() != part[idx])
            {
                  return false;
            }
            tempst.pop();
      }
      return true;
}

string removeOccurrences(string s, string part)
{

      // Using Stack
      int m = s.length();
      int n = part.length();
      stack<char> st;

      for (int i = 0; i < m; i++)
      {
            st.push(s[i]);
            if (st.size() >= n && check(part, n, st) == true)
            {
                  for (int j = 0; j < n; j++)
                  {
                        st.pop();
                  }
            }
      }

      string res = "";
      while (!st.empty())
      {
            res += st.top();
            st.pop();
      }

      reverse(res.begin(), res.end());
      return res;
}
int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      string s = "axxxxyyyyb";
      string part = "xy";
      string ans = removeOccurrences(s, part);
      cout << ans << endl;
      return 0;
}