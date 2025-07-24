#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

vector<int> printPrimeFactor(int n)
{
      // Using Sqrt method
      vector<int> ans;
      for (int i = 2; i * i <= n; i++)
      {
            if (n % i == 0)
            {
                  ans.push_back(i);
                  while (n % i == 0)
                  {
                        n /= i;
                  }
            }
      }
      if (n != 1)
            ans.push_back(n);

      return ans;
}
int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      int num = 780;

      vector<int> ans = printPrimeFactor(num);
      for (auto it : ans)
      {
            cout << it << " ";
      }
      return 0;
}