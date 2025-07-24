#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &list)
{
      vis[node] = 1;
      list.push_back(node);

      for (auto it : adj[node])
      {
            if (!vis[it])
            {
                  vis[it] = 1;
                  dfs(it, adj, vis, list);
            }
      }
}
int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      int n, m;
      cin >> n >> m;

      vector<vector<int>> adj(n + 1);
      for (int i = 0; i < m; i++)
      {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
      }

      int cnt = 0;
      vector<int> vis(n + 1);
      vector<int> componentSizes;

      for (int i = 1; i <= n; i++)
      {
            if (!vis[i])
            {
                  cnt++;
                  vector<int> list; // reset for each component
                  dfs(i, adj, vis, list);
                  componentSizes.push_back(list.size()); // store size
            }
      }

      // cout << "Number of components are: " << cnt << endl;

      int ans = 1;
      for (auto it : componentSizes)
      {
            ans *= it;
      }
      cout << ans * cnt << endl;

      return 0;
}