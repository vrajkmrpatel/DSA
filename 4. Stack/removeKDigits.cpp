#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

string removeKdigits(string num, int k)
{
      stack<char> st;
      int n = num.length();

      for (int i = 0; i < n; i++)
      {
            while (!st.empty() && k > 0 && st.top() > num[i])
            {
                  st.pop();
                  k -= 1;
            }
            st.push(num[i]);
      }

      while (k > 0)
      {
            st.pop();
            k -= 1;
      }

      string res = "";
      while (!st.empty())
      {
            res += st.top();
            st.pop();
      }
      reverse(res.begin(), res.end());
      return res.empty() ? "0" : res;
}
int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      string num = "10200";
      int k = 1;
      cout << removeKdigits(num, k) << endl;
      return 0;
}