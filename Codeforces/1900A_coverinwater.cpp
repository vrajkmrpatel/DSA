#include <bits/stdc++.h>

using namespace std;

int main()
{
      int t;
      cin >> t;

      while (t--)
      {
            int n;
            cin >> n;

            string str;
            cin >> str;
            int count = 0;

            if (str.find("...") != string::npos)
            {
                  // found
                  cout << 2 << endl;
            }
            else
            {
                  // not found
                  for (char ch : str)
                  {
                        if (ch == '#')
                        {
                              count++;
                        }
                  }
                  cout << n - count << endl;
            }
      }
      return 0;
}