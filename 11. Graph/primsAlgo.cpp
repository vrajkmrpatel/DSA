#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

// Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[])
{
      int sum = 0;
      priority_queue<pair<int, int>,
                     vector<pair<int, int>>,
                     greater<pair<int, int>>>
          pq;

      vector<int> vis(V, 0);
      pq.push({0, 0});
      // E log E
      while (!pq.empty())
      {

            // log E
            auto it = pq.top();
            pq.pop();
            int cost = it.first;
            int node = it.second;

            if (vis[node] == 1)
                  continue;
            vis[node] = 1; // this is where we add it to the MST only then we mark it as visited.
            sum += cost;

            // E log E
            for (auto edge : adj[node])
            {
                  int adjNode = edge[0];
                  int edgW = edge[1];

                  if (!vis[adjNode])
                  {
                        // do not mark it as visited here.
                        pq.push({edgW, adjNode});
                  }
            }
      }
      return sum;
}

int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);


      return 0;
}