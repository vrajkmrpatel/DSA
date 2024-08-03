#include <bits/stdc++.h>

using namespace std;

int main()
{
      int t;
      cin >> t;
      int x = 0;

      while (t--)
      {
            string st;
            cin >> st;

            string plus = "++";
            string minus = "--";
            for (int i = 0; i < st.length(); i++)
            {
                  if (st.substr(i, 2) == plus)
                  {
                        x++;
                  }
                  else if (st.substr(i, 2) == minus)
                  {
                        x--;
                  }
            }
            st.clear();
      }
      cout << x << endl;
      return 0;
}