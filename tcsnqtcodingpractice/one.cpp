#include <bits/stdc++.h>

using namespace std;

int main()
{
      int n = 10, k = 15;
      // cin>>n>>k;

      int a[n] = {5, 3, 8, 14, 18, 1, 18, 4, 8, 3};
      // for(int i = 1; i<= n; i++) {
      //       cin>> a[i];
      // }
      pair<int, int> ans;
      int l = 0, r = 0;
      int sum = 0;
      for (int i = 0; i < n; i++)
      {

            sum += a[i];
            if (sum == k)
            {
                  ans.first = l + 1;
                  ans.second = r + 1;
            }
            else if (sum > k)
            {
                  sum -= a[l];
                  l++;
            }
            else
            {
                  r++;
            }
            cout<<sum<<endl;
      }
      cout << ans.first << ans.second;
      return 0;
}