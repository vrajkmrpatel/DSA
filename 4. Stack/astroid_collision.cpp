#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

vector<int> asteroidCollision(vector<int> &asteroids)
{
      int n = asteroids.size();
      stack<int> st;
      for (int i = 0; i < n; i++)
      {
            if (asteroids[i] > 0 || st.empty())
            {
                  st.push(asteroids[i]);
            }
            else
            {
                  while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i]))
                  {
                        st.pop();
                  }

                  if (!st.empty() && st.top() == abs(asteroids[i]))
                  {
                        st.pop();
                  }
                  else if (st.empty() || st.top() < 0)
                  {
                        st.push(asteroids[i]);
                  }
            }
      }

      // stack to vector
      vector<int> res(st.size());
      for (int i = st.size() - 1; i >= 0; i--)
      {
            res[i] = st.top();
            st.pop();
      }
      return res;
}

int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      vector<int> asteroids = {5, 10, -5};
      vector<int> ans = asteroidCollision(asteroids);

      for (auto it : ans)
      {
            cout << it << " ";
      }
      return 0;
}