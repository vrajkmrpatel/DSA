#include <bits/stdc++.h>

using namespace std;

string determineWinner(int n)
{
      for (int move = 1; move <= 10; move++)
      {
            if (n % 3 != 0)
            {
                  return "First";
            }
            else
            {
                  return "Second";
            }
      }
}
int main()
{
      int t;
      cin >> t;

      while (t--)
      {
            int n;
            cin >> n;

            cout << determineWinner(n) << endl;
      }
      return 0;
}