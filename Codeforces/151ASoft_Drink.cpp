#include<bits/stdc++.h>

using namespace std;

int main()
{
      int n, k, l, c, d, p, nl, np;
      cin >> n >> k >> l >> c >> d >> p >> nl >> np;

      vector<int> ans;

      ans.push_back(k * l / nl);
      ans.push_back(c * d);
      ans.push_back(p / np);

      int min = *min_element(ans.begin(), ans.end());

      cout << min / n << endl;
      return 0;
}