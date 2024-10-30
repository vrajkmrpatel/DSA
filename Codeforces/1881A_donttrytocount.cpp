/* The answer is always not greater than 5.
When n = 1,m = 25, the answer is either 5 or −1, 
it is easy to see that the answer cannot be greater.
*/

#include <bits/stdc++.h>

using namespace std;

void donttrytocount(int n, string x, int m, string s)
{

      for (int i = 0; i <= 5; i++)
      {
            if (x.find(s) != string::npos)
            {
                  cout << i << endl;
                  return;
            }
            x += x;
      }

      cout << -1 << endl;
}

int main()
{
      int t;
      cin >> t;

      while (t--)
      {
            int n, m;
            cin >> n >> m;

            string x, s;
            cin >> x >> s;

            donttrytocount(n, x, m, s);
      }
      return 0;
}