#include <bits/stdc++.h>

using namespace std;

int main()
{
      vector<int> a = {1, 1, 2, 2, 3, 3, 1};
      int n = 7;
      vector<int> ans(7, 0);
      vector<int> res;
      for (int i = 0; i < n; i++)
      {
            ans[a[i]]++;
      }
      for(int i = 0; i<n; i++) {
            int temp = ans[a[i]]--;
            res.push_back(temp);
      }

      for(auto it: res) {
            cout<<it<<" ";
      }
      return 0;
}