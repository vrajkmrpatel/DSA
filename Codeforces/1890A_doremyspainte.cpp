#include<bits/stdc++.h>

using namespace std;

void solve(int n, vector<int> &arr)
{
      unordered_map<int, int> mp;
      for(auto it: arr)
      {
            mp[it]++;
      }
      int unique = mp.size();
      if(n == unique)
      {
            cout << "NO" << endl;
      }
      else if(n > unique)
      {
            cout << "YES" << endl;
      }
      else {
            cout << "NO" << endl;
      }
}
int main()
{
      int t;
      cin >> t;

      while(t--)
      {
            int n;
            cin >> n;

            vector<int> arr(n);
            for(int i = 0; i<n; i++)
            {
                  cin >> arr[i];
            }

            // solution
            if(n == 2)
                  cout << "YES" << endl;
            else if(n > 2)
            {
                  solve(n, arr);
            }
      }
      return 0;
}