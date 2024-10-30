#include <bits/stdc++.h>

using namespace std;

bool isGoodString(string &s, int n)
{
      for (int i = 0; i < n; i++)
      {
            if (s[i] != s[n - i - 1])
            {
                  return false;
            }
      }
      return true;
}
int main()
{
      int t;
      cin >> t;
      while (t--)
      {
            int k;
            cin >> k;

            int goodStringCount = 0;

            for (int i = 0; i < k; i++)
            {
                  int n;
                  string s;
                  cin >> n >> s;

                  if (isGoodString(s, n))
                  {
                        goodStringCount++;
                  }
            }

            cout << goodStringCount << endl;
      }
      return 0;
}