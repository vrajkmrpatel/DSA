#include <bits/stdc++.h>

using namespace std;

void printPattern(int n)
{
      for (int i = 1; i <= n; i++)
      {
            // space
            for (int j = 0; j <= (n - i); j++)
            {
                  cout << " ";
            }
            // alphabet
            char ch = 'A';
            int breakpoint = (2 * i + 1) / 2;
            for (int j = 1; j < (2 * i); j++)
            {
                  cout << ch;
                  if (j < breakpoint)
                        ch++;
                  else
                        ch--;
            }
            // space
            for (int j = 0; j < (n - i); j++)
            {
                  cout << " ";
            }
            cout << endl;
      }
}
int main()
{
      int n;
      cin >> n;

      printPattern(n);
      return 0;
}