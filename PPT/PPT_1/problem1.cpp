#include <bits/stdc++.h>

using namespace std;

int solve(int n)
{
      int l = 1, r = 1, cnt = 0;
      int sum = 1;
      while (l <= n / 2)
      {
            if (sum == n)
            {
                  cnt++;
                  sum -= l;
                  l++;
            }
            else if (sum < n)
            {
                  r++;
                  sum += r;
            }
            else
            {
                  sum -= l;
                  l++;
            }
      }
      return cnt;
}
int main()
{
      /* Enter your code here. Read input from STDIN. Print output to STDOUT */
      int n;
      cin >> n;

      cout << solve(n) << endl;
      return 0;
}